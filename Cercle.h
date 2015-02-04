
/*************************************************************************
Cercle  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------

#if ! defined ( CERCLE_H )
#define CERCLE_H

//--------------------------------------------------- Interfaces utilisees
#include "Point.h"
#include "FormeGeometrique.h"
#include <string.h>
class Selection; //pour eviter l'inclusion cyclique

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Cercle>
//  La classe Cercle represente une forme circulaire composee principalement
//  d'un point de deux coordonnees (abscisse et ordonnee) et d'un rayon.
//
//------------------------------------------------------------------------

class Cercle : public FormeGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    //   Deplace le Cercle de dx en abscisse et dy en ordonne.
    // Contrat :
    //  aucun

    bool FaitPartieDe(const Selection &maSelection) const;
    // Mode d'emploi :
    //   Renvoie true si le Cercle fait partie de maSelection, false sinon.
    // Contrat :
    //  aucun

    virtual FormeGeometrique* Copy() const;

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Cercle (const Cercle &unCercle );
    // Mode d'emploi (constructeur de copie) :
    //  Copie en profondeur (pas que les pointeurs) de tous les attributs de
    //  l'objet en parametre.
    // Contrat :
    //  aucun

    Cercle ();
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Cercle (string nom, long x1, long y1, long pRayon);
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Cercle ( istream &is );
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    virtual ~Cercle ( );
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
    void initialiser(long x1, long y1, long pRayon);
protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    Point centre;
    long rayon;

//---------------------------------------------------------- Classes amies
/*friend ostream & operator << (ostream &os, FormeGeometrique &r);
friend istream & operator >> (istream &is, FormeGeometrique &r);
*///-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Cercle>

#endif // CERCLE_H
