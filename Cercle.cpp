
/*************************************************************************
Cercle  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <Cercle> (fichier Cercle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Cercle.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

FormeGeometrique* Cercle::Copy() const
{
    return new Cercle(*this);
} //----- Fin de Copy

void Cercle::Deplacer(long dx, long dy)
{
    centre.Deplacer(dx, dy);
} //----- Fin de Deplacer

bool Cercle::FaitPartieDe(const Selection &maSelection) const
{
    Point maxHaut = Point(centre.x, (centre.y + rayon));
    Point maxBas = Point(centre.x, (centre.y - rayon));
    Point maxGauche = Point((centre.x - rayon), centre.y);
    Point maxDroit = Point((centre.x + rayon), centre.y);

    return (maSelection.rectangleDeSelection->Contient(maxHaut) &&
            maSelection.rectangleDeSelection->Contient(maxBas) &&
            maSelection.rectangleDeSelection->Contient(maxGauche)&&
            maSelection.rectangleDeSelection->Contient(maxDroit));
} //----- Fin de FaitPartieDe

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur

Cercle::Cercle(const Cercle &unCercle) : FormeGeometrique(unCercle)
{
    centre.x = unCercle.centre.x;
    centre.y = unCercle.centre.y;
    rayon = unCercle.rayon;
}

Cercle::Cercle (): FormeGeometrique()
{
#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle


Cercle::Cercle(string nom, long x1, long y1, long pRayon) : FormeGeometrique(nom)
{
    initialiser(x1, y1, pRayon);
#ifdef MAP
    cout << "Appel au constructeur de <Cercle>" << endl;
#endif
} //----- Fin de Cercle

Cercle::Cercle(istream &is)
{
    is >> (*this);
}//----- Fin de Cercle

Cercle::~Cercle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cercle>" << endl;
#endif
} //----- Fin de ~Cercle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

void Cercle::initialiser(long x1, long y1, long pRayon) {
    centre.x = x1;
    centre.y = y1;
    rayon = pRayon;
}

istream& Cercle::fluxRentrant(istream &is)
{
    string x1="";
    string y1="";
    string pRayon="";

    //getline(is,nomForme,' '); // pour le 'R'
    getline(is,nomForme,' ');
    getline(is,x1,' ');
    getline(is,y1,' ');
    getline(is,pRayon);

    initialiser((long)(atoi(x1.c_str())), (long)(atoi(y1.c_str())), (long)(atoi(pRayon.c_str())));
    return is;
}

ostream& Cercle::fluxSortant(ostream &os)
{
    os << "C "
       << nomForme+" "
            << centre.x << " "
            << centre.y << " "
            << rayon
            << endl;
    return os;
}


