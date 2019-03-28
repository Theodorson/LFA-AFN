#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

ifstream f;

struct Stari
{
int inceput;
vector <int> inceput_finale;
vector <char> litera;
};



void citire_AFN (Stari **A,int &nr_stari,int &nr_tranzitii,int &nr_stari_finale,int &nr_litere,int **finale,char **litere)
{
    f.open("date.in.txt");


    f>>nr_stari;
    f>>nr_tranzitii;
    f>>nr_stari_finale;

    *finale=new int[nr_stari_finale];


    f>>nr_litere;
    *litere=new char[nr_litere];

    *A=new Stari[nr_stari];

    int x,y,contor=0;
    char z,aux[nr_litere];

    f.close();

    for(int i=0;i<nr_stari;i++)
        {(*A)[i].inceput=i;
            f.open("date.in.txt");

            f>>nr_stari>>nr_tranzitii>>nr_stari_finale;

                for (int p=0; p<nr_stari_finale; p++)
                f>>(*finale)[p];

                f>>nr_litere;

                for (int p=0; p<nr_litere; p++)
                f>>(*litere)[p];

            while(f>>x>>z>>y)
            {
                if(x==(*A)[i].inceput)
                {
                (*A)[i].inceput_finale.resize(contor);
                (*A)[i].inceput_finale.push_back(y);
                (*A)[i].litera.resize(contor);
                (*A)[i].litera.push_back(z);
                contor++;
                }
                else
                contor=0;

            }
            f.close();
        }

}

void afisare_AFN(Stari *A,int nr_stari,int nr_tranzitii,int nr_stari_finale,int nr_litere,int *finale,char *litere)
{
cout<<"Nr de stari="<<nr_stari<<endl;
cout<<"Nr de tranzitii="<<nr_tranzitii<<endl;
cout<<"Nr de stari finale="<<nr_stari_finale<<endl;
cout<<"Nr de litere="<<nr_litere<<endl;

int i;
cout<<"Starile finale sunt=";
for (i=0; i<nr_stari_finale; i++)
  cout<<finale[i]<<" ";
  cout<<endl;

cout<<"Literele automatului sunt: ";
for (i=0; i<nr_litere; i++)
 cout<<litere[i]<<" ";
 cout<<endl;

for (i=0; i<nr_stari; i++)
{
    cout<<A[i].inceput;
    for(int j=0;j<A[i].inceput_finale.size();j++)
        {
        cout<<" "<<A[i].inceput_finale[j]<<" ";
        cout<<" "<<A[i].litera[j]<<" ";
        }
cout<<endl;
}

}


bool verificare_cuvant_AFN(int contor_cuvant,Stari *A,int stare_initiala,int nr_stari_finale,int *finale,char *cuvant)
{   if(cuvant[contor_cuvant]==NULL)
    {
        for(int i=0;i<nr_stari_finale;i++)
            if(stare_initiala==finale[i])
            return 1;

        return 0;
    }

     for(int i=0;i<A[stare_initiala].litera.size();i++)
        if(cuvant[contor_cuvant]==A[stare_initiala].litera[i])
        {
        stare_initiala=A[stare_initiala].inceput_finale[i];
        if(verificare_cuvant_AFN(contor_cuvant+1,A,stare_initiala,nr_stari_finale,finale,cuvant))
        return 1;
        }
return 0;
}


int main()
{
    int nr_stari,nr_tranzitii,nr_stari_finale,stare_initiala,nr_litere,*finale,k=0;
    char *litere,*cuvant="accac";
    Stari *A;

    citire_AFN(&A,nr_stari,nr_tranzitii,nr_stari_finale,nr_litere,&finale,&litere);
    afisare_AFN(A,nr_stari,nr_tranzitii,nr_stari_finale,nr_litere,finale,litere);
    stare_initiala=0;

    if(verificare_cuvant_AFN(0,A,0,nr_stari_finale,finale,cuvant)==0)
     cout<<"Cuvant neacceptat de automat"<<endl;
    else cout<<"Cuvant acceptat de automat"<<endl;
    return 0;
}
