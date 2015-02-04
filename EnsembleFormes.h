/*************************************************************************
EnsembleFormes  -  description
-------------------
début                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- Interface de la classe <EnsembleFormes> (fichier EnsembleFormes.h) ------
#if ! defined ( ENSEMBLE_FORMES_H )
#define ENSEMBLE_FORMES_H

//--------------------------------------------------- Interfaces utilisées
#include <string.h>
#include <unordered_map>
#include <map>
#include <vector>
#include "FormeGeometrique.h"
#include "Selection.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EnsembleFormes>
//  Stocke et gere toutes les FormesGeometriques et les Selections (ajout, suppression, deplacement...)
//------------------------------------------------------------------------ 

class EnsembleFormes
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Sauvegarder (string nomFichier);
    // Mode d'emploi :
    //  sauvegarde la map stockant toutes les FormesGeometriques dans un fichier texte du nom 'nomFichier'
    // Contrat :
    //  aucun

    bool Charger (string nomFichier, EnsembleFormes* ancien);
    // Mode d'emploi :
    //  charge la map stockant toutes les FormesGeometriques depuis un fichier texte du nom 'nomFichier'
    // Contrat :
    //  aucun

    vector<FormeGeometrique*> Supprimer (string nomForme);
    // Mode d'emploi :
    //  supprime la Forme du nom 'nomForme' en gerant le cas ou cette Forme est une Selection
    // Contrat :
    //  aucun

    bool AjouterFormeGeo (FormeGeometrique* maForme);
    // Mode d'emploi :
    //  ajoute la Forme 'maForme' a la map correspondante
    // Contrat :
    //  aucun

    bool AjouterSelection (Selection* maSelection);
    // Mode d'emploi :
    //  ajoute la Forme 'maSelection' a la map correspondante
    // Contrat :
    //  aucun

    bool Deplacer (string nomForme, long dx, long dy);
    // Mode d'emploi :
    //  deplace la Forme de nom 'nomForme' de dx en abscisse et dy en ordonne, en gerant le cas ou cette Forme est une Selection
    // Contrat :
    //  aucun

    void Lister ();
    // Mode d'emploi :
    //  affiche toutes les FormeGeometrique
    // Contrat :
    //  aucun

    void Effacer();
    // Mode d'emploi :
    //  vide les 2 map. Reinitialise la classe
    // Contrat :
    //  aucun

//-------------------------------------------- Constructeurs - destructeur
    EnsembleFormes (const EnsembleFormes & unEnsembleFormes );
    // Mode d'emploi (constructeur de copie) :
    //  copie en profondeur (pas que les pointeurs) tous les attributs de l'objet en parametre.
    // Contrat :
    //  aucun

    EnsembleFormes ( );
// Mode d'emploi :
//  cree un objet EnsembleFormes et initialise ses attributs
// Contrat :
//

    virtual ~EnsembleFormes ( );
// Mode d'emploi :
//  supprime tous les attributs de la classe de la memoire
// Contrat :
// aucun

friend class CommandeLoad;
friend class CommandeDelete;
//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes privees

//----------------------------------------------------- Attributs prives
    typedef map<string, FormeGeometrique*> DicoFormeGeometrique;
    typedef unordered_map<string, Selection*> DicoSelection;
    DicoFormeGeometrique mesFormes;
    DicoSelection mesSelections;
};

//--------------------------- Autres définitions dépendantes de <EnsembleFormes>

#endif // ENSEMBLE_FORMES_H

