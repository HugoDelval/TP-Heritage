/*************************************************************************
CommandeRectangle  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <CommandeRectangle> (fichier CommandeRectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeAjoutFormeGeo.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool CommandeAjoutFormeGeo::FaireCommande()
{
    bool res = false;
    if(!done)
    {
        res=leDessin->AjouterFormeGeo(laForme);
        done=true;
        unDone=false;
    }
    return res;
}

bool CommandeAjoutFormeGeo::DefaireCommande()
{
    bool res=false;
    if(!unDone)
    {
        res=leDessin->Supprimer(laForme->GetNom());
        done=false;
        unDone=true;
    }
    cout<<done<<endl;
    return res;
}

//-------------------------------------------- Constructeurs - destructeur

CommandeAjoutFormeGeo::CommandeAjoutFormeGeo (EnsembleFormes* maStructure,FormeGeometrique* laFormeAAjouter)
{
    leDessin=maStructure;
    laForme=laFormeAAjouter;
    done=false;
    unDone=false;
#ifdef MAP
    cout << "Appel au constructeur de <CommandeAjoutFormeGeo>" << endl;
#endif
} //----- Fin du constructeur CommandeRectangle


CommandeAjoutFormeGeo::~CommandeAjoutFormeGeo ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <CommandeAjoutFormeGeo>" << endl;
#endif
} //----- Fin de ~CommandeRectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privees
