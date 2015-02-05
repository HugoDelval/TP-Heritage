/*************************************************************************
Polyligne  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <Polyligne> (fichier Polyligne.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <vector>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

FormeGeometrique* Polyligne::Copy() const
{
    return new Polyligne(*this);
} //----- Fin de Copy

void Polyligne::Deplacer(long dx, long dy)
{
    for (int i = 0; i < ensemblePoints.size(); i++)
    {
        ensemblePoints[i].x += dx;
        ensemblePoints[i].y += dy;
    }
} //----- Fin de Deplacer

bool Polyligne::FaitPartieDe(const Selection &maSelection) const
{
    bool presence = true;
    for (int i = 0; i < ensemblePoints.size() && presence; i++)
    {
        if (!maSelection.rectangleDeSelection->Contient(ensemblePoints[i]))
        {
            presence = false;
        }
    }
    return presence;
} //----- Fin de FaitPartieDe

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur

Polyligne::Polyligne(const Polyligne &unPolyligne) : FormeGeometrique(unPolyligne)
{
    ensemblePoints=unPolyligne.ensemblePoints;
}

Polyligne::Polyligne (): FormeGeometrique()
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne


Polyligne::Polyligne(string nom, vector<long> coordonnees) : FormeGeometrique(nom)
{
    // Initialiser tous les points de l'objet
    initialiser(coordonnees);
#ifdef MAP
    cout << "Appel au constructeur de <Polyligne>" << endl;
#endif
} //----- Fin de Polyligne

Polyligne::Polyligne(istream &is)
{
    is >> (*this);
}//----- Fin de Polyligne

Polyligne::~Polyligne ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyligne>" << endl;
#endif
} //----- Fin de ~Polyligne


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

void Polyligne::initialiser(vector<long> coordonnees)
{
    for (int i = 0; i < coordonnees.size(); i+=2)
    {
        Point p(coordonnees[i],coordonnees[i+1]);
        ensemblePoints.push_back(p);
    }
}

istream& Polyligne::fluxRentrant(istream &is)
{
    vector<string> points;

    getline(is,nomForme,' ');

    // Pour tous les points de l'attribut p, faire un getline
    //getline(is,x1,' ');

    // Puis appeler la fonction initialiser
    //initialiser((long)(atoi(x1.c_str())), (long)(atoi(y1.c_str())), (long)(atoi(x2.c_str())), (long)(atoi(y2.c_str())));
    return is;
}

ostream& Polyligne::fluxSortant(ostream &os)
{
    os << "PL "
       << nomForme+" ";
    for (int i = 0; i < ensemblePoints.size(); i++)
    {
        os << ensemblePoints[i].x << " "
                << ensemblePoints[i].y << " ";
    }
    os << endl;
    return os;
}
