/*************************************************************************
Selection  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Realisation de la classe <Selection> (fichier Selection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types prives


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Methodes publiques
void Selection::Deplacer(long dx, long dy) {

    list<FormeGeometrique*>::iterator it = mesFormesGeo.begin();
    for ( it ; it != mesFormesGeo.end(); ++it)
    {
        (*it)->Deplacer(dx, dy);
    }
} //----- Fin de Deplacer

void Selection::Retirer(string nomForme) {
    list<FormeGeometrique*>::iterator i = mesFormesGeo.begin();
    bool pasFini = true;
    while(i!= mesFormesGeo.end() && pasFini){
        if((*i)->GetNom().compare(nomForme)==0){
            pasFini=false;
        }
    }
    if(!pasFini)
        mesFormesGeo.erase(i);
}

list<FormeGeometrique*> Selection::GetFormesSelectionnees() const {
    return mesFormesGeo;
}

//------------------------------------------------- Surcharge d'operateurs


//-------------------------------------------- Constructeurs - destructeur
Selection::Selection(const Selection &uneSelection) : Forme(uneSelection.nomForme)
{
    list<FormeGeometrique*>::const_iterator i = uneSelection.mesFormesGeo.begin();
    for(i ; i!= uneSelection.mesFormesGeo.end() ; ++i)
    {
        mesFormesGeo.push_back((*i)->Copy());
    }
}

Selection::Selection () : Forme()
{
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection

Selection::Selection(string nom, Rectangle* rectangleDeSelection) : Forme(nom)
{
    this->rectangleDeSelection = rectangleDeSelection;
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
}

Selection::Selection(string nom, list<FormeGeometrique *> &mesFormesGeo) : Forme(nom)
{
    (this->mesFormesGeo) = mesFormesGeo;
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection

Selection::~Selection ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees

//------------------------------------------------------- Methodes privees

