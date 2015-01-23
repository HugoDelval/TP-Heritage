/*************************************************************************
EnsembleFormes  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- R�alisation de la classe <EnsembleFormes> (fichier EnsembleFormes.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "EnsembleFormes.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques


//-------------------------------------------- Constructeurs - destructeur

EnsembleFormes::EnsembleFormes ( EnsembleFormes & unEnsembleFormes )
{
    DicoFormeGeometrique::iterator i1 = unEnsembleFormes.mesFormes.begin();
    for(i1 ; i1!=unEnsembleFormes.mesFormes.end() ; ++i1 )
    {
        mesFormes.insert(make_pair(i1->first,i1->second->Copy()));
    }
    DicoSelection::iterator i2 = unEnsembleFormes.mesSelections.begin();
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


//----------------------------------------------------- M�thodes privees

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

void EnsembleFormes::Charger(string nomFichier)
{
    ifstream file(nomFichier.c_str());

    if(file.good())
    {
        FormeGeometrique* fg;
        string type="";
        while(getline(file, type, ' '))
        {
            if( type.compare("R")==0 ) {
                fg = new Rectangle(file);
                mesFormes.insert(pair<string,FormeGeometrique*>(fg->GetNom(),fg));
                cout << "OK" << endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }
    }
    else
    {
        cout << "ERR" <<endl;
    }


}

void EnsembleFormes::Supprimer(string nomForme, bool estUneFormeGeo)
{
    if(estUneFormeGeo){
        FormeGeometrique* fg = (mesFormes.find(nomForme)->second);
        fg->Disparaitre();
        mesFormes.erase(nomForme);
        delete fg;
    }else{
        Selection* s = mesSelections.find(nomForme)->second;
        list<FormeGeometrique*> lesFormesASupprimer = s->GetFormesSelectionnees();
        for(list<FormeGeometrique*>::const_iterator ci=lesFormesASupprimer.begin() ; ci!=lesFormesASupprimer.end() ; ++ci){
            FormeGeometrique* fg = (*ci);
            fg->Disparaitre();
            mesFormes.erase(fg->GetNom());
            delete fg;
        }
        mesSelections.erase(nomForme);
        delete s;
    }


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

void EnsembleFormes::Deplacer(string nomForme, long dx, long dy)
{
    if(mesFormes.find(nomForme) != mesFormes.end()){
        FormeGeometrique* fg = mesFormes.find(nomForme)->second;
        fg->Deplacer(dx, dy);
    }else{
        Selection* s = mesSelections.find(nomForme)->second;
        s->Deplacer(dx, dy);
    }
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
