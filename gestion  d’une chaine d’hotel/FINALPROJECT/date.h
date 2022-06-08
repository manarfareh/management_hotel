#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<istream>
#include<fstream>
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
/***********************Class Date****************************/
class Date
{
    string jour;
    string mois;
    string annee;
public:
    Date(){}; // Constructeur
    ~Date(){}; // Destructeur
    string getjour(){return jour;} // Retour jour
    string getmois(){return mois;} // Retour mois
    string getannee(){return annee;} // Retour annee
    void setjour(string a){jour=a; } // Set jour
    void setmois(string b){mois=b;} // Set mois
    void setannee(string c){annee=c;} // Set annee
    void remplir(fstream&);// Remplissage de fichier
    void lire(fstream&);// Remplissage de lecture de fichier
    void ouvrir(fstream&); //Ouverture de fichier
     friend ostream& operator<<(ostream&, Date&); // Surcharge
    friend istream& operator>>(istream&, Date&); // Surcharge
};


#endif // DATE_H_INCLUDED
