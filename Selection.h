/*************************************************************************
Selection  -  description
-------------------
debut                : 17/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection.h) ------

#if ! defined ( SELECTION_H )
#define SELECTION_H

//--------------------------------------------------- Interfaces utilisees
#include <list>
#include "Rectangle.h"

class Forme; // pour eviter l'inclusion cyclique

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Selection>
//  represente une selection de formes geometriques
//  gere ses formes lors des deplacements et suppression
//------------------------------------------------------------------------ 

class Selection : public Forme
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    virtual void Deplacer ( long dx, long dy);
    // Mode d'emploi :
    //  deplace toutes les formes geometriques selectionnees de dx et dy
    // Contrat :
    //  aucun

    void Retirer(string nomForme);
    // Mode d'emploi :
    //  retire de 'mesFormesGeo' la forme de nom 'nomForme'
    // Contrat :
    //  aucun

    list<FormeGeometrique*> GetFormesSelectionnees() const;
    // Mode d'emploi :
    //  supprime toutes
    // Contrat :
    //  aucun

//------------------------------------------------- Surcharge d'operateurs


//-------------------------------------------- Constructeurs - destructeur
    Selection (Selection & uneSelection );
    // Mode d'emploi (constructeur de copie) :
    //  copie en profondeur (pas que les pointeurs) tous les attributs de l'objet en parametre.
    // Contrat :
    //  aucun

    Selection ();
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    Selection (string nom, Rectangle *rectangleDeSelection);
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    Selection (string nom, list<FormeGeometrique*> &mesFormesGeo);
    // Mode d'emploi :
    //  initialise les attributs, et cree l'instance de l'objet
    // Contrat :
    //  aucun

    virtual ~Selection ( );
    // Mode d'emploi :
    //  supprime les attributs ainsi que l'instance de l'objet
    // Contrat :
    //  aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges

private:
//------------------------------------------------------- Attributs prives
    list<FormeGeometrique*> mesFormesGeo; // tableau de Formes
    Rectangle *rectangleDeSelection;

//---------------------------------------------------------- Classes amies
friend class Rectangle;
//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Selection>

#endif // SELECTION_H
