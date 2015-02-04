/*************************************************************************
CommandeDeplacer  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeDeplacer> (fichier CommandeDeplacer.h) ------
#if ! defined ( COMMANDE_DEPLACER_H )
#define COMMANDE_DEPLACER_H

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "FormeGeometrique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CommandeDeplacer>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeDeplacer : public Commande
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

    CommandeDeplacer (EnsembleFormes* maStructure,string laFormeADeplacer, long dx, long dy);
// Mode d'emploi :
//  cree un objet CommandeDeplacer et initialise ses attributs
// Contrat :
//

    virtual ~CommandeDeplacer ();
// Mode d'emploi :
// supprime tous les attributs de l'objet de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- M�thodes privees
    string laForme;
    long dx;
    long dy;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeDeplacer>

#endif // COMMANDE_DEPLACER_H

