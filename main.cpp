#include <iostream>
#include "prostopadloscian.hh"
#include "templates.cpp"
#include "m_obrotu.hh"
#include <fstream>
using namespace std;

void wait4key() {
  do {
    cout << "\n Press a key to continue..." << endl;
  } while(cin.get() != 'a');
}

int main()
{
  TWektor<double,3> tab[8];
  TMacierzKw<double,3> x;
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
  char wybor='v';

  ////////\menu/\\\\\\\\\



  while(wybor!='q')
  {

      cout<<"wybierz opcję:"<<endl<<endl;
      cout<<"o - obroc prostopadloscian"<<endl;
      cout<<"p - przesun prostopadloscian"<<endl;
      cout<<"q - wyjscie z programu"<<endl;
      cout<<"r - rysuj prostopadloscian"<<endl;
      cout<<"w - zmien wspolrzedne wierzcholkow"<<endl;


    p.rysuj_ksztalt();
    cout<<"Twoj wybor to ";
    cin>>wybor;
    switch(wybor)
    {
      case 'o':
      {
        double k;
        cout<<"Podaj kat obrotu: ";
        cin>>k;
        p.zmien_kat(k);
        wait4key();
        break;
      }

      case 'p':
      {
        TWektor<double,3> w;
        cout<<"Podaj wektor przesuniecia: ";
        cin>>w;
        p.zmien_polozenie(w);
        wait4key();
        break;
      }

      case 'q':
        cout<<"Dziekuje za skorzystanie z programu,\nmilego dnia!"<<endl;
        exit(0);
        break;

      case 'r':
        p.rysuj_ksztalt();
        wait4key();
        break;

      case 'w':
      {
        TWektor<double,3> nowe_w[8];
        cout<<"Podaj nowe wierzcholki w formie 8 wektorow:"<<endl;
        for(int i=0; i<8; i++)
        {
          cin>>nowe_w[i];
        }
        p.zmien_wierzcholki(nowe_w);
        wait4key();
        break;
      }

      default:
        cerr<<"Niepoprawna opcja wyboru z menu"<<endl;

    }
  }

return 0;
}
