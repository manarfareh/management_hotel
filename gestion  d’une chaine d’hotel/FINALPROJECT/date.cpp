#include"date.h"
#include<string>

 ostream& operator<<(ostream& out, Date& d)
 {

     out<<endl<<d.jour<<"/"<<d.mois<<"/"<<d.annee;

     return out;
 }
istream& operator>>(istream& in, Date& d)
{
    cout<<"Saisir jour : "<<endl;
    in>>d.jour;
    cout<<"Saisir mois:"<<endl;
    in>>d.mois;
     cout<<"Saisir annee:"<<endl;
    in>>d.annee;
    return in;
}
 void Date::remplir(fstream& f)
    {

      f<<jour<<"/"<<mois<<"/"<<annee<<endl;

    }
void Date::lire(fstream& f)
{

    char ch[101];

   f.getline(ch,100,'/');
   jour=ch;

 f.getline(ch,100,'/');
 mois=ch;

   f.getline(ch,100);
   annee=ch;


}
void  Date::ouvrir(fstream & f)
{
    f.open("reservation.txt",ios::in|ios::out|ios::app);
    if(!f.is_open()) exit -1;
}
