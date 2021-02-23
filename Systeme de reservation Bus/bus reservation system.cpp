#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;
static int p = 0;
class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}

bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}

void a::install()
{
  cout<<"Entrer le numero de bus : ";
  cin>>bus[p].busn;

  cout<<"\nEntrez le nom du conducteur : ";
  cin>>bus[p].driver;

  cout<<"\nHeure d'arrivee : ";
  cin>>bus[p].arrival;

  cout<<"\nDeparture : ";
  cin>>bus[p].depart;

  cout<<"\nDe : \t\t\t";
  cin>>bus[p].from;

  cout<<"\nÀ: \t\t\t";
  cin>>bus[p].to;

  bus[p].empty();
  p++;
}

void a::allotment()
{
  int seat;
  char number[5];
  top:

  cout<<"Numéro de bus : ";
  cin>>number;

  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }

  while(n<=p)
  {
    cout<<"\nNumero de la place : ";
    cin>>seat;

    if(seat>32)
    {
      cout<<"\nIl n'y a que 32 places disponibles dans ce bus .";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Entrez le nom du passager : ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
		cout<<"La place est déjà réservé.\n";
      }
      }
    if(n>p)
    {
      cout<<"Entrez le numero de bus correct\n";
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}

void a::show()
{
  int n;
  char number[5];
  cout<<"Entrez le numero de bus : ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }

while(n<=p)
{
  vline('*');
  cout<<"Numero de bus : \t"<<bus[n].busn
  <<"\nConducteur: \t"<<bus[n].driver<<"\t\tHeure d'arrivee : \t"
  <<bus[n].arrival<<"\tDate Departure:"<<bus[n].depart
  <<"\nDe : \t\t"<<bus[n].from<<"\t\tA: \t\t"<<

  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nLa place numero "<<(a-1)<<" est deja reserve "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Entrez le numero de bus correct : ";
}

void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
  }

void a::avail()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"Le bus numero : \t"<<bus[n].busn<<"\nConducteur : \t"<<bus[n].driver
    <<"\t\tHeure arrivee: \t"<<bus[n].arrival<<"\tHeure Departure : \t"
    <<bus[n].depart<<"\nDe : \t\t"<<bus[n].from<<"\t\tA : \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
}

int main()
{
system("cls");
int w;
while(1)
{
    //system("cls");
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Installer\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Afficher\n\t\t\t"
  <<"4.Autobus disponibles. \n\t\t\t"
  <<"5.Sortie";
  cout<<"\n\t\t\tEntrez votre choix :-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
      break;

    case 2:  bus[p].allotment();
      break;

    case 3:  bus[0].show();
      break;

    case 4:  bus[0].avail();
      break;

    case 5:  exit(0);
  }
}
return 0;
}