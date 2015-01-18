/*************************************************************************
FormeGeometrique  -  description
-------------------
debut                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <FormeGeometrique> (fichier FormeGeometrique.h) ------
#if ! defined ( FORME_GEOMETRIQUE_H )
#define FORME_GEOMETRIQUE_H

//--------------------------------------------------- Interfaces utilisees
#include <list>
#include <string.h>
#include "Forme.h"
class Selection;
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <FormeGeometrique>
//  represente une forme geometrique, gere l'interaction avec les selections
//
//------------------------------------------------------------------------ 

class FormeGeometrique : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer (long dx, long dy) = 0;
    // Mode d'emploi :
    //   deplace la forme de dx en abscisse et dy en ordonne
    // Contrat :
    //  aucun

    virtual bool FaitPartieDe (const Selection &maSelection) const = 0;
    // Mode d'emploi :
    //   renvoie true si la Forme fait partie de maSelection, false sinon
    // Contrat :
    //  aucun



//------------------------------------------------- Surcharge d'operateurs

    void Disparaitre();
    // Mode d'emploi :
    //  retire des selections ou la forme geometrique (this) est presente
    // Contrat :
    //  aucun


//-------------------------------------------- Constructeurs - destructeur

    FormeGeometrique ();
    // Mode d'emploi :
    //  initialise les attributs de la classe
    // Contrat :
    //  aucun

    FormeGeometrique (string nomForme);
    // Mode d'emploi :
    //  initialise les attributs de la classe
    // Contrat :
    //  aucun

    virtual ~FormeGeometrique ( );
    // Mode d'emploi :
    //  supprime proprement les attributs de la classe
    // Contrat :
    //  aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees
    virtual istream& fluxRentrant(istream &is)=0;
    virtual ostream& fluxSortant(ostream &os)=0;

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges
list<Selection*> parQuiSuisJeSelectionne;

//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies
friend ostream & operator << (ostream &os, FormeGeometrique &r);
friend istream & operator >> (istream &is, FormeGeometrique &r);
//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <FormeGeometrique>

ostream & operator << (ostream &os, FormeGeometrique &r);
// Mode d'emploi :
//  affiche la Forme dans le flux os
// Contrat :
//  aucun

istream & operator >> (istream &is, FormeGeometrique &r);
// Mode d'emploi :
//  recupere la Forme dans le flux is
// Contrat :
//  aucun

#endif // FORME_GEOMETRIQUE_H
