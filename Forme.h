/*************************************************************************
Form  -  description
-------------------
debut                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Form> (fichier Forme.h) ------
#if ! defined ( FORME_H )
#define FORME_H

//--------------------------------------------------- Interfaces utilisees
#include <string.h>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Form>
//
//
//------------------------------------------------------------------------ 

class Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer (long dx, long dy) = 0;
    // Mode d'emploi :
    //   deplace la forme de dx en abscisse et dy en ordonne
    // Contrat :
    //  aucun


//-------------------------------------------- Constructeurs - destructeur

    virtual Forme (string nomForme);
    // Mode d'emploi :
    //   initialise le nom de la Forme
    // Contrat :
    //   aucun

    virtual ~Forme ( );
    // Mode d'emploi :
    //   supprime les attributs de la forme
    // Contrat :
    //   aucun

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges
string nomForme;

private:
//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Form>

#endif // FORME_H
