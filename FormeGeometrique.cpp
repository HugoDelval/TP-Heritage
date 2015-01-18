/*************************************************************************
FormeGeometrique  -  description
-------------------
debut                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <FormeGeometrique> (fichier FormeGeometrique.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "FormeGeometrique.h"
#include "Selection.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques

void FormeGeometrique::Disparaitre()
{
    for(list<Selection*>::iterator i=parQuiSuisJeSelectionne.begin(); i!=parQuiSuisJeSelectionne.end() ; i++){
        (*i)->Retirer(nomForme);
    }
}//----- Fin de Disparaitre

//------------------------------------------------- Surcharge d'operateurs


//-------------------------------------------- Constructeurs - destructeur

FormeGeometrique::FormeGeometrique () : Forme()
{
#ifdef MAP
    cout << "Appel au constructeur de <FormeGeometrique>" << endl;
#endif
} //----- Fin de FormeGeometrique

FormeGeometrique::FormeGeometrique (string nomForme) : Forme(nomForme)
{
#ifdef MAP
    cout << "Appel au constructeur de <FormeGeometrique>" << endl;
#endif
} //----- Fin de FormeGeometrique


FormeGeometrique::~FormeGeometrique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FormeGeometrique>" << endl;
#endif
} //----- Fin de ~FormeGeometrique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

ostream &operator<<(ostream &os, FormeGeometrique &r) {
    return r.fluxSortant(os);
}

istream &operator>>(istream &is, FormeGeometrique &r) {
    return r.fluxRentrant(is);
}
