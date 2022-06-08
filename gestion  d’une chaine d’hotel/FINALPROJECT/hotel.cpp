#include"hotel.h"
#include<vector>
Hotel::Hotel(){}


Hotel::Hotel(const Hotel& h)
{
    Entite*e;
    IdHotel=h.IdHotel;
    NomHotel=h.NomHotel;
   Adresse=h.Adresse;

   for (int i=0; i<h.v.size();i++)
   {
       e=new Entite(*h.v[i]);
       v.push_back(e);
   }
}
Hotel::~Hotel(void )
{
    for(int i=0;i<v.size();i++)
    delete v[i];
    v.clear();
}
void Hotel::creer(fstream& f)
{
     f.open("hotel.txt", ios::in | ios::out | ios::app );
      if (! f.is_open()) exit(-1);
}
void Hotel::remplir(fstream& f)
{
  Hotel h;
  cout<<"Saisir Id hotel: "<<endl;
   cin>>h.IdHotel;
   f<<h.IdHotel<<endl;
    cout<<"Saisir Nom d'hotel: "<<endl;
   cin>>h.NomHotel;
   f<<h.NomHotel<<endl;
   cout<<"Saisir adresse  d'hotel: "<<endl;
   cin>>h.Adresse;
   f<<h.Adresse<<endl;
}
void Hotel:: afficher(fstream& f) // permet d afficher l hotel
   {
       cout<<"Affichage du fichier "<<endl;
        f.seekg(0);
        char ch[100];
        while  (1)
        {
         f.getline (ch,100);
         if (f.eof()) break;
         cout <<ch<<endl;
        }
   }

int Hotel::ChoisirHotel (vector<Hotel*> tab) // permet de choisir l'hotel
{
    cout<<"Saisir l Id de l hotel"<<endl;
    cin>>IdHotel;
    for (int i=0;i<tab.size();i++)
        if (tab[i]->IdHotel==IdHotel)
        return i;
}
int Hotel:: Rechercher()             //fonction qui permet de retourner  l'indice d'un entite � rechercher
        {
            int p=-1;
            string x;
            cout<<"Saisir le numero d entite � rechercher"<<endl;
            cin>>x;
            cout<<"--------------------------------------------------------"<<endl;
            for(int i=0;i<v.size();i++)
            {
                if(x==v[i]->getnumero())
                {
                    p=i;
                    cout<<"valeur "<<i<<endl;
                    break;
                }
            }
            cout<<"--------------------------------------------------------"<<endl;
            return p;
        }

void Hotel:: inserer ( Entite* e)// Permet d inserer entite
{
  v.push_back(e);
}

ostream & operator<<(ostream &out,const Hotel& h ) // Surcharge
{

     out<<setw(10)<<h.IdHotel<<" "<<setw(10)<<h.NomHotel<<" "<<setw(10)<<h.Adresse<<"\n";
     for (int i=0; i<h.v.size(); i++)
        out<<setw(10) <<*h.v[i]<<endl;
     return out ;
}
istream& operator>>(istream& in  ,Hotel& h) //Surcharge
  {
       in>>h.IdHotel;
       in>>h.NomHotel;
       in>>h.Adresse;
       for (int i=0; i<h.v.size(); i++)
          in>>*h.v[i];
     return in ;
  }
void Hotel::afficherH() //Afficher les informations Hotel+Entites
{
    cout<<"IdHotel :"<<IdHotel<<endl;
    cout<<"Nom Hotel:"<<NomHotel<<endl;
    cout<<"Adresse:"<<Adresse<<endl;
    for(int i=0;i<v.size();i++)
        cout<<*v[i]<<" ";

}
