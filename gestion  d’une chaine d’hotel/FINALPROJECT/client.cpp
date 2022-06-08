#include"client.h"
#include<iostream>
#include<iomanip>
#include<fstream>
void menu();
using namespace std;
void Client::Saisir()		//saisir les informations
{
    cout<<"Entrer cin de client :"<<endl;
	cin>>CIN;
	cout<<"Entrer nom de client :"<<endl;
	cin>>Nom;
	cout<<"Entrer prenom de client:"<<endl;
	cin>>Prenom;
	cout<<"Entrer l address de client : "<<endl;
	cin>>AdresseC;
	test:
	cout<<"Entrer numero de telephone de client: "<<endl;
	cin>>Telephone;
	for(int i=0;i<(Telephone.length());i++)	//Validation numero de telephone
     {

                                    //condition sur le numero de telephone : 8 chiffres
		if(!isdigit(Telephone[i]))
		{
			cout<<"Numero de telephone doit etre en chiffre\n"<<endl;
			goto test;
		}

  	if(Telephone.length()!=8)		//validation longeur de telephone
  	{
  	  cout<<"Numero de telephone sur 8 chiffres.\n";
  	  goto test;
 	 }
     }
     cout<<"Entrer adresse email: "<<endl;
	cin>>Email;
}
void  Client::ouvrir(fstream & f)
{
    f.open("reservation.txt",ios::in|ios::app);
    if(!f.is_open()) exit -1;
}
void Client::enregistrer(fstream & f,  Client & c)
{
    f<<c<<"\n";
}

ostream& operator<< (ostream & out ,const  Client& c)
{
    out<<"CIN :"<<endl;
    out<<c.CIN <<endl;
    out<<"Nom:"<<endl;
    out<<c.Nom <<endl;
    out<<"Prenom"<<endl;
    out<<c.Prenom <<endl;
    out<<"Telephone:"<<endl;
    out<<c.Telephone <<endl;
    out<<"Email:"<<endl;
    out<<c.Email<<endl;
    out<<"Adresse:"<<endl;
    out<<c.AdresseC<<endl;


    return out;
}
istream& operator>> (istream & in ,  Client& c)
{
    cout<<"Entrer CIN:"<<endl;
    in>>c.CIN;
    cout<<"Entrer Nom:"<<endl;
    in>>c.Nom;
    cout<<"Entrer Prenom:"<<endl;
    in>>c.Prenom;
    cout<<"Entrer Telephone:"<<endl;
    in>>c.Telephone;
    cout<<"Entrer Email:"<<endl;
    in>>c.Email;
    cout<<"Entrer Adresse:"<<endl;
    in>>c.AdresseC;



    return in;
}
void Client::remplir(fstream& f)
{

    f<<"CIN:"<<endl;
    f<<CIN<<endl;
   f<<"Nom:"<<endl;
    f<<Nom<<endl;
    f<<"Prenom:"<<endl;
    f<<Prenom<<endl;
    f<<"Telephone:"<<endl;
    f<<Telephone<<endl;
    f<<"Email:"<<endl;
    f<<Email<<endl;
   f<<"Adresse:"<<endl;
    f<<AdresseC<<endl;




}
void Client::lire(fstream& f)
{

   char ch[101];
     f.getline(ch,100,'\n');
    f>>CIN;
    f.getline(ch,100,'\n');
    f.getline(ch,100,'\n');
    f>>Nom;
     f.getline(ch,100,'\n');
     f.getline(ch,100,'\n');
    f>>Prenom;
     f.getline(ch,100,'\n');
     f.getline(ch,100,'\n');
    f>>Telephone;
     f.getline(ch,100,'\n');
     f.getline(ch,100,'\n');
    f>>Email;
     f.getline(ch,100,'\n');
     f.getline(ch,100,'\n');
    f>>AdresseC;
    f.getline(ch,100,'\n');





}
