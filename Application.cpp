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
#include "CommandeDelete.h"
#include "CommandeDeplacer.h"
#include "CommandeLoad.h"
#include "Cercle.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Application::LancerApplication ()
{
    string commande="";
    bool sortir = false;
    etatCourant=listeEtats.begin();
    maStructure=new EnsembleFormes();
    FormeGeometrique* formeAAjouter= nullptr;
    Selection* selectionAAjouter= nullptr;
    Commande* nouvelleCommande= nullptr;
    while(!sortir)
    {
        getline(cin,commande);
        vector<string> args= string_split(commande, ' ');
        if(args[0].compare("C")==0){
            formeAAjouter=new Cercle(args[1],atoi(args[2].c_str()),atoi(args[3].c_str()),atoi(args[4].c_str()));
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
        }else if(args[0].compare("R")==0){
            // ajout rectangle
            formeAAjouter=new Rectangle(args[1],atoi(args[2].c_str()),atoi(args[3].c_str()),atoi(args[4].c_str()),atoi(args[5].c_str()));
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
        }else if(args[0].compare("L")==0){
            // ajout ligne
            cout<< "commande L"<<endl;
        }else if(args[0].compare("PL")==0){
            // ajout polyligne
            cout<< "commande PL"<<endl;
        }else if(args[0].compare("S")==0){
            Rectangle r(args[1]+"RectangleAssociee",atoi(args[2].c_str()),atoi(args[3].c_str()),atoi(args[4].c_str()),atoi(args[5].c_str()));
            selectionAAjouter=new Selection(args[1],&r);
            if(maStructure->AjouterSelection(selectionAAjouter))
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(args[0].compare("DELETE")==0){
            // suppession
            list<string> formesASupp;
            for(int i=1 ; i<args.size() ; i++)
                formesASupp.push_back(args[i]);
            nouvelleCommande=new CommandeDelete(maStructure,formesASupp);
            if(nouvelleCommande->FaireCommande())
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelleCommande);
                etatCourant++;
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(args[0].compare("MOVE")==0){
            nouvelleCommande=new CommandeDeplacer(maStructure,args[1],atoi(args[2].c_str()),atoi(args[3].c_str()));;
            if(nouvelleCommande->FaireCommande())
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelleCommande);
                etatCourant++;
                cout<<"OK"<<endl;
            } else {
                cout << "ERR" << endl;
            }
        }else if(args[0].compare("LIST")==0){
            maStructure->Lister();
        }else if(args[0].compare("UNDO")==0){
            if(undo())
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(args[0].compare("REDO")==0){
            if(redo())
            {
                cout<<"OK"<<endl;
            }else{
                cout<<"ERR"<<endl;
            }
        }else if(args[0].compare("LOAD")==0){
            if(!args[1].empty())
            {
                nouvelleCommande = new CommandeLoad(maStructure,args[1]);
                if(nouvelleCommande->FaireCommande())
                {
                    eraseAllFrom(etatCourant);
                    listeEtats.push_back(nouvelleCommande);
                    etatCourant++;
                    cout<<"OK"<<endl;
                } else {
                    cout << "ERR" << endl;
                }
            }else{
                cout << "ERR" << endl;
            }
        }else if(args[0].compare("SAVE")==0){
            maStructure->Sauvegarder(args[1]);
        }else if(args[0].compare("CLEAR")==0){
            nouvelleCommande = new CommandeDelete(maStructure);
            if(nouvelleCommande->FaireCommande())
            {
                eraseAllFrom(etatCourant);
                listeEtats.push_back(nouvelleCommande);
                etatCourant++;
                cout<<"OK"<<endl;
            } else {
                cout << "ERR" << endl;
            }
        }else if(args[0].compare("EXIT")==0){
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

bool Application::undo()
{
    bool res=false;
    if(listeEtats.empty())
    {
        res=true;
    }
    else
    {
        res =(*etatCourant)->DefaireCommande();
        if(res && etatCourant != listeEtats.begin())
        {
            etatCourant--;
        }
    }
    return res;
}  //----- Fin de undo

bool Application::redo()
{
    bool res=false;
    if(listeEtats.empty())
    {
        res=true;
    }
    else {
        res = (*etatCourant)->FaireCommande();
        if (etatCourant != (--listeEtats.end())) {
            etatCourant++;
        }
    }
    return res;
}  //----- Fin de redo

void Application::eraseAllFrom(list<Commande*>::iterator debut)
{
    debut++;
    while (debut != listeEtats.end())
        listeEtats.erase(debut++);
}


vector<string> Application::string_split(const string &s, const char delimiter) {
    size_t start = 0;
    size_t end = s.find_first_of(delimiter);

    vector<string> output;

    while (end <= string::npos) {
        output.emplace_back(s.substr(start, end - start));

        if (end == string::npos)
            break;

        start = end + 1;
        end = s.find_first_of(delimiter, start);
    }
    return output;
}

