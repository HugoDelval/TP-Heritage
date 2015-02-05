/*************************************************************************
CommandeAjoutFormeGeo  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- R�alisation de la classe <CommandeAjoutFormeGeo> (fichier CommandeAjoutFormeGeo.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeAjoutFormeGeo.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CommandeAjoutFormeGeo::FaireCommande()
{
    bool res = true;
    if(!done)
    {
        res=leDessin->AjouterFormeGeo(laForme);
        if(res)
        {
            done=true;
            unDone=false;
        }
    }
    return res;
}

bool CommandeAjoutFormeGeo::DefaireCommande()
{
    bool res=true;
    if(!unDone)
    {
        res=!(leDessin->Supprimer(laForme->GetNom()).first.empty());
        if(res)
        {
            done=false;
            unDone=true;
        }
    }
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
} //----- Fin du constructeur CommandeAjoutFormeGeo


CommandeAjoutFormeGeo::~CommandeAjoutFormeGeo ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <CommandeAjoutFormeGeo>" << endl;
#endif
} //----- Fin de ~CommandeAjoutFormeGeo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes privees
