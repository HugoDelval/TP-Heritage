/*************************************************************************
Commande  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ------
#if ! defined ( COMMANDE_H )
#define COMMANDE_H

//--------------------------------------------------- Interfaces utilis�es
#include "EnsembleFormes.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Commande>
//  Permet de gerer les undo et redo.
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    virtual bool FaireCommande()=0;
    // Mode d'emploi :
    //  lance la commande
    // Contrat :
    // aucun

    virtual bool DefaireCommande()=0;
    // Mode d'emploi :
    //  lance la commande inverse
    // Contrat :
    // aucun

//-------------------------------------------- Constructeurs - destructeur

    //Commande ();
// Mode d'emploi :
//  cree un objet Commande et initialise ses attributs
// Contrat :
//

//    virtual ~Commande ();
// Mode d'emploi :
// supprime tous les attributs de l'objet de la memoire
// Contrat :
// aucun

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- M�thodes privees

protected:
//----------------------------------------------------- Attributs proteges
    bool done;
    bool unDone;
    EnsembleFormes* leDessin;

//----------------------------------------------------- Attributs prives

};

//--------------------------- Autres d�finitions d�pendantes de <Commande>

#endif // COMMANDE_H

