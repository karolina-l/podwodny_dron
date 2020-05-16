#include "prostopadloscian.hh"
#include "m_obrotu.hh"
#include <math.h>

using namespace std;
  Prostopadloscian::Prostopadloscian(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w): Bryla(plot, sr, mat)
  {
    for(int i=0; i<8; i++)
    {
      t[i]=w[i];
    }
  }

  void Prostopadloscian::rysuj_ksztalt()
  {
    nazwa=gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
    {
      {t[0],t[1],t[2],t[3]},
      {t[4],t[5],t[6],t[7]}
    },"red");
    gnuplot->redraw();
  }

  void Prostopadloscian::zmien_kat(double kat)
  {

    M_obr obr;
    /*double dod=kat/360;
    for(int j=1; j<=360; j++)
    {
      double nkat=dod*j;
      obr=obr.utworz_mRz(nkat);
      srodek=obr*srodek;

      for(int i=0; i<8; i++)
          {
            t[i]=t[i]-srodek;
          }
          //srodek=nmob*srodek;
          for(int i=0; i<8; i++)
          {
            t[i]=obr*t[i];
          }

          for(int i=0; i<8; i++)
          {
            t[i]=t[i]+srodek;
          }
      //gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();
    }*/
    /*TMacierzKw<double,3> pom;
    pom[0][0]=cos(kat*M_PI/180.0);
    pom[0][1]=sin(kat*M_PI/180.0)*(-1);
    pom[0][2]=0.0;
    pom[1][0]=sin(kat*M_PI/180.0);
    pom[1][1]=cos(kat*M_PI/180.0);
    pom[1][2]=0.0;
    pom[2][0]=0.0;
    pom[2][1]=0.0;
    pom[2][2]=1.0;
    M_obr nmob(pom);*/

    double dzielnik=420;
    double dod=kat/dzielnik;
    for(int wycinek=1; wycinek<=dzielnik; wycinek++)
    {
      obr=obr.utworz_mRz(dod);
      for(int i=0; i<8; i++)
      {
        t[i]=t[i]-srodek;
      }

      for(int i=0; i<8; i++)
      {
        t[i]=obr*t[i];
      }

      for(int i=0; i<8; i++)
      {
        t[i]=t[i]+srodek;
      }

      usleep(0.000000001);

      gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();
    }


  }

void Prostopadloscian::zmien_polozenie(const TWektor<double,3> &w)
{
  double dzielnik=1000;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    srodek=srodek+dod;
    for(int i=0; i<8; i++)
    {
      t[i]=t[i]+dod;
    }
    //if(nazwa!=0)
    usleep(0.0000001);
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
  }
  /*srodek=srodek+w;
  for(int i=0; i<8; i++)
  {
    t[i]=t[i]+w;
  }
  gnuplot->erase_shape(nazwa);
  this->rysuj_ksztalt();*/
}
