/*************************************************************************
EnsembleFormes  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <EnsembleFormes> (fichier EnsembleFormes.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "EnsembleFormes.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

EnsembleFormes::EnsembleFormes (const EnsembleFormes & unEnsembleFormes )
{
    DicoFormeGeometrique::const_iterator i1 = unEnsembleFormes.mesFormes.cbegin();
    for(i1 ; i1!=unEnsembleFormes.mesFormes.end() ; ++i1 )
    {
        mesFormes.insert(make_pair(i1->first,i1->second->Copy()));
    }
    DicoSelection::const_iterator i2 = unEnsembleFormes.mesSelections.cbegin();
    for(i2 ; i2!=unEnsembleFormes.mesSelections.end() ; ++i2 )
    {
        mesSelections.insert(make_pair(i2->first,new Selection(*(i2->second))));
    }
#ifdef MAP
    cout << "Appel au constructeur de copie de <EnsembleFormes>" << endl;
#endif
} //----- Fin de EnsembleFormes (constructeur de copie)

EnsembleFormes::EnsembleFormes ()
{
#ifdef MAP
    cout << "Appel au constructeur de <EnsembleFormes>" << endl;
#endif
} //----- Fin du constructeur EnsembleFormes


EnsembleFormes::~EnsembleFormes ()
{
    Effacer();
#ifdef MAP
    cout << "Appel au destructeur de <EnsembleFormes>" << endl;
#endif
} //----- Fin de ~EnsembleFormes


//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes privees

void EnsembleFormes::Sauvegarder(string nomFichier)
{
    ofstream file(nomFichier.c_str());
    if(file.good())
    {
        for(DicoFormeGeometrique::iterator i=mesFormes.begin(); i!=mesFormes.end(); ++i)
        {
            file << *(i->second);
        }
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" <<endl;
    }
}

bool EnsembleFormes::Charger(string nomFichier, EnsembleFormes* ancien)
{
    bool res=true;
    if(!nomFichier.empty())
    {
        ifstream file(nomFichier.c_str());
        if(file.good())
        {
            FormeGeometrique* fg;
            string type="";
            while(getline(file, type, ' ') && res)
            {
                if( type.compare("R")==0 ) {
                    fg = new Rectangle(file);
                    mesFormes.insert(pair<string,FormeGeometrique*>(fg->GetNom(),fg));
                }else if(type.compare("C")==0){
                    //cercle
                }else if(type.compare("L")==0){
                    //LIGNE
                }else if(type.compare("PL")==0){
                    //polyligne
                }
                if(ancien->mesFormes.find(fg->GetNom())!=ancien->mesFormes.end())
                {
                    res=false;
                }
            }
        }
        else
        {
            res=false;
        }
    }
    return res;
}

vector<FormeGeometrique*> EnsembleFormes::Supprimer(string nomForme)
{
    vector<FormeGeometrique*> res;
    DicoFormeGeometrique::iterator i = (mesFormes.find(nomForme));
    if(i!=mesFormes.end()){
        FormeGeometrique* fg = (i->second);
        res.push_back(fg);
        fg->Disparaitre();
        mesFormes.erase(i);
    }else{
        DicoSelection::iterator i2 = mesSelections.find(nomForme);
        if(i2!=mesSelections.end())
        {
            Selection* s = i2->second;
            list<FormeGeometrique*> lesFormesASupprimer = s->GetFormesSelectionnees();
            for(list<FormeGeometrique*>::const_iterator ci=lesFormesASupprimer.begin() ; ci!=lesFormesASupprimer.end() ; ++ci){
                FormeGeometrique* fg = (*ci);
                res.push_back(fg);
                fg->Disparaitre();
                mesFormes.erase(fg->GetNom());
            }
            mesSelections.erase(i2);
        }
    }
    return res;
}

bool EnsembleFormes::AjouterFormeGeo (FormeGeometrique* maForme)
{
    bool res=false;
    if(mesSelections.find(maForme->GetNom()) == mesSelections.end() )
    {
        pair<DicoFormeGeometrique::iterator,bool> p = mesFormes.insert(pair<string,FormeGeometrique*>(maForme->GetNom(), maForme));
        res = p.second;
    }
    return res;
}

bool EnsembleFormes::AjouterSelection (Selection* maSelection)
{
    bool res = false;
    if(mesFormes.find(maSelection->GetNom()) == mesFormes.end())
    {
        list<FormeGeometrique*> mesFormesGeo;
        for(DicoFormeGeometrique::iterator i=mesFormes.begin() ; i!=mesFormes.end() ; ++i){
            if(i->second->FaitPartieDe(*maSelection))
            {
                mesFormesGeo.push_front(i->second);
            }
        }
        pair<DicoSelection::iterator,bool> p = mesSelections.insert(pair<string,Selection*>(maSelection->GetNom(), new Selection(maSelection->GetNom(), mesFormesGeo)));
        res = p.second;
    }
    return res;
}

bool EnsembleFormes::Deplacer(string nomForme, long dx, long dy)
{
    bool res=true;
    DicoFormeGeometrique::iterator i= mesFormes.find(nomForme);
    if(i != mesFormes.end())
    {
        i->second->Deplacer(dx, dy);
    }else{
        DicoSelection::iterator i2= mesSelections.find(nomForme);
        if(i2 != mesSelections.end())
        {
            i2->second->Deplacer(dx, dy);
        }else {
            res=false;
        }
    }
    return res;
}

void EnsembleFormes::Lister()
{
    for(DicoFormeGeometrique::iterator i=mesFormes.begin() ; i!=mesFormes.end() ; ++i){
        cout << *(i->second);
    }
}

void EnsembleFormes::Effacer()
{
    for(DicoFormeGeometrique::iterator i=mesFormes.begin() ; i!=mesFormes.end() ; ++i){
        delete i->second;
    }
    for(DicoSelection::iterator i=mesSelections.begin() ; i!=mesSelections.end() ; ++i){
        delete i->second;
    }
    mesFormes.clear();
    mesSelections.clear();


}
