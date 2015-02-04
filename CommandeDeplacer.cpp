/*************************************************************************
CommandeDeplacer  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- R�alisation de la classe <CommandeDeplacer> (fichier CommandeDeplacer.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "CommandeDeplacer.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
bool CommandeDeplacer::FaireCommande()
{
    bool res = false;
    if(!done)
    {
        res=leDessin->Deplacer(laForme, dx, dy);
        if(res)
        {
            done=true;
            unDone=false;
        }
    }
    return res;
}

bool CommandeDeplacer::DefaireCommande()
{
    bool res=false;
    if(!unDone)
    {
        res=leDessin->Deplacer(laForme, -dx, -dy);
        if(res)
        {
            done=false;
            unDone=true;
        }
    }
    return res;
}

//-------------------------------------------- Constructeurs - destructeur

CommandeDeplacer::CommandeDeplacer (EnsembleFormes* maStructure,string laFormeADeplacer, long dx, long dy)
{
    leDessin=maStructure;
    laForme=laFormeADeplacer;
    done=false;
    unDone=false;
    this->dx=dx;
    this->dy=dy;
#ifdef MAP
    cout << "Appel au constructeur de <CommandeDeplacer>" << endl;
#endif
} //----- Fin du constructeur CommandeDeplacer


CommandeDeplacer::~CommandeDeplacer ( )
{

#ifdef MAP
    cout << "Appel au destructeur de <CommandeDeplacer>" << endl;
#endif
} //----- Fin de ~CommandeDeplacer


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes privees
