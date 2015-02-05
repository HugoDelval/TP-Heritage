
/*************************************************************************
Polyligne  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) ------

#if ! defined ( POLYLIGNE_H )
#define POLYLIGNE_H

//--------------------------------------------------- Interfaces utilisees
#include "Point.h"
#include "FormeGeometrique.h"
#include <string.h>
#include <vector>

class Selection;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <Polyligne>
//  La classe Polyligne represente une suite de formes lineaires composees
//  principalement d'une suite deux points de coordonnees (abscisse et
//  ordonnee).
//
//------------------------------------------------------------------------

class Polyligne : public FormeGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    //   Deplace la Polyligne de dx en abscisse et dy en ordonne.
    // Contrat :
    //  aucun

    bool FaitPartieDe(const Selection &maSelection) const;
    // Mode d'emploi :
    //   Renvoie true si la Polyligne fait partie de maSelection, false sinon.
    // Contrat :
    //  aucun

    virtual FormeGeometrique* Copy() const;

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Polyligne (const Polyligne &unPolyligne );
    // Mode d'emploi (constructeur de copie) :
    //  Copie en profondeur (pas que les pointeurs) de tous les attributs de
    //  l'objet en parametre.
    // Contrat :
    //  aucun

    Polyligne ();
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Polyligne (string nom, vector<long> coordonnees);
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    Polyligne ( istream &is );
    // Mode d'emploi :
    //  Initialise les attributs, et cree l'instance de l'objet.
    // Contrat :
    //  aucun

    virtual ~Polyligne ( );
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
    void initialiser(vector<long> coordonnees);
protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    vector<Point> ensemblePoints;

//---------------------------------------------------------- Classes amies
/*friend ostream & operator << (ostream &os, FormeGeometrique &r);
friend istream & operator >> (istream &is, FormeGeometrique &r);
*///-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Polyligne>

#endif // POLYLIGNE_H
