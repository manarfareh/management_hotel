#ifndef FACTURE_H_INCLUDED
#define FACTURE_H_INCLUDED
#pragma once
#include<iostream>
#include<string>
#include<istream>
#include <ctime>
using namespace std;
#include"date.h"
#include"client.h"
/***********Class Facture*********/
class Facture {

    string IdF; // Identifiant de facture
    float montant; // Montant
    Date DateFacture; // Date de facture

public:
    Facture(){}; // Constructeur
    ~Facture(){}; // Destructeur
   void setmontant(float c){ montant=montant+c;} //Set montant
   float getmontant(){return montant;} // Get montant
  void setidf(string a){IdF=a;} // Set identite de facture
   string getidf(){return IdF;} // get Identite de facture
   void setdate(string a,string b,string c){DateFacture.setjour(a);DateFacture.setmois(b);DateFacture.setannee(c);} // Set date
    void remplir(fstream&);// Remplissage de fichier
    void lire(fstream&); // Lecture de fichier
    void ouvrir(fstream&); //Ouverture de fichier
    friend ostream& operator<<(ostream&, Facture&); // Surcharge
    friend istream& operator>>(istream&, Facture&); // Surcharge

};


#endif // FACTURE_H_INCLUDED
