/*************************************************************************
Rectangle  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <Rectangle> (fichier Rectangle.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

FormeGeometrique* Rectangle::Copy() const
{
    return new Rectangle(*this);
}


void Rectangle::Deplacer(long dx, long dy)
{
    hautDroit.Deplacer(dx, dy);
    basGauche.Deplacer(dx, dy);
    initial1.Deplacer(dx, dy);
    initial2.Deplacer(dx, dy);
} //----- Fin de Deplacer

bool Rectangle::FaitPartieDe(const Selection &maSelection) const
{
    return maSelection.rectangleDeSelection->Contient(basGauche) && maSelection.rectangleDeSelection->Contient(hautDroit);
}

bool Rectangle::Contient(const Point &p) const
{
    return (p.x <= hautDroit.x)&&(p.x >= basGauche.x)&&(p.y <= hautDroit.y)&&(p.y >= basGauche.y);
}

//------------------------------------------------- Surcharge d'operateurs


//-------------------------------------------- Constructeurs - destructeur

Rectangle::Rectangle(const Rectangle &unRectangle) : FormeGeometrique(unRectangle)
{
    hautDroit.x = unRectangle.hautDroit.x;
    hautDroit.y = unRectangle.hautDroit.y;
    basGauche.x = unRectangle.basGauche.x;
    basGauche.y = unRectangle.basGauche.y;
    initial1.x = unRectangle.initial1.x;
    initial1.y = unRectangle.initial1.y;
    initial2.x = unRectangle.initial2.x;
    initial2.y = unRectangle.initial2.y;
}

Rectangle::Rectangle (): FormeGeometrique()
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::Rectangle(string nom, long x1, long y1, long x2, long y2) : FormeGeometrique(nom)
{
    initialiser(x1,y1,x2,y2);
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle

Rectangle::Rectangle(istream &is)
{
    is >> (*this);
}//----- Fin de Rectangle

Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

void Rectangle::initialiser(long x1, long y1, long x2, long y2) {
    initial1.x=x1;
    initial1.y=y1;
    initial2.x=x2;
    initial2.y=y2;
    hautDroit.x=x1>x2?x1:x2;
    hautDroit.y=y1>y2?y1:y2;
    basGauche.x=x1<x2?x1:x2;
    basGauche.y=y1<y2?y1:y2;
}

istream& Rectangle::fluxRentrant(istream &is)
{
    string x1="";
    string x2="";
    string y1="";
    string y2="";

    //getline(is,nomForme,' '); // pour le 'R'
    getline(is,nomForme,' ');
    getline(is,x1,' ');
    getline(is,y1,' ');
    getline(is,x2,' ');
    getline(is,y2);

    initialiser((long)(atoi(x1.c_str())), (long)(atoi(y1.c_str())), (long)(atoi(x2.c_str())), (long)(atoi(y2.c_str())));
    return is;
}

ostream& Rectangle::fluxSortant(ostream &os)
{
    os << nomForme+" "
       << initial1.x << " "
       << initial1.y << " "
       << initial2.x << " "
       << initial2.y
       << endl;
    return os;
}


