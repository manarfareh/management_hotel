#if !defined(_RESERVATION_H)
#define _RESERVATION_H
#pragma once
#include"client.h"
#include"facture.h"
#include"date.h"
#include"service.h"
#include<iostream>
#include<string>
#include<istream>
#include<vector>
#include <ctime>
#include"date.h"
#include"entite.h"
#include"client.h"
/***********class Reservation*****************/

class Reservation
{
    Date DateDebutR;//Date de debut de reservation
    Date DateFinR; // Date fin de reservation
    int nbjours;// Nombre de jour
    Facture fac;// facture
    Client cl;//Client
    Entite e;//Entite
    vector <Service>t;

public:
    Reservation() {};
    ~Reservation() {};

    friend ostream& operator<<(ostream&, Reservation&); //Surcharge
    friend istream& operator>>(istream&, Reservation& ); //Surcharge
    void ajouter(Entite ); //Ajouter Entite
    void remplir_reservation(fstream&  );//Remplissage dans le fichier
    void modifier_reservation(Client);//Modification
    void annuller_reservation(Client );//Annumlation
    void ouvrir(fstream&);//Ouverture
    void lire(fstream&);//Lecture



};


#endif // _RESERVATION_H
