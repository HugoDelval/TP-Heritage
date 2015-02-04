/*************************************************************************
CommandeLoad  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeLoad> (fichier CommandeLoad.h) ------
#if ! defined ( COMMANDE_LOAD_H )
#define COMMANDE_LOAD_H

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "FormeGeometrique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CommandeLoad>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeLoad : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual bool FaireCommande();
    // Mode d'emploi :
    //  lance la commande
    // Contrat :
    // aucun

    virtual bool DefaireCommande();
    // Mode d'emploi :
    //  lance la commande inverse
    // Contrat :
    // aucun

//-------------------------------------------- Constructeurs - destructeur

    CommandeLoad (EnsembleFormes* maStructure,string fileName="");
// Mode d'emploi :
//  cree un objet CommandeLoad et initialise ses attributs
// Contrat :
//

    virtual ~CommandeLoad ();
// Mode d'emploi :
// supprime tous les attributs de l'objet de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- M�thodes privees
    string nomFichier;
    EnsembleFormes::DicoFormeGeometrique structureSauv;
    EnsembleFormes* nouvelleStruct;
    bool charge;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeLoad>

#endif // COMMANDE_LOAD_H

