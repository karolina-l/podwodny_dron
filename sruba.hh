#ifndef SRUBA
#define SRUBA

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "graniastoslup.hh"



using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa Prostopadloscian dziedziczaca publicznie po klasie Bryla
*/
class Sruba: public Graniastoslup{
  /*!
  * \brief srodek drona (potrzebne do obrotow)
  */
protected:
  TWektor<double,3> sr_drona;

public:
  /*!
  * \brief Konstruktor obiektu klasy Graniastoslup
  * \param1 drawNS::APIGnuPlot3D *plot - wskaznik na dany obszar rysowania
  * \param2 TWektor<double,3> sr - wspolrzedne srodka
  * \param3 TMacierzKw<double,3> mat - macierz m_obrotu
  * \param4 TWektor<double,3> *w - tablica wektorow zawieracjacych wspolrzedne wierzcholkow prostopadloscianu
  * Metoda korzysta z konstruktora klasy Bryla
  */
  Sruba(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w, const TWektor<double,3> &sr_dr): Graniastoslup(plot,sr,mat,w), sr_drona(sr_dr){}
  /*!
  * \brief Metoda pozwalajaca na zmiane kata prostopadloscianu wzgledem osi OZ
  * \param1 double kat - kat obrotu
  */
  virtual ~Sruba(){}

  void zmien_kat(double kat) override;
  /*!
  * \brief Metoda pozwalajaca na zmiane polozenia prostopadloscianu
  * \param1 TWektor<double,3> w - wektor zmiany polozenia
  */
  void zmien_polozenie(const TWektor<double,3> &w) override;
  void obrot_sruby();

};



#endif
