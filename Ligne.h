
/*************************************************************************
Ligne  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------

#if ! defined ( LIGNE_H )
#define LIGNE_H

//--------------------------------------------------- Interfaces utilisees
#include "Point.h"
#include "FormeGeometrique.h"
#include <string.h>
class Selection;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Ligne>
//  La classe Ligne represente une forme lineaire composee principalement
//  de deux points de coordonnees (abscisse et ordonnee).
//
//------------------------------------------------------------------------

class Ligne : public FormeGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    //   Deplace le Ligne de dx en abscisse et dy en ordonne.
    // Contrat :
    //  aucun

    bool FaitPartieDe(const Selection &maSelection) const;
    // Mode d'emploi :
    //   Renvoie true si le Ligne fait partie de maSelection, false sinon.
    // Contrat :
    //  aucun

    virtual FormeGeometrique* Copy() const;

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Ligne (const Ligne &unLigne );
    // Mode d'emploi (constructeur de copie) :
    //  Copie en profondeur (pas que les pointeurs) de tous les attributs de
    //  l'objet en parametre.
    // Contrat :
    //  aucun

    Ligne ();
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Ligne (string nom, long x1, long y1, long x2, long y2);
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Ligne ( istream &is );
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    virtual ~Ligne ( );
    // Mode d'emploi :
    //  Supprime les attributs ainsi que l'instance de l'objet.
    // Contrat :
    //  aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees
    virtual istream& fluxRentrant(istream &is);
    virtual ostream& fluxSortant(ostream &os);

private:
//------------------------------------------------------- Methodes privees
    void initialiser(long x1, long y1, long x2, long y2);
protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    Point p1;
    Point p2;

//---------------------------------------------------------- Classes amies
/*friend ostream & operator << (ostream &os, FormeGeometrique &r);
friend istream & operator >> (istream &is, FormeGeometrique &r);
*///-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Ligne>

#endif // LIGNE_H
