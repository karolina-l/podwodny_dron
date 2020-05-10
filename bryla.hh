#ifndef BRYLA
#define BRYLA

#include <cstdlib>
#include <unistd.h>
#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa wirtualna reprezentujaca bryle,
* dziedziczy publicznie po klasie Rysuj
*/
class Bryla:public Rysuj{

protected:
  /*!
  * \brief srodek bryly
  */
  TWektor<double,3> srodek;
  /*!
  * \brief macierz obrotu bryly
  */
  M_obr mobr;
  /*!
  * \brief nazwa bryly nadawana podczas rysowania
  */
  int nazwa;

public:
  /*!
  * \brief Konstruktor obiektu klasy Bryla
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * Metoda domyslnie przypisuje polu "nazwa" wartosc 0
  */
  Bryla(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat): Rysuj(plot), mobr(mat), srodek(sr), nazwa(0){}
  /*!
  * \brief Wirtualny destruktor obiiektów klasy Bryla
  */
  virtual ~Bryla(){}
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za rysowanie bryl
  */
  virtual void rysuj_ksztalt()=0;
};



#endif
