/*************************************************************************
CommandeLoad  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <CommandeLoad> (fichier CommandeLoad.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeLoad.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool CommandeLoad::FaireCommande()
{
    if(!done)
    {
        if(!charge)
        {
            nouvelleStruct=new EnsembleFormes();
            charge=nouvelleStruct->Charger(nomFichier,leDessin); // renvoie false si un nom est en commun
        }
        if(charge)
        {
            for(EnsembleFormes::DicoFormeGeometrique::iterator i = nouvelleStruct->mesFormes.begin() ; i!=nouvelleStruct->mesFormes.end() ; i++)
            {
                done=leDessin->AjouterFormeGeo(i->second);
            }
            done=true;
            unDone=false;
        }
    }
    return charge;
}

bool CommandeLoad::DefaireCommande()
{
    if(!unDone)
    {
        for(EnsembleFormes::DicoFormeGeometrique::iterator i = nouvelleStruct->mesFormes.begin(); i!=nouvelleStruct->mesFormes.end()  ; i++)
        {
            leDessin->Supprimer(i->first);
        }
        done=false;
        unDone=true;
    }
    return true;
}

//-------------------------------------------- Constructeurs - destructeur

CommandeLoad::CommandeLoad(EnsembleFormes* maStructure,string fileName)
{
    leDessin=maStructure;
    structureSauv = leDessin->mesFormes;
    nomFichier=fileName;
    done=false;
    unDone=false;
    charge=false;
#ifdef MAP
    cout << "Appel au constructeur de <CommandeLoad>" << endl;
#endif
} //----- Fin du constructeur CommandeLoad


CommandeLoad::~CommandeLoad ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <CommandeLoad>" << endl;
#endif
} //----- Fin de ~CommandeLoad


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privees
