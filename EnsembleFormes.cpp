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
        for(list<FormeGeometrique*>::const_iterator ci=lesFormesASupprimer.begin() ; ci!=lesFormesASupprimer.end() ; ci++){
            FormeGeometrique* fg = (*ci);
            fg->Disparaitre();
            mesFormes.erase(fg->GetNom());
            delete fg;
        }
        mesSelections.erase(nomForme);
        delete s;
    }
}

void EnsembleFormes::AjouterFormeGeo (FormeGeometrique &maForme)
{
    mesFormes.insert(pair<string,FormeGeometrique*>(maForme.GetNom(), &maForme));
}

void EnsembleFormes::AjouterSelection (Selection &maSelection)
{
    list<FormeGeometrique*> mesFormesGeo;
    for(DicoFormeGeometrique::iterator i=mesFormes.begin() ; i!=mesFormes.end() ; i++){
        if(i->second->FaitPartieDe(maSelection))
            mesFormesGeo.push_front(i->second);
    }
    mesSelections.insert(pair<string,Selection*>(maSelection.GetNom(), new Selection(maSelection.GetNom(), mesFormesGeo)));
}

void EnsembleFormes::Deplacer(string nomForme, long dx, long dy, bool estUneFormeGeo)
{
    if(estUneFormeGeo){
        FormeGeometrique* fg = mesFormes.find(nomForme)->second;
        fg->Deplacer(dx, dy);
    }else{
        Selection* s = mesSelections.find(nomForme)->second;
        s->Deplacer(dx, dy);
    }
}

void EnsembleFormes::Lister() const
{
    for(DicoFormeGeometrique::const_iterator ci=mesFormes.begin() ; ci!=mesFormes.end() ; ci++){
        cout << ci->second;
    }
}

void EnsembleFormes::Effacer()
{
    for(DicoFormeGeometrique::iterator i=mesFormes.begin() ; i!=mesFormes.end() ; i++){
        delete i->second;
    }
    for(DicoSelection::iterator i=mesSelections.begin() ; i!=mesSelections.end() ; i++){
        delete i->second;
    }
    mesFormes.clear();
    mesSelections.clear();
}
