#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "sruba.hh"
#include "dron.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Interfejs: public Sruba, public Dron{

Sruba s1;
Sruba s2;
Dron dron;

public:

  Interfejs(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr1, const TWektor<double,3> &sr2, const TWektor<double,3> &srdr, TWektor<double,3> *ws1, TWektor<double,3> *ws2, TWektor<double,3> *wd, const TMacierzKw<double,3> &mat);
  void rysuj_ksztalt() override;
  void zmien_kat(double kat) override;
  void zmien_polozenie(const TWektor<double,3> &w) override;

};

#endif
