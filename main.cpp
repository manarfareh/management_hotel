#include <iostream>
#include<vector>

using namespace std;

int main()
{

    long int t,n;
    double  s;

    cin>>t;

    for(int k=0;k<t;k++)
    {
        s=0;
        cin>>n;
         long int  tab1[n],tab2[n];
        long int  mina,minb;


        minb=tab2[0];
         mina=tab1[0];

        for(int i=0;i<n;i++)
        {
            cin>>tab1[i];

            if(tab1[i]<mina) mina=tab1[i];

        }
        for(int i=0;i<n;i++)
        {
            cin>>tab2[i];
            if(tab2[i]<minb) minb=tab2[i];
        }
         for(int i=0;i<n;i++)
        {
            vector<int> tab;
            int c=0;
            for(int j=i+1;j<n;j++)
            {

                if(tab1[i]==tab1[j] && tab2[i]==tab2[j] && tab1[i]>mina && tab2[i]>minb)
                {
                    tab.push_back(j);
                    c++;
                }
            }
            int p=0;

            while(tab1[i]>mina && tab2[i]>minb)
            {
                tab1[i]-=1;
                tab2[i]-=1;
                s+=1;
                if(c!=0) p++;

            }
            while(tab1[i]>mina)
            {
                tab1[i]-=1;

                s+=1;
                if(c!=0) p++;

            }
            while(tab2[i]>minb)
            {
                tab2[i]-=1;

                s+=1;
                if(c!=0) p++;

            }
            for(int o=0;o<c;o++)
            {
                    tab1[tab[o]]=mina;
                    tab2[tab[o]]=minb;

            }
            s+=c*p;





    }
    cout<<s;
    }

    return 0;
}
