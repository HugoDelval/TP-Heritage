/*************************************************************************
Application  -  description
-------------------
d�but                : 16/01/2015
copyright            : (C) 2015 par B3424
*************************************************************************/

//---------- R�alisation de la classe <Application> (fichier Application.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Application.h"
#include <sstream>

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
void Application::LancerApplication ()
{
    string commande="";
    string type="";
    bool sortir = false;
    EnsembleFormes* nouvelEtat = new EnsembleFormes();
    listeEtats.push_back(nouvelEtat);
    etatCourant=listeEtats.begin();
    FormeGeometrique* formeAAjouter;
    Selection* selectionAAjouter;
    while(!sortir)
    {
        getline(cin,commande);
        istringstream iss(commande);
        iss >> type;
        if(type.compare("C")==0){
            //ajout cercle
            string name,x1,y1,rayon;
            iss >> name;
            iss >> x1;
            iss >> y1;
            iss >> rayon;
            cout<< "commande C with : "+name+" "+x1+" "+y1+" "+rayon<<endl;
        }else if(type.compare("R")==0){
            // ajout rectangle
            string name,x1,x2,y1,y2;
            iss >> name;
            iss >> x1;
            iss >> y1;
            iss >> x2;
            iss >> y2;
            formeAAjouter=new Rectangle(name,atoi(x1.c_str()),atoi(y1.c_str()),atoi(x2.c_str()),atoi(y2.c_str()));
            nouvelEtat=new EnsembleFormes(**etatCourant);
            bool bienInsere = nouvelEtat->AjouterFormeGeo(formeAAjouter);
            if(bienInsere)
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelEtat);
                etatCourant++;
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(type.compare("L")==0){
            // ajout ligne
            cout<< "commande L"<<endl;
        }else if(type.compare("PL")==0){
            // ajout polyligne
            cout<< "commande PL"<<endl;
        }else if(type.compare("S")==0){
            string name,x1,x2,y1,y2;
            iss >> name;
            iss >> x1;
            iss >> y1;
            iss >> x2;
            iss >> y2;
            Rectangle r(name+"RectangleAssociee",atoi(x1.c_str()),atoi(y1.c_str()),atoi(x2.c_str()),atoi(y2.c_str()));
            selectionAAjouter=new Selection(name,&r);
            nouvelEtat=new EnsembleFormes(**etatCourant);
            bool bienInsere = nouvelEtat->AjouterSelection(selectionAAjouter);
            if(bienInsere)
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelEtat);
                etatCourant++;
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(type.compare("DELETE")==0){
            // suppession
            cout<< "commande DELETE"<<endl;
        }else if(type.compare("MOVE")==0){
            string name,dx,dy;
            iss >> name;
            iss >> dx;
            iss >> dy;
            nouvelEtat=new EnsembleFormes(**etatCourant);
            nouvelEtat->Deplacer(name,atoi(dx.c_str()),atoi(dy.c_str()));
            eraseAllFrom(etatCourant);
            listeEtats.push_back(nouvelEtat);
            etatCourant++;
            cout<<"OK"<<endl;
        }else if(type.compare("LIST")==0){
            // enumerer
            (*etatCourant)->Lister();
        }else if(type.compare("UNDO")==0){
            if(undo())
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(type.compare("REDO")==0){
            if(redo())
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(type.compare("LOAD")==0){
            // charger fichier
            cout<< "commande LOAD"<<endl;
        }else if(type.compare("SAVE")==0){
            // enregistrer dans un fichier
            cout<< "commande SAVE"<<endl;
        }else if(type.compare("CLEAR")==0){
            // tout vider
            cout<< "commande CLEAR"<<endl;
        }else if(type.compare("EXIT")==0){
            // arreter
            sortir=true;
        }
    }
    delete formeAAjouter;
    delete selectionAAjouter;
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

//----------------------------------------------------- M�thodes privees

bool Application::undo() {
    bool res = false;
    if(etatCourant != listeEtats.begin())
    {
        etatCourant--;
        res = true;
    }
    return res;
}  //----- Fin de undo

bool Application::redo() {
    bool res = false;
    if(etatCourant != listeEtats.end())
    {
        etatCourant++;
        res = true;
    }
    return res;
}  //----- Fin de undo

void Application::eraseAllFrom(list<EnsembleFormes*>::iterator debut)
{
    debut++;
    while (debut != listeEtats.end())
    {
        listeEtats.erase(debut++);
    }
}