#ifndef DRON
#define DRON

#include <iostream>
#include "interfejs_drona.hh"
#include "rysowanie_int.hh"
#include "sruba.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Dron: public Interfejs{

  Sruba s1;
  Sruba s2;

public:
  /*!
  * \brief Konstruktor obiektu klasy Prostopadloscian
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Bryla
  */
  Dron(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr1, const TWektor<double,3> &sr2, const TWektor<double,3> &srdr, TWektor<double,3> *ws1, TWektor<double,3> *ws2, TWektor<double,3> *wd, const TMacierzKw<double,3> &mat): Interfejs(plot,srdr,mat,wd), s1(plot, sr1, mat, ws1, srdr), s2(plot, sr2, mat, ws2, srdr){}
  /*!
  * \brief Metoda pozwalajaca na zmiane kata prostopadloscianu wzgledem osi OZ
  * \param1 double kat - kat obrotu
  */
  virtual ~Dron(){}
  void rysuj_ksztalt() override;
  void zmien_kat(double kat) override;
  /*!
  * \brief Metoda pozwalajaca na zmiane polozenia prostopadloscianu
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  void zmien_polozenie(const TWektor<double,3> &w) override;

};


#endif
