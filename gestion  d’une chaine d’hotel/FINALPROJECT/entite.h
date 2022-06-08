#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED
#include<iostream>
using namespace std;
#include<string>
#include"hotel.h"
#include<iomanip>
#include<istream>
#include<vector>
#include<fstream>
/*********Class Entite**************/
class Entite {
    string IdE; //Identifiant
    string type; //Type d entite : chambre,salle de marriage,...
    int Etage; // Numero d etage
    string Numero; // Numero d entite
    float Prix; // Prix
    int Capacite; // Capacite
    int status; // Status de disponibilite
public:
   static void ouvrir(fstream& ); // Ouverture de fichier
   void remplir_entite (fstream& ); //Remplissage de entite dans un fichier
   void  lire_entite(fstream&); // Lecture à partir de fichier
   void disponibile_entite();// Disponibilte d entite
   void modifier_entite();//Modification de prix ou status
   void ajouter_entite();//Ajout d entite
   string getnumero(){return Numero;} //retourner un numero
   friend ostream& operator<< (ostream& ,const Entite&);//Surcharge
   friend istream& operator>> (istream& , Entite&);//Surcharge
    string getIdE(){return IdE;}//retourner IdE
    void setStatus(int a){status=a;} // Modifier status
   string gettype(){return type;}//Retourner type
   char getEtage(){return Etage;} //Retourner etage
   float getPrix(){return Prix;} //Retourner prix
   int getCapacite(){return Capacite;} //Retourner capacite
   int getStatus(){return status;} // Retourner status
   friend class Hotel; //Class amie
};
#endif // ENTITE_H_INCLUDED
