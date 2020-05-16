#include "sruba.hh"
#include "m_obrotu.hh"
#include <math.h>

using namespace std;

void Sruba::obrot_sruby()
{
  M_obr obr;
    for(int i=0; i<360; i++)
  {
    obr=obr.utworz_mRz(1);
    for(int j=0; i<12; j++)
    {
      t[i]=t[i]-srodek;
    }

    for(int i=0; i<12; i++)
    {
      t[i]=obr*t[i];
    }

    for(int i=0; i<12; i++)
    {
      t[i]=t[i]+srodek;
    }

    usleep(0.000000001);

    //gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
  }
  void Graniastoslup::zmien_kat(double kat)
  {

    M_obr obr;
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


  }

void Graniastoslup::zmien_polozenie(const TWektor<double,3> &w)
{
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
    //if(nazwa!=0)
    usleep(0.0000001);
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
  }
}

}
