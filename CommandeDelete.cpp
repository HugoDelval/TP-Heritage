/*************************************************************************
CommandeDelete  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- R�alisation de la classe <CommandeDelete> (fichier CommandeDelete.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeDelete.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CommandeDelete::FaireCommande()
{
    bool res = false;
    if(!done)
    {
        res=true;
        for(int i=0;i<lesFormesASupprimer.size() && res;i++)
        {
            res=leDessin->Supprimer(lesFormesASupprimer[i]);
        }
        done=true;
        unDone=false;
    }
    return res;
}

bool CommandeDelete::DefaireCommande()
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

CommandeDelete::CommandeDelete (EnsembleFormes* maStructure,stack<string> &lesFormes)
{
    leDessin=maStructure;
    lesFormesASupprimer=lesFormes;
    done=false;
    unDone=false;
#ifdef MAP
    cout << "Appel au constructeur de <CommandeDelete>" << endl;
#endif
} //----- Fin du constructeur CommandeDelete


CommandeDelete::~CommandeDelete ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <CommandeDelete>" << endl;
#endif
} //----- Fin de ~CommandeDelete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes privees
