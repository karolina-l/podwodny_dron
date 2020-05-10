#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "bryla.hh"



using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Prostopadloscian dziedziczaca publicznie po klasie Bryla
*/
class Prostopadloscian:public Bryla{
  /*!
  * \brief wierzcholki prostopadloscianu
  */
  TWektor<double,3> t[8];

public:
  /*!
  * \brief Konstruktor obiektu klasy Prostopadloscian
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Bryla
  */
  Prostopadloscian(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w);
  /*!
  * \brief Dziedziczona metoda sluzaca do rysowania obiektow
  */
  void rysuj_ksztalt() override;
  /*!
  * \brief Metoda pozwalajaca na zmiane kata prostopadloscianu wzgledem osi OZ
  */
  void zmien_kat(double kat);
  /*!
  * \brief Metoda pozwalajaca na zmiane polozenia prostopadloscianu
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  void zmien_polozenie(const TWektor<double,3> &w);
  /*!
  * \brief Metoda pozwalajaca na zmiane wartosci wierzcholkow prostopadloscianu
  * \param1 TWektor<double,3> wekt - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  */
  void zmien_wierzcholki(const TWektor<double,3> *wekt);
};



#endif
