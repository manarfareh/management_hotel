#include "reservation.h"
ostream& operator<<(ostream& out, Reservation& r) // surcharge
{

     out<<"Client  : "<<endl<<r.cl;
     out<<"Entite : "<<endl<<r.e;
     out<<"Nombre de jour : "<<r.nbjours<<endl;
     out<<"Date de d'arrivee :"<<r.DateDebutR<<endl;
     out<<"Date de depart :"<<r.DateFinR<<endl;

     out<<"Les services :    "<<endl;
     for (int i=0;i<r.t.size();i++)

     out<<r.t[i].getdes()<<endl;
     out<<"Facture :"<<endl<<r.fac;

     return out;
 }
void Reservation::ajouter(Entite et) // fonction qui permet d ajouter une reservation
 {

     Service tab[7];

          Service  massage , spa , gym , casino , salonDeBeaute ,sauna;
          massage.setDES("Massage");
          massage.setIds("1");
          massage.setprix(55);
          tab[0]=massage;
          gym.setDES("Gym");
          gym.setIds("2");
          gym.setprix(6);
          tab[1]=gym;
          casino.setDES("Casino");
          casino.setIds("3");
         casino.setprix(77);
         tab[2]=casino;
          sauna.setDES("Sauna");
          sauna.setIds("4");
          sauna.setprix(88);
          tab[3]=sauna;
          spa.setDES("Spa");
          spa.setIds("5");
          spa.setprix(88);
          tab[4]=spa;
          salonDeBeaute.setDES("SalonDeBeaute");
          salonDeBeaute.setIds("6");
          salonDeBeaute.setprix(99);
          tab[5]=salonDeBeaute;
     cout<<"Saisir les donnees du client : "<<endl;
     cin>>cl;
     e=et;
     cout<<"Saisir Date de d arrive :      "<<endl;
     cin>>DateDebutR;
     cout<<"Saisir Date de depart :        "<<endl;
     cin>>DateFinR;
     cout<<"Saisir nombre de jour :     "<<endl;
     cin>>nbjours;
     cout<<"Choisir les services :    "<<endl;
    int nbrservice=0;
    for(int i=1;i<7;i++)
    {cout<<i<<":"<<tab[i-1].getdes()<<endl;}
     cout<<6<<":"<<"Quitter"<<endl;

    while(1)
    {
        int a;
        cin>>a;
        if(a==7) break;
        nbrservice++;
        t.push_back(tab[a]);
         fac.setmontant(tab[a].getprix());
    }
    cout<<"Saisir date d'aujourdhui"<<endl;
    Date d;
    cin>>d;
    fac.setdate(d.getjour(),d.getmois(),d.getannee());
    cout<<"Saisir id facture : "<<endl;
    string ch;
    cin>>ch;
    fac.setidf(ch);
	cout<<"Montant a payer :"<<fac.getmontant()<<endl;
    e.setStatus(1);

 }



void  Reservation::ouvrir(fstream & f) // Ouverture de fichier
{
    f.open("reservation.txt",ios::in|ios::app);
    if(!f.is_open()) exit -1;
}
void Reservation::remplir_reservation(fstream& f) // remplissage dans le fichier
{
     Reservation::ouvrir( f);
     f<<"---------------------------------------------------------------------------------------"<<endl;
    string ch;
    f<<"Client : "<<endl;
    cl.remplir(f);
    f<<"Entite : "<<endl;
    e.remplir_entite(f);
    f<<"Nombre de jour: "<<endl<<nbjours<<endl;
    f<<"Date d'arrivee : "<<endl<<DateDebutR<<endl;
	f<<"Date de depart : "<<endl<<DateFinR<<endl;
	f<<"services : " <<endl;
	fac.setmontant(nbjours*e.getPrix());
	for(int i=0;i<t.size();i++) {ch=t[i].getdes()/*service*/;f<<ch<<endl;}
	f<<"Facture :"<<endl;
     fac.remplir(f);
     f.close();

}

  void Reservation::lire(fstream& f) // Lecture à partir de fichier
  {
     Reservation::ouvrir( f);

    char ch[101];
   f.getline(ch,100);
   f.getline(ch,100);
    cl.lire(f);
    e.lire_entite(f);
    f>>nbjours;
    f.getline(ch,100);
    f.getline(ch,100);
    f.getline(ch,100);
    DateDebutR.lire(f);
   f.getline(ch,100);
   f.getline(ch,100);
    DateFinR.lire(f);
   for(int i=0;i<t.size(); i++) {
            f.getline(ch,100);}
    f.getline(ch,100);
    f.getline(ch,100);

    fac.lire( f);

    f.close();
  }

  void Reservation::modifier_reservation(Client clt)
  {
      vector<Reservation*> vec;
      fstream f;
      Reservation::ouvrir(f);
      while(1)
      {

          lire(f);
         if(!f.eof()) break;
          vec.push_back(this);
      }
      cout<<*this;
      cout<<vec.size()<<endl;
      cout<<*vec[0];
      for(int i=0 ;i<vec.size();i++)
        if(clt.getCIN()==(vec[i]->cl).getCIN()) {cout<<i;vec[i]->ajouter(vec[i]->e);};
      for(int i=0 ;i<vec.size();i++) vec[i]->remplir_reservation(f);

  }
   void Reservation::annuller_reservation(Client clt)
   {
       vector<Reservation> vec;
       fstream f;
      Reservation::ouvrir(f);
      while(1)
      {
          Reservation::lire(f);
          if(!f.eof()) break;

          vec.push_back(*this);

      }
      for(int i=0 ;i<vec.size();i++)
        if(clt.getCIN()==(vec[i].cl).getCIN()) vec.erase(vec.begin(),vec.begin()+i);
      for(int i=0 ;i<vec.size();i++) vec[i].remplir_reservation(f);
   }
