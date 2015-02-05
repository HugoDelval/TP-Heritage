
/*************************************************************************
Ligne  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <Ligne> (fichier Ligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Ligne.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

FormeGeometrique* Ligne::Copy() const
{
    return new Ligne(*this);
} //----- Fin de Copy

void Ligne::Deplacer(long dx, long dy)
{
    p1.Deplacer(dx, dy);
    p2.Deplacer(dx, dy);
} //----- Fin de Deplacer

bool Ligne::FaitPartieDe(const Selection &maSelection) const
{
    return (maSelection.rectangleDeSelection->Contient(p1) &&
            maSelection.rectangleDeSelection->Contient(p2));
} //----- Fin de FaitPartieDe

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur

Ligne::Ligne(const Ligne &unLigne) : FormeGeometrique(unLigne)
{
    p1.x = unLigne.p1.x;
    p1.y = unLigne.p1.y;
    p2.x = unLigne.p2.x;
    p2.y = unLigne.p2.y;
}

Ligne::Ligne (): FormeGeometrique()
{
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne


Ligne::Ligne(string nom, long x1, long y1, long x2, long y2) : FormeGeometrique(nom)
{
    initialiser(x1, y1, x2, y2);
#ifdef MAP
    cout << "Appel au constructeur de <Ligne>" << endl;
#endif
} //----- Fin de Ligne

Ligne::Ligne(istream &is)
{
    is >> (*this);
}//----- Fin de Ligne

Ligne::~Ligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ligne>" << endl;
#endif
} //----- Fin de ~Ligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

void Ligne::initialiser(long x1, long y1, long x2, long y2)
{
    p1.x = x1;
    p1.y = y1;
    p2.x = x2;
    p2.y = y2;
}

istream& Ligne::fluxRentrant(istream &is)
{
    string x1="";
    string y1="";
    string x2="";
    string y2="";

    getline(is,nomForme,' ');
    getline(is,x1,' ');
    getline(is,y1,' ');
    getline(is,x2,' ');
    getline(is,y2,' ');

    initialiser((long)(atoi(x1.c_str())), (long)(atoi(y1.c_str())), (long)(atoi(x2.c_str())), (long)(atoi(y2.c_str())));
    return is;
}

ostream& Ligne::fluxSortant(ostream &os)
{
    os << "L "
            << nomForme+" "
            << p1.x << " "
            << p1.y << " "
            << p2.x << " "
            << p2.y
            << endl;
    return os;
}
