#include <iostream>
#include <cstdlib>
#include "interfejs_drona.hh"
//#include "prostopadloscian.hh"
//#include "sruba.hh"
#include "dno.hh"
#include "tafla.hh"
#include "templates.cpp"
#include "m_obrotu.hh"
#include <fstream>
using namespace std;

void wait4key() {
  do {
    cout << "\n Press a key to continue..." << endl;
  } while(cin.get() != 'a');
}

/*void wczytaj(int w_tab, string nazwa, TWektor<double,3> *tab, TMacierzKw<double,3> *x, TWektor<double,3> *sdk)
{
  fstream plik;
  TWektor<double,3> d[w_tab];
  TWektor<double,3> temp[3];

  /////wczytanie danych z pliku/////
  plik.open("nazwa.txt");
  for(int i=0; i<w_tab; i++)
  {
    plik>>d[i];
  }
  cout<<endl;
  for(int i=0; i<w_tab; i++)
  {
    if(i<w_tab-4)
      tab[i]=d[i];
    else if(i>w_tab-3 && i<w_tab-1)
      temp[i-(w_tab-4)]=d[i];
    else if(i>w_tab-2 && i<w_tab)
        sdk=d[i];
  }
  x->TMacierzKw(temp);
}
*/

int main()
{
  drawNS::APIGnuPlot3D *wsk=new drawNS::APIGnuPlot3D(-5,5,-5,5,-5,5,-1);//-1 na reczne odswiezanie
  TWektor<double,3> tab[12], tab1[12], tab2[8];
  TMacierzKw<double,3> x, x1, x2;
  TWektor<double,3> sdk, sdk1, sdk2, srw, srw1;
  TWektor<double,3> d[17];
  fstream wirnik, wirnik1, plik;

  wirnik.open("wirnik.txt");
  for(int i=0; i<17; i++)
  {
    wirnik>>d[i];
  }
  //cout<<"koniec d"<<endl;
  for(int j=0; j<17; j++)
  {
    cout<<d[j]<<endl;
  }
  cout<<endl;
  for(int i=0; i<16; i++)
  {
    if(i<12)
      tab[i]=d[i];
    else if(i>11 && i<15)
      x[i-12]=d[i];
    else if(i>14 && i<16)
        sdk=d[i];
    else if(i>15 && i<17)
        srw=d[i];
  }

  M_obr y(x);

  wirnik1.open("wirnik1.txt");
  for(int i=0; i<17; i++)
  {
    wirnik1>>d[i];
  }
  //cout<<"koniec d"<<endl;
  for(int j=0; j<16; j++)
  {
    cout<<d[j]<<endl;
  }
  cout<<endl;
  for(int i=0; i<17; i++)
  {
    if(i<12)
      tab1[i]=d[i];
    else if(i>11 && i<15)
      x1[i-12]=d[i];
    else if(i>14 && i<16)
        sdk1=d[i];
    else if(i>15 && i<17)
        srw1=d[i];
  }

  M_obr y1(x1);

  plik.open("dane.txt");
  for(int i=0; i<12; i++)
  {
    plik>>d[i];
  }
  for(int j=0; j<12; j++)
  {
    cout<<d[j]<<endl;
  }
  cout<<endl;
  for(int i=0; i<12; i++)
  {
    if(i<8)
      tab2[i]=d[i];
    else if(i>7 && i<11)
      x2[i-8]=d[i];
    else if(i>10 && i<12)
        sdk2=d[i];
  }
  M_obr y2(x);

  //Sruba g(wsk,sdk,y,tab, srw1);
  //Sruba g1(wsk, sdk1, y1, tab1, srw1);
  //Prostopadloscian p(wsk, sdk2, y2, tab2);
  Interfejs I(wsk, sdk, sdk1, sdk2, tab, tab1, tab2, y);

/////////dobry main/////////  TWektor<double,3> tab[8];
/*  TMacierzKw<double,3> x;
  TWektor<double,3> sdk;
  fstream plik;
  TWektor<double,3> d[12];

  /////wczytanie danych z pliku/////
  plik.open("dane.txt");
  for(int i=0; i<12; i++)
  {
    plik>>d[i];
  }
  for(int j=0; j<12; j++)
  {
    cout<<d[j]<<endl;
  }
  cout<<endl;
  for(int i=0; i<12; i++)
  {
    if(i<8)
      tab[i]=d[i];
    else if(i>7 && i<11)
      x[i-8]=d[i];
    else if(i>10 && i<12)
        sdk=d[i];
  }
  M_obr y(x);
  /////koniec wczytywania danych/////////

  drawNS::APIGnuPlot3D *wsk=new drawNS::APIGnuPlot3D(-5,5,-5,5,-5,5,-1);//-1 na reczne odswiezanie
  Prostopadloscian p(wsk, sdk, y, tab);
  */



  Dno dno(wsk);
  Tafla tafla(wsk);
  char wybor='v';

  ////////\menu/\\\\\\\\\

  dno.rysuj_ksztalt();
  tafla.rysuj_ksztalt();
	/*p.rysuj_ksztalt();
  g.Graniastoslup::rysuj_ksztalt();
  g1.rysuj_ksztalt();*/
  I.rysuj_ksztalt();


  while(wybor!='q')
  {

      cout<<"wybierz opcję:"<<endl<<endl;
      cout<<"o - obroc prostopadloscian"<<endl;
      cout<<"p - przesun prostopadloscian"<<endl;
      cout<<"q - wyjscie z programu"<<endl;
      cout<<"r - rysuj prostopadloscian"<<endl;


    //p.rysuj_ksztalt();
    cout<<"Twoj wybor to ";
    cin>>wybor;
    switch(wybor)
    {
      case 'o':
      {
        double k;
        cout<<"Podaj kat obrotu: ";
        cin>>k;
      /*  p.zmien_kat(k);
        g.zmien_kat(k);
        g1.zmien_kat(k);*/
        I.zmien_kat(k);
        break;
      }

      case 'p':
      {
        TWektor<double,3> w;
        cout<<"Podaj wektor przesuniecia: ";
        cin>>w;
      /*  p.zmien_polozenie(w);
        g.zmien_polozenie(w);
        g1.zmien_polozenie(w);*/
        I.zmien_polozenie(w);
        break;
      }

      case 'q':
        cout<<"Dziekuje za skorzystanie z programu,\nmilego dnia!"<<endl;
        exit(0);
        break;

      case 'r':
      /*  p.rysuj_ksztalt();
        g.rysuj_ksztalt();
        g1.rysuj_ksztalt();*/
        I.rysuj_ksztalt();
        break;



      default:
        cerr<<"Niepoprawna opcja wyboru z menu"<<endl;

    }
  }

return 0;
}
