#ifndef HOTEL_H_INCLUDED
#define HOTEL_H_INCLUDED
#include <string>
#include <fstream>
#include <iostream>
#include <istream>
#include<vector>
#include"entite.h"
using namespace std;
/*************Class Hotel****************************/
class Entite;
class Hotel {

    string IdHotel;//Identifiant hotel
    string NomHotel;//Nom hotel
    string Adresse;//Adresse
    vector <Entite*> v;
public:

    Hotel();//Constructeur
    Hotel(const Hotel&);//Constructeur par recopie
    ~Hotel(void ); //Destructeur
    static void creer(fstream& ); //Creation fichier
    static void  remplir(fstream &); //Remplissage fichier
    static void  afficher(fstream& );//Affichage fichier
    void inserer (Entite*);//Insertion entite
    friend ostream& operator<< (ostream& ,const Hotel&);//Surcharge
    friend istream& operator>> (istream& ,Hotel& );//Surcharge
    int ChoisirHotel(vector<Hotel*> );//Choisir Hotel
    void EnregistrerFichier(); //Enregistrer dans un fichier
    int  Rechercher();//Rechercher
    void afficherH();//Affichage
     vector <Entite*> getVecteur(){return v;}//Retourner vecteur

};

#endif // HOTEL_H_INCLUDED
