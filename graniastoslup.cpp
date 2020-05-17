#include "graniastoslup.hh"
#include "m_obrotu.hh"
#include <math.h>

using namespace std;

  Graniastoslup::Graniastoslup(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w): Bryla(plot, sr, mat)
  {
    for(int i=0; i<12; i++)
    {
      t[i]=w[i];
    }
  }

  void Graniastoslup::rysuj_ksztalt()
  {
    nazwa=gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
    {
      {t[0],t[1],t[2],t[3],t[4],t[5]},
      {t[6],t[7],t[8],t[9],t[10],t[11]}
    },"red");
  //  gnuplot->redraw();
  }

  void Graniastoslup::zmien_kat(double kat)
  {

    M_obr obr;

      obr=obr.utworz_mRz(kat);
      for(int i=0; i<12; i++)
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

      gnuplot->erase_shape(nazwa);
      this->rysuj_ksztalt();
  }




void Graniastoslup::zmien_polozenie(const TWektor<double,3> &w)
{
    srodek=srodek+w;
    for(int i=0; i<12; i++)
    {
      t[i]=t[i]+w;
    }
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
}
