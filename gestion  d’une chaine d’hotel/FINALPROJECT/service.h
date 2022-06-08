#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<istream>
#include<iomanip>
#include<fstream>
#include<vector>
class Service {


    string IdS;//Identifiant
    string Description;//Description
    float prix;//Prix
   public:
       Service(){};//Constructeur
       ~Service(){};//Destructeur
       void ouvrir(fstream&);//Ouverture fichier
       void modifierS();//Modification service
      void setDES(string ch){Description=ch;}//Modification description
      string getdes(){return Description;}//Retourner description
      float getprix(){return prix;}//Retourner prix
       void setIds(string ch){IdS=ch;}//Modification  Identifiant
       void setprix(float c){prix=c;}//Modification de prix
       friend ostream& operator<<(ostream&, Service&);//Surcharge
    friend istream& operator>>(istream&, Service&);//Surcharge



};



#endif // SERVICE_H_INCLUDED
