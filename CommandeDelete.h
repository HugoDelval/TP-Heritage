/*************************************************************************
CommandeDelete  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeDelete> (fichier CommandeDelete.h) ------
#if ! defined ( COMMANDE_DELETE_H )
#define COMMANDE_DELETE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "FormeGeometrique.h"
#include <stack>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CommandeDelete>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeDelete : public Commande
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

    CommandeDelete(EnsembleFormes* maStructure,stack<string> &lesFormes);
// Mode d'emploi :
//  cree un objet CommandeDelete et initialise ses attributs
// Contrat :
//

    virtual ~CommandeDelete ();
// Mode d'emploi :
// supprime tous les attributs de l'objet de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- M�thodes privees
    stack<string> lesFormesASupprimer;
    stack<FormeGeometrique> lesFormesASupprimer;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeDelete>

#endif // COMMANDE_DELETE_H

