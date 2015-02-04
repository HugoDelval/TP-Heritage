/*************************************************************************
CommandeDeplacer  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeDeplacer> (fichier CommandeDeplacer.h) ------
#if ! defined ( COMMANDE_DEPLACER_H )
#define COMMANDE_DEPLACER_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "FormeGeometrique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CommandeDeplacer>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeDeplacer : public Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
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
//----------------------------------------------------- Méthodes privees
    string laForme;
    long dx;
    long dy;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres définitions dépendantes de <CommandeDeplacer>

#endif // COMMANDE_DEPLACER_H

