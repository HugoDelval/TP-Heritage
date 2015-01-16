/*************************************************************************
Forme  -  description
-------------------
debut                : date
copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Realisation de la classe <Forme> (fichier Forme.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Forme.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques
//type Forme::Methode ( liste de parametres )
// Algorithme :
//
//{
//} //----- Fin de Methode


//-------------------------------------------- Constructeurs - destructeur

Forme::Forme (string nomForme )
{
    this->nomForme = nomForme;
#ifdef MAP
    cout << "Appel au constructeur de <Forme>" << endl;
#endif
} //----- Fin de Forme


Forme::~Forme ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Forme>" << endl;
#endif
} //----- Fin de ~Forme


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

