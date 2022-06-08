#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<iomanip>
#include<fstream>
#include"utilisateur.h"

class Client:public Utilisateur
{
    string Telephone;           //Telephone client
    string AdresseC;            //Adresse client
public:
	Client():Utilisateur(){;}
	void Saisir(); //Saisir informations
	int getCIN(){return CIN;}
	friend ostream& operator<< (ostream & , const Client& )	;	//Afficher informations
	friend istream& operator>> (istream & ,  Client& )	;	//Afficher informations
    static void ouvrir(fstream &); //Ouvrir fichier
    void remplir(fstream& ); //Remplir fichier
	static void enregistrer(fstream &, Client &); //Enregistrer dans le fichier
    void lire(fstream& ); //Lecture a partir de fichier
};


#endif // CLIENT_H_INCLUDED
