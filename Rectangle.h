/*************************************************************************
Rectangle  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------

#if ! defined ( RECTANGLE_H )
#define RECTANGLE_H

//--------------------------------------------------- Interfaces utilisees
#include "Point.h"
#include "FormeGeometrique.h"
#include <string.h>
class Selection; //pour eviter l'inclusion cyclique


//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Rectangle>
//  represente une forme rectangulaire
//
//------------------------------------------------------------------------ 

class Rectangle : public FormeGeometrique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    //   deplace le Rectangle de dx en abscisse et dy en ordonne
    // Contrat :
    //  aucun

    bool FaitPartieDe(const Selection &maSelection) const;
    // Mode d'emploi :
    //   renvoie true si le Rectangle fait partie de maSelection, false sinon
    // Contrat :
    //  aucun

    bool Contient(const Point &p) const;
    // Mode d'emploi :
    //   renvoie true si le Rectangle contient le point, false sinon
    // Contrat :
    //  aucun

    virtual FormeGeometrique* Copy() const;

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Rectangle (const Rectangle &unRectangle );
    // Mode d'emploi (constructeur de copie) :
    //  copie en profondeur (pas que les pointeurs) tous les attributs de l'objet en parametre.
    // Contrat :
    //  aucun

    Rectangle ();
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    Rectangle (string nom, long x1, long y1, long x2, long y2);
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    Rectangle ( istream &is );
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    virtual ~Rectangle ( );
    // Mode d'emploi :
    //  supprime les attributs ainsi que l'instance de l'objet
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
    Point hautDroit;
    Point basGauche;
    Point initial1;
    Point initial2;

//---------------------------------------------------------- Classes amies
/*friend ostream & operator << (ostream &os, FormeGeometrique &r);
friend istream & operator >> (istream &is, FormeGeometrique &r);
*///-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Rectangle>



#endif // RECTANGLE_H
