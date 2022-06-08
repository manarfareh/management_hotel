#include"entite.h"
void  Entite::ouvrir(fstream& f) // Ouverture de fichier
   {
      f.open("reservation.txt",ios::in|ios::app);
    if(!f.is_open()) exit -1;
   }
   void Entite::remplir_entite (fstream& f ) //Remplir l entite dans le fichier
   {


    f<<"identite : "<<endl;
    f<<IdE<<endl;
    f<<"type : "<<endl;
    f<<type<<endl;
    f<<"etage : "<<endl;
    f<<Etage<<endl;
    f<<"Numero : "<<endl;
    f<<Numero<<endl;
    f<<"Prix: "<<endl;
    f<<Prix<<endl;
    f<<"Capacite : "<<endl;
    f<<Capacite<<endl;
    f<<"status : "<<endl;
    f<<status<<endl;


   }
    void Entite::lire_entite (fstream& f ) // Lecture d entite à partir de fichier
   {

    char ch[101];

   f.getline(ch,100);
   f.getline(ch,100);
    f>>IdE;
     f.getline(ch,100);
     f.getline(ch,100);
    f>>type;
     f.getline(ch,100);
     f.getline(ch,100);
    f>>Etage;
     f.getline(ch,100);
     f.getline(ch,100);
    f>>Numero;

     f.getline(ch,100);
     f.getline(ch,100);
    f>>Prix;
    f.getline(ch,100);
    f.getline(ch,100);
    f>>Capacite;
     f.getline(ch,100);
     f.getline(ch,100);
    f>>status;
     f.getline(ch,100);
     f.getline(ch,100);



   }

  void Entite::disponibile_entite() // l entite est disponible ou pas
   {
      if (status==1) cout<<"Disponible\n";
      else cout<<"Non Disponible\n";

   }
  void Entite::modifier_entite() // Modification de l entite
  {
    cout<<"Modification de prix: "<<endl;
    cin>>Prix;  //setprix
    cout<<"Modification de status:"<<endl;
    cin>>status;
   }
void Entite::ajouter_entite() //Ajout de l entite
{
    cout<<"Entrer l'identificateur d' entite :\n";
    cin>>IdE;
    cout<<"Entrer le type d'entite: \n";
    cin>>type;
    cout<<"Entrer l' Etage d'entite :\n";
    cin>>Etage;
    cout <<"Entrer le Numero d' entite :\n";
    cin>>Numero;
    cout <<"Entrer le prix d' entite :\n";
    cin>>Prix;
    cout <<"Entrer la capacite d' entite :\n";
    cin>>Capacite;
    cout <<"Entrer le status d' entite :\n";
    cin>>status;

}
ostream& operator<< (ostream& out  , const Entite& e) // Surcharge
   {
        out<<e.IdE<<endl;
        out<<e.type<<endl;
        out<<e.Etage<<endl;
        out<<e.Numero<<endl;
        out<<e.Prix<<endl;
        out<<e.Capacite<<endl;
        out<<e.status<<endl;
     return out;
   }
istream& operator>> (istream& in  , Entite& e) //Surcharge
   {
        in>>e.IdE;
        in>>e.type;
        in>>e.Etage;
        in>>e.Numero;
        in>>e.Prix;
        in>>e.Capacite;
        in>>e.status;
     return in;
   }
