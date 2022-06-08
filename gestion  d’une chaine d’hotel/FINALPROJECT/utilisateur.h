#ifndef UTILISATEUR_H_INCLUDED
#define UTILISATEUR_H_INCLUDED
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<istream>
#include<fstream>
void menu();
/*******************Class Utilisateur**********************/
class Utilisateur
{
    protected:
    int CIN; //Identite utlisateur
    string Nom; // Nom
    string Prenom;//Prenom
    string Email;//Email
public:
    Utilisateur(){};//Constructeur
    void registr();//Inscription
    void login(); //Login
    void forgot(); //Mot de passe oublié
   ~Utilisateur(){}//Destructeur
};


#endif // UTILISATEUR_H_INCLUDED
