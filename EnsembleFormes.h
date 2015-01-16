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
#include <map>
#include 'Forme.h'
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 
typedef map<string, FormeGeometrique*> DicoFormeGeometrique;
typedef map<string, Selection*> DicoSelection;
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

    void Charger (string nomFichier);
    // Mode d'emploi :
    //  charge la map stockant toutes les FormesGeometriques depuis un fichier texte du nom 'nomFichier'
    // Contrat :
    //  aucun

    void Supprimer (string nomForme, bool estUneFormeGeo=true);
    // Mode d'emploi :
    //  supprime la Forme du nom 'nomForme' en gerant le cas ou cette Forme est une Selection
    // Contrat :
    //  aucun

    void Ajouter (Forme maForme, bool estUnFormeGeo=true);
    // Mode d'emploi :
    //  ajoute la Forme 'maForme' a la map correspondante (en fonction du bool), gere le cas ou cette Frome est une Selection
    // Contrat :
    //  aucun

    void Deplacer (string nomForme, long dx, long dy, bool estUneFormeGeo=true);
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

//------------------------------------------------------------------ PRIVE 

private:
//----------------------------------------------------- Méthodes privees

//----------------------------------------------------- Attributs prives
    DicoFormeGeometrique mesFormes;
    DicoSelection mesSelections;
};

//--------------------------- Autres définitions dépendantes de <EnsembleFormes>

#endif // ENSEMBLE_FORMES_H

