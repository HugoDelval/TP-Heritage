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

//void FormeGeometrique::Deplacer(long dx, long dy) {cout<<"wrong deplacer"<<endl;}
//bool FormeGeometrique::FaitPartieDe(const Selection &maSelection) const {return false;}

/*FormeGeometrique* FormeGeometrique::Copy() const
{
    list<Selection *> parQuiSuisJeSel;
    list<Selection *>::const_iterator i = parQuiSuisJeSelectionne.begin();
    for(i ; i!=parQuiSuisJeSelectionne.end() ; ++i)
    {
        parQuiSuisJeSel.push_back(*i);
    }
    return nullptr;
}*/

//------------------------------------------------- Surcharge d'operateurs


//-------------------------------------------- Constructeurs - destructeur

FormeGeometrique::FormeGeometrique(const FormeGeometrique &uneFormeGeometrique) : Forme(uneFormeGeometrique.nomForme)
{
    list<Selection *>::const_iterator i = uneFormeGeometrique.parQuiSuisJeSelectionne.begin();
    for(i ; i!=uneFormeGeometrique.parQuiSuisJeSelectionne.end() ; ++i)
    {
        parQuiSuisJeSelectionne.push_back(new Selection(**i));
    }
}

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

FormeGeometrique::FormeGeometrique(string nom, list<Selection *> parQuiSuisJeSelectionne) : Forme(nom)
{
    this->parQuiSuisJeSelectionne = parQuiSuisJeSelectionne;
}


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

istream& FormeGeometrique::fluxRentrant(istream &is)
{
    getline(is,nomForme,' ');
    return is;
}

ostream& FormeGeometrique::fluxSortant(ostream &os)
{
    os << nomForme
       << endl;
    return os;
}

ostream &operator<<(ostream &os, FormeGeometrique &r) {
    return r.fluxSortant(os);
}

istream &operator>>(istream &is, FormeGeometrique &r) {
    return r.fluxRentrant(is);
}