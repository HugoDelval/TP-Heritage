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

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques
virtual void Rectangle::Deplacer(long dx, long dy)
{
    hautDroit.Deplacer(dx, dy);
    basGauche.Deplacer(dx, dy);
    initial1.Deplacer(dx, dy);
    initial2.Deplacer(dx, dy);
} //----- Fin de Deplacer

virtual bool Rectangle::FaitPartieDe(const Selection maSelection) const
{
    return maSelection.rectangleDeSelection.Contient(basGauche) && maSelection.rectangleDeSelection.Contient(hautDroit);
}

bool Rectangle::Contient(Point p) const
{
    return (p.x <= hautDroit.x)&&(p.x >= basGauche.y)&&(p.y <= hautDroit.y)&&(p.y >= basGauche.y);
}

//------------------------------------------------- Surcharge d'operateurs

virtual ostream &Rectangle::operator<<(ostream &os) const{
    os << nomForme+" "
       << initial1.x + " "
       << initial1.y + " "
       << initial2.x + " "
       << initial2.y;
    return os;
} //----- Fin de operator <<

virtual istream &Rectangle::operator>>(istream &is) {
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
} //----- Fin de operator >>

//-------------------------------------------- Constructeurs - destructeur

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

Rectangle::Rectangle(istream const &is)
{
    is>>(*this);
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
    initial1=Point(x1, y1);
    initial2=Point(x2, y2);
    hautDroit=Point(x1>x2?x1:x2, y1>y2?y1:y2);
    hautDroit=Point(x1<x2?x1:x2, y1<y2?y1:y2);
}
