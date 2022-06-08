#include"facture.h"
 ostream& operator<<(ostream& out, Facture& f) //Surcharge
 {

     out<<"Id de facture :  "<<endl<<f.IdF;
     out<<f.DateFacture<<endl;
     out<<"Montant :"<<endl<<f.montant<<endl;
     return out;
 }
istream& operator>>(istream& in, Facture& f) // Surcharge
{
    cout<<"saisir id de facture : "<<endl;
    in>>f.IdF;
    cout<<"saisir Date :"<<endl;
    in>>f.DateFacture;
     cout<<"saisir montant :"<<endl;
    in>>f.montant;
    return in;
}
  void Facture::remplir(fstream& f) // Remplissage de fichier
    {

      f<<"Id de facture : "<<endl<<IdF<<endl;
      f<<"Date de facture : "<<endl;DateFacture.remplir(f);
      f<<"Montant : "<<endl<< montant <<endl;

    }
void Facture::lire(fstream& f) // fonction permet la lecture de fichier
{

    char ch[101];

   f.getline(ch,100);
    f>>IdF;
    f.getline(ch,100);
    DateFacture.lire(f);
   f.getline(ch,100);
    f>>montant;


}
void  Facture::ouvrir(fstream & f) // Ouverture de fichier
{
    f.open("reservation.txt",ios::in|ios::out|ios::app);
    if(!f.is_open()) exit -1;
}
