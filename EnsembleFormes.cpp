/*************************************************************************
EnsembleFormes  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <EnsembleFormes> (fichier EnsembleFormes.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EnsembleFormes.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur

EnsembleFormes::EnsembleFormes ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <EnsembleFormes>" << endl;
#endif
} //----- Fin du constructeur EnsembleFormes


EnsembleFormes::~EnsembleFormes ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsembleFormes>" << endl;
#endif
} //----- Fin de ~EnsembleFormes


//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes privees

void EnsembleFormes::Sauvegarder(string nomFichier) {

}

void EnsembleFormes::Charger(string nomFichier) {

}

void EnsembleFormes::Supprimer(string nomForme, bool estUneFormeGeo) {

}

void Ajouter (Forme maForme, bool estUnFormeGeo){

}

void EnsembleFormes::Deplacer(string nomForme, long dx, long dy, bool estUneFormeGeo) {

}

void EnsembleFormes::Lister() {

}

void EnsembleFormes::Effacer() {

}
