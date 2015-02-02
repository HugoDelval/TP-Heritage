/*************************************************************************
CommandeAjoutFormeGeo  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <CommandeAjoutFormeGeo> (fichier CommandeAjoutFormeGeo.h) ------
#if ! defined ( COMMANDE_AJOUT_FORME_GEO_H )
#define COMMANDE_AJOUT_FORME_GEO_H

//--------------------------------------------------- Interfaces utilisées
#include "Commande.h"
#include "FormeGeometrique.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <CommandeAjoutFormeGeo>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class CommandeAjoutFormeGeo : public Commande
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
//----------------------------------------------------- Méthodes privees
    FormeGeometrique* laForme;

protected:
//----------------------------------------------------- Attributs proteges

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres définitions dépendantes de <CommandeAjoutFormeGeo>

#endif // COMMANDE_AJOUT_FORME_GEO_H

