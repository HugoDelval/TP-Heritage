/*************************************************************************
CommandeAjoutFormeGeo  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeAjoutFormeGeo> (fichier CommandeAjoutFormeGeo.h) ------
#if ! defined ( COMMANDE_AJOUT_FORME_GEO_H )
#define COMMANDE_AJOUT_FORME_GEO_H

//--------------------------------------------------- Interfaces utilis�es
#include "Commande.h"
#include "FormeGeometrique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <CommandeAjoutFormeGeo>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeAjoutFormeGeo : public Commande
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

    CommandeAjoutFormeGeo (EnsembleFormes* maStructure,FormeGeometrique* laFormeAAjouter);
// Mode d'emploi :
//  cree un objet CommandeAjoutFormeGeo et initialise ses attributs
// Contrat :
//

    virtual ~CommandeAjoutFormeGeo ();
// Mode d'emploi :
// supprime tous les attributs de l'objet de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- M�thodes privees
    FormeGeometrique* laForme;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres d�finitions d�pendantes de <CommandeAjoutFormeGeo>

#endif // COMMANDE_AJOUT_FORME_GEO_H

