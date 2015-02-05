/*************************************************************************
CommandeDelete  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <CommandeDelete> (fichier CommandeDelete.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeDelete.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool CommandeDelete::FaireCommande()
{
    bool res=true;
    if(!done)
    {
        for(list<string>::iterator i=lesFormesASupprimer.begin();i!=lesFormesASupprimer.end();i++)
        {
            pair<vector<FormeGeometrique*>,bool> v=leDessin->Supprimer(*i);
            if(res)
            {
                res=v.second || !(v.first.empty()); // vrai si il y a des formes supprimees ou si c'est une selection vide
            }
            if(!charge)
                lesFormesSauv.insert (lesFormesSauv.begin(),v.first.begin(),v.first.end());
        }
        done=true;
        unDone=false;
        charge=true;
    }
    return res;
}

bool CommandeDelete::DefaireCommande()
{
    bool res=true;
    if(!unDone)
    {
        for(list<FormeGeometrique*>::iterator i=lesFormesSauv.begin();i!=lesFormesSauv.end() && res;i++)
        {
            res=leDessin->AjouterFormeGeo(*i);
        }
        done=false;
        unDone=true;
    }
    return res;
}

//-------------------------------------------- Constructeurs - destructeur

CommandeDelete::CommandeDelete (EnsembleFormes* maStructure) // pour le clear
{
    leDessin=maStructure;
    for(EnsembleFormes::DicoFormeGeometrique::iterator i=maStructure->mesFormes.begin() ; i!=maStructure->mesFormes.end() ; i++)
    {
        lesFormesASupprimer.push_back(i->first);
    }
    done=false;
    unDone=false;
    charge=false;
#ifdef MAP
    cout << "Appel au constructeur de <CommandeDelete>" << endl;
#endif
} //----- Fin du constructeur CommandeDelete

CommandeDelete::CommandeDelete (EnsembleFormes* maStructure,list<string> &lesFormes)
{
    leDessin=maStructure;
    lesFormesASupprimer=lesFormes;
    done=false;
    unDone=false;
    charge=false;
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

//----------------------------------------------------- Méthodes privees
