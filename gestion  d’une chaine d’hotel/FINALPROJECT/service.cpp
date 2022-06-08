#include "service.h"


ostream& operator<<(ostream& out, Service& s) //Surcharge
{
    out<<"id de service:  "<<s.IdS<<endl;
    out<<"Description de service:  "<<s.Description<<endl;
    out<<"prix de service:  "<<s.prix<<endl;

    return out;
}

istream& operator>>(istream& in, Service& s) //Surcharge
{
    cout<<"saisir id de service "<<endl;
    in>>s.IdS;
    cout<<"saisir description de service "<<endl;
    in>>s.Description;
    cout<<"saisir prix de service"<<endl;
    in>>s.prix;
    return in;
}
void Service::modifierS() //Modification
{
    cout<<"saisir id de service "<<endl;
    cin>>IdS;
    cout<<"saisir description de servide "<<endl;
    cin>>Description;
    cout<<"saisir prix de service"<<endl;
    cin>>prix;
}
