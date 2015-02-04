/*************************************************************************
Application  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application.h) ------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "EnsembleFormes.h"
#include "Commande.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Application>
//  gere les commandes utilisateur et modifie son EnsembleFormes en consequences.
//------------------------------------------------------------------------ 

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void LancerApplication ();
    // Mode d'emploi :
    //  lance la lecture des commandes utilisateurs
    // Contrat :
    // aucun


//-------------------------------------------- Constructeurs - destructeur

Application ( );
// Mode d'emploi :
//  cree un objet Application et initialise ses attributs
// Contrat :
//

virtual ~Application ( );
// Mode d'emploi :
// supprime tous les attributs de la classe de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE 

private:
//----------------------------------------------------- Méthodes privees

    bool undo ();
    // Mode d'emploi :
    //  recule d'un etat dans la liste des etats, si c'est possible
    // Contrat :
    //  aucun

    bool redo ();
    // Mode d'emploi :
    //  avance d'un etat dans la liste des etats, si c'est possible
    // Contrat :
    //  aucun

    void eraseAllFrom(list<Commande*>::iterator debut);
    // Mode d'emploi :
    //  supprime tout depuis 'debut' jusqu'à la fin de la liste
    // Contrat :
    //  aucun

    vector<string> string_split(const string &s, const char delimiter);
    // Mode d'emploi :
    //  split a string
    // Contrat :
    //  aucun

//----------------------------------------------------- Attributs prives
    EnsembleFormes* maStructure;
    list<Commande*>::iterator etatCourant;
    list<Commande*> listeEtats;

};

//--------------------------- Autres définitions dépendantes de <Application>

#endif // APPLICATION_H

