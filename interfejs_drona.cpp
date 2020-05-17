#include "interfejs_drona.hh"

//using namespace std;

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

Interfejs::Interfejs(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr1, const TWektor<double,3> &sr2, const TWektor<double,3> &srdr, TWektor<double,3> *ws1, TWektor<double,3> *ws2, TWektor<double,3> *wd, const TMacierzKw<double,3> &mat)
{
/*  Sruba *s1=new Sruba(plot, sr1, mat, ws1, srdr);
  Sruba *s2 = new Sruba(plot, sr2, mat, ws2, srdr);
  Dron *dron = new Dron(plot, srdr, mat, wd);*/
  s1(plot, sr1, mat, ws1, srdr);
  s2(plot, sr2, mat, ws2, srdr);
  dron(plot, srdr, mat, wd);
}

void Interfejs::rysuj_ksztalt()
{
  dron.Dron::rysuj_ksztalt();
  s1.Sruba::rysuj_ksztalt();
  s2.Sruba::rysuj_ksztalt();
  gnuplot->redraw();
}

void Interfejs::zmien_kat(double kat)
{
  M_obr obr;
  double dzielnik=420;
  double dod=kat/dzielnik;
  for(int wycinek=1; wycinek<=dzielnik; wycinek++)
  {
    s1.Sruba::zmien_kat(dod);
    s2.Sruba::zmien_kat(dod);
    s1.Sruba::obrot_sruby();
    s2.Sruba::obrot_sruby();
    dron.Prostopadloscian::zmien_kat(dod);

    usleep(0.000000001);
    gnuplot->redraw();
  }

}

void Interfejs::zmien_polozenie(const TWektor<double,3> &w)
{

  double dzielnik=1000;
  TWektor<double,3> dod;
  dod=w/dzielnik;
  for(int j=1; j<=dzielnik; j++)
  {
    s1.Sruba::zmien_polozenie(dod);
    s2.Sruba::zmien_polozenie(dod);
    s1.Sruba::obrot_sruby();
    s2.Sruba::obrot_sruby();
    dron.Prostopadloscian::zmien_polozenie(dod);
  }
}
