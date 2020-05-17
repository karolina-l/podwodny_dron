#include "dron.hh"
#include "sruba.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*Dron::Dron(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr1, const TWektor<double,3> &sr2, const TWektor<double,3> &srdr, TWektor<double,3> *ws1, TWektor<double,3> *ws2, TWektor<double,3> *wd, const TMacierzKw<double,3> &mat):
Interfejs(plot,srdr,mat,wd)
{
  s1.Sruba(plot, sr1, mat, ws1, srdr);
  s2.Sruba(plot, sr2, mat, ws2, srdr);
}
*/

void Dron::rysuj_ksztalt()
{
  s1.rysuj_ksztalt();
  s2.rysuj_ksztalt();
  nazwa=gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
  {
    {t[0],t[1],t[2],t[3]},
    {t[4],t[5],t[6],t[7]}
  },"red");
}

void Dron::zmien_kat(double kat)
{
  M_obr obr;
  double dzielnik=20;
  double dod=kat/dzielnik;
  for(int wycinek=1; wycinek<=dzielnik; wycinek++)
  {

    s1.Sruba::zmien_kat(dod);
    s2.Sruba::zmien_kat(dod);
    //s1.Sruba::obrot_sruby();
    //s2.Sruba::obrot_sruby();
    M_obr obr;
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
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
    gnuplot->redraw();
    //usleep(0.000000001);

  }
}

void Dron::zmien_polozenie(const TWektor<double,3> &w)
{

  double dzielnik=10;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    s1.Sruba::zmien_polozenie(dod);
    s2.Sruba::zmien_polozenie(dod);
    //s1.Sruba::obrot_sruby();
    //s2.Sruba::obrot_sruby();

    srodek=srodek+dod;
    for(int i=0; i<8; i++)
    {
      t[i]=t[i]+dod;
    }
    gnuplot->erase_shape(nazwa);
    this->rysuj_ksztalt();
    gnuplot->redraw();
  }
}
