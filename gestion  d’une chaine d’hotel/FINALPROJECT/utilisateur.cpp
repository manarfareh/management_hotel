#include"utilisateur.h"
#include"reservation.h"
#include"hotel.h"
#include <vector>

void menu(); //Menu
void EnregistrerFichier();
void gererEntite(); //Gerer les entites
void GererReservation(); //Gerer les reservations
void Entete() // En tete
{
    cout<<"\n\n\n";
    cout<<"\t\t**********************************        MENU        *******************************\n\n";
}
void menu()
{
    int choice;
    Utilisateur u;
    string ch ;
    cout<<endl;
    cout<<"\n\t\t*******************************************************************************************\n\n";
    cout<<"\n\t\t\t                            Welcome login page                              \n\n";
    cout<<"\n\t\t*******************************************************************************************\n\n";
    cin.get();
    system("cls");

    Entete();
    cout<<"\n\n\t\t\t\t\t\t1.Login"<<endl;
    cout<<"\t\t\t\t\t\t2.Inscription"<<endl;
    cout<<"\t\t\t\t\t\t3.Mot de passe oublie"<<endl;
    cout<<"\t\t\t\t\t\t4.Exit"<<endl;
    cout<<"Entrer votre choix :";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {

    case 1:
        u.login();
        break;
    case 2:
        u.registr();
        break;
    case 3:
        u.forgot();
        break;
    case 4:
        system("cls");
        exit( EXIT_SUCCESS );
        break;

    default:
        system("cls");
        cout<<"Erreur! veuillez reessayer de nouveau"<<endl;
        menu();


    }

}
int menu2() // Menu 2
{
    int choix2;
    string ch;
again:
    system("cls");
    cout<<"\n";
    cout<<"\n\n\t\t\t\t\t\t1.Administrateur"<<endl;
    cout<<"\n\t\t\t\t\t\t2.Personnel de service"<<endl;
    cout<<"\n\t\t\t\t\t\t3.Exit"<<endl;
    cout<<"Entrer votre choix :";
    cin>>choix2;
    cout<<endl;

    return choix2;
}
void Utilisateur::login() // Login
{
    int count=0;
    int choix2;
    string ch;
    system("cls");
    Entete();
    choix2=menu2();
    switch(choix2)
    {
    case 1:
        ch="database.txt" ;
        break;
    case 2:
        ch="text.txt";
        break;
    case 3:
        menu();
        break;


    }
    string user,pass,u,p;
    system("cls");
    cout<<"Remplir les details suivants"<<endl;
    cout<<"Login :";
    cin>>user;
    cout<<"Mot de passe :";
    cin>>pass;
    ifstream input(ch);
    while(input>>u>>p)
    {
        if(u==user && p==pass)

        {
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1)
    {
        cout<<"\n\t\t*******************************************************************************************\n\n";
        cout<<"\n\t\t\t                            Bonjour\t"<< user<<"                            \n\n";
        cout<<"\n\t\t*******************************************************************************************\n\n";
        cin.get();
        switch(choix2)
        {
        case 1:
            gererEntite();
            break;
        case 2:
            GererReservation();
            break;
        }


    }
    else
    {
        cout<<"LOGIN ERROR ,Veuillez verifier votre Login ou mot de passe";


    }
    //menu();
}
void Utilisateur::registr() // Inscription
{

    system("cls");
    string reguser,regpass,ru,rp,ch;


    int choix2;
    choix2=menu2();
    switch(choix2)
    {
    case 1:
        ch="database.txt" ;
        break;
    case 2:
        ch="text.txt";
        break;
    case 3:
        menu();
        break;


    }
    system("cls");
    cout<<"Entrer Login:";
    cin>>reguser;
    cout<<"Entrer Mot de passe :";
    cin>>regpass;

    ofstream reg(ch,ios::app);
    reg<<reguser<<' '<<regpass<<endl;
    system("cls");
    cout<<"Registration Success!!";
    menu();



}

void Utilisateur::forgot() // En cas de mot de passe ou bien login oublie
{
    int ch;
    string ch2;
    system("cls");
    Entete();
    ch2=menu2();
    system("cls");
    cout<<"oublie ? \n";
    cout<<"1.Rechercher votre id par login"<<endl;
    cout<<"2.Rechercher votre id par mot de passe"<<endl;
    cout<<"3.Menu principal"<<endl;
    cout<<"Entrer votre choix :";
    cin>>ch;
    switch(ch)
    {
    case 1:
    {
        int count=0;
        string searchuser,su,sp;
        cout<<"Entrer votre login :";
        cin>>searchuser;

        ifstream searchu(ch2);
        while(searchu>>su>>sp)
        {
            if(su==searchuser)
            {
                count=1;
            }
        }
        searchu.close();
        if(count==1)
        {
            cout<<"Hurray!, Compte trouve\n";
            cout<<"Votre mot de passe est "<<sp;
            cin.get();
            cin.get();
            system("cls");

        }
        else
        {
            cout<<"Desole, Votre login n existe pas dans la base de donnees\n";
            cin.get();

        }
        break;
    }
    case 2:
    {
        int count=0;
        string searchpass,su2,sp2;
        cout<<"Entrer votre Mot de passe:";
        cin>>searchpass;

        ifstream searchp(ch2);
        while(searchp>>su2>>sp2)
        {
            if(sp2==searchpass)
            {
                count=1;
            }
        }
        searchp.close();
        if(count==1)
        {
            cout<<"Votre mot de pass trouvee \n";
            cout<<"Votre login esr : "<<su2;
            cin.get();
            cin.get();
            system("cls");
            menu();

        }
        else
        {
            cout<<"Desole, votre mot de passe n'existe pas dans la base de donnee \n";
            cin.get();
            cin.get();

        }

        break;
    }

    case 3:
    {
        cin.get();

    }
    default:
        cout<<"Veuillez ressayez de nouveau"<<endl;
        forgot();
    }
}
vector<Hotel*> copier_fichier_dans_var(vector<Hotel*>tab) //permet de copier contenu de fichier dans un variable
{
    string ch;
    fstream f("hotel.txt", ios::in|ios::out|ios::app);
    if (!f) cout<<"Impossible de creer le fichier "<<endl;
    while (1)
    {
        Hotel*h=new Hotel;
        f>>*h;
//cout<<*h;
        if(f.eof()) break;
        tab.push_back(h);
    }
    f.close();

    return tab;
}
vector<Reservation*> copier_fichier_dans_var(vector<Reservation*>tab)// copier fichier dans variable
{
    string ch;
    int i=0;
    fstream f("reservation.txt", ios::in|ios::out|ios::app);
    if (!f) cout<<"Impossible de creer le fichier "<<endl;
    while (1)
    {
        Reservation*r=new Reservation;
        r->lire(f);
        cout<<"-------------------------------------------------"<<endl;
        cout<<*r;
        cout<<"-------------------------------------------------"<<endl;
       if(f.eof()) break;
        tab.push_back(r);
        cout<<"-------------------------------------------------"<<endl;

    }
    f.close();
    return tab;
}
void gererEntite() // gerer les entites
{

    int x, i,choix;
    vector<Hotel*>tab;
    Entite e;
    Hotel h,h1;
    fstream f;
    h.creer(f);
    h.remplir(f);
    f.close();
    h1.creer(f);
    f>>h1;
    cout<<h1;
    tab=copier_fichier_dans_var(tab);
    //system("cls");

    i=h.ChoisirHotel(tab);
flag:
    cout<<"-------------------------------------"<<endl;
    cout<<"1.Ajouter Entite"<<endl;
    cout<<"2.Modifier Entite"<<endl;
    cout<<"3.Disponibilite Entite"<<endl;
    cout<<"4.Afficher les donnees de l hotel"<<endl;
    cout<<"5.Quitter"<<endl;
    cout<<"-------------------------------------"<<endl;
    cin>>choix;
    switch (choix)
    {
    case 1:
        e.ajouter_entite();
        cout<<*tab[i];
        tab[i]->inserer(&e);
        goto flag;
        break;
    case 2:
        x=(*tab[i]).Rechercher();
        tab[i]->getVecteur()[x]->modifier_entite();
        goto flag;
        break;
    case 3:
        e.disponibile_entite();
        goto flag;
        break;
    case 4:
        tab[i]->afficherH();
        goto flag;
        break;
    case 5:
        tab[i]->EnregistrerFichier();
        menu();
        break;
    }

}
void Hotel:: EnregistrerFichier()
{
    fstream f("hotel.txt",ios::in|ios::out|ios::app);
    if (!f) {cout<<"\n Erreur fichier hotel"; }
    for(int i=0;i<v.size();i++){
            f << *v[i];
    f.close();
}
}
   void GererReservation()
   {
fstream f;
    int x, i,choix;
    Hotel h;
    Entite e;
   vector<Hotel*>tab;
   Client cl;
    tab=copier_fichier_dans_var(tab);


    system("cls");
    i=h.ChoisirHotel(tab);
    flag:
    system("cls");
    cout<<"1.Ajouter reservation"<<endl;
    cout<<"2.Modifier reservation"<<endl;
    cout<<"3.annuler reservation"<<endl;
    cout<<"4.afficher reservation"<<endl;
    cout<<"5.quitter"<<endl;

    cin>>choix;
    switch (choix)
    {
        case 1:
            {Entite e;
            Reservation r;
            e.ajouter_entite();
            r.ajouter(e);
            r.remplir_reservation(f);


            goto flag;
            break;}
        case 2:{Reservation r;
            cl.Saisir();
               r.modifier_reservation(cl);
            goto flag;}
            break;
        case 3:{Reservation r ;cl.Saisir();
       r.annuller_reservation(cl);
            goto flag;

        break;}

        case 4:menu();
        break;
    }
   }
