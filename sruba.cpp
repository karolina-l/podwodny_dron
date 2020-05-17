#include "sruba.hh"
#include "m_obrotu.hh"
#include "dron.hh"
#include <math.h>

using namespace std;

void Sruba::obrot_sruby()
{
  M_obr obr;

    obr=obr.utworz_mRz(1);
    for(int j=0; j<12; j++)
    {
      t[j]=t[j]-srodek;

    for(int i=0; i<12; i++)
    {
      t[i]=obr*t[i];
    }

    for(int i=0; i<12; i++)
    {
      t[i]=t[i]+srodek;
    }

    gnuplot->erase_shape(nazwa);
    this->Graniastoslup::rysuj_ksztalt();
  }
}

  void Sruba::zmien_kat(double kat)
  {
      M_obr obr;

      obr=obr.utworz_mRz(kat);
      for(int i=0; i<12; i++)
      {
        t[i]=t[i]-sr_drona;
      }
      for(int i=0; i<12; i++)
      {
        t[i]=obr*t[i];
      }

      for(int i=0; i<12; i++)
      {
        t[i]=t[i]+sr_drona;
      }

      gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();

    /*M_obr obr;
    double dzielnik=420;
    double dod=kat/dzielnik;
    for(int wycinek=1; wycinek<=dzielnik; wycinek++)
    {
      obr=obr.utworz_mRz(dod);
      for(int i=0; i<12; i++)
      {
        t[i]=t[i]-sr_drona;
      }
      for(int i=0; i<12; i++)
      {
        t[i]=obr*t[i];
      }

      for(int i=0; i<12; i++)
      {
        t[i]=t[i]+sr_drona;
      }

      usleep(0.000000001);

      gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();
    }

*/
  }

void Sruba::zmien_polozenie(const TWektor<double,3> &w)
{

  sr_drona=sr_drona+w;
  srodek=srodek+w;
  for(int i=0; i<12; i++)
  {
    t[i]=t[i]+w;
  }
  gnuplot->erase_shape(nazwa);
  this->rysuj_ksztalt();

  /*sr_drona=sr_drona+w;
  double dzielnik=1000;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    srodek=srodek+dod;
    for(int i=0; i<12; i++)
    {
      t[i]=t[i]+dod;
    }
    usleep(0.0000001);
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
  }*/
}
