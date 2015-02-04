/*************************************************************************
Point  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#include "FormeGeometrique.h"

#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    void Deplacer ( long dx, long dy );
    // Mode d'emploi :
    //   deplace le point de dx en abscisse et dy en ordonnee
    // Contrat :
    //  aucun



//-------------------------------------------- Constructeurs - destructeur

    Point ();
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    Point (long x, long y);
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    virtual ~Point ( );
    // Mode d'emploi :
    //  supprime les attributs ainsi que l'instance de l'objet
    // Contrat :
    //  aucun

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    long x;
    long y;

//---------------------------------------------------------- Classes amies
friend class Rectangle;
friend class Cercle;
//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Point>

#endif // POINT_H
