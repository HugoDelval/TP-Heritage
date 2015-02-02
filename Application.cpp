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
#include <stdlib.h>

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "CommandeAjoutFormeGeo.h"
#include <sstream>

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Application::LancerApplication ()
{
    string commande="";
    string type="";
    bool sortir = false;
    etatCourant=listeEtats.begin();
    maStructure=new EnsembleFormes();
    FormeGeometrique* formeAAjouter;
    Selection* selectionAAjouter;
    Commande* nouvelleCommande;
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
            nouvelleCommande=new CommandeAjoutFormeGeo(maStructure,formeAAjouter);
            if(nouvelleCommande->FaireCommande())
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelleCommande);
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
            if(maStructure->AjouterSelection(selectionAAjouter))
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(type.compare("DELETE")==0){
            // suppession



        }else if(type.compare("MOVE")==0){
            string name,dx,dy;
            iss >> name;
            iss >> dx;
            iss >> dy;
        //    nouvelleCommande=new CommandeDeplacer(maStructure,name,atoi(dx.c_str()),atoi(dy.c_str()));;
            if(nouvelleCommande->FaireCommande())
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelleCommande);
                etatCourant++;
                cout<<"OK"<<endl;
            }
        }else if(type.compare("LIST")==0){
            // enumerer
            maStructure->Lister();
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
    delete nouvelleCommande;
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

bool Application::undo() {
    cout<<(*etatCourant)<<endl;
    bool res =(*etatCourant)->DefaireCommande();
    if(res && etatCourant != listeEtats.begin())
        etatCourant--;
    cout<<(*etatCourant)<<endl;
    return res;
}  //----- Fin de undo

bool Application::redo() {
    if(etatCourant != (--listeEtats.end()))
        etatCourant++;
    return (*etatCourant)->FaireCommande();
}  //----- Fin de redo

void Application::eraseAllFrom(list<Commande*>::iterator debut)
{
    debut++;
    while (debut != listeEtats.end())
        listeEtats.erase(debut++);
}