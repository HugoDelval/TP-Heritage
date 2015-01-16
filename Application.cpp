/*************************************************************************
Application  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Application.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Application::LancerApplication ()
{

} //----- Fin de LancerApplication


//-------------------------------------------- Constructeurs - destructeur

Application::Application ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
} //----- Fin du constructeur Application


Application::~Application ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
} //----- Fin de ~Application


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes privees


void Application::undo() {

}  //----- Fin de undo

void Application::redo() {

}  //----- Fin de undo
