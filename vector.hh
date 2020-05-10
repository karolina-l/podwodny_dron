#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "rozmiar.h"
#include "Dr3D_gnuplot_api.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*!
* \brief Klasa i szablon reprezentujaca obiekt TWektor
*/
template <typename TYP, int ROZM>
class TWektor{
  /*!
  * \brief wektor zadabego typu i rozmiaru
  */
  TYP Twek[ROZM];
public:
  /*!
  * \brief Konstruktor klasy TWektor
  */
  TWektor();
  /*!
  * \brief Konstruktor klasy TWektor
  * \param1 TYP tab[ROZM] - tablica danych zadanego typu i rozmiaru
  */
  TWektor(TYP tab[ROZM]);
  /*!
  * \brief Przeciazenie operatora []
  * \param1 int index - indeks danego skladnika
  * \return zwraca obecny indeks
  */
  const TYP & operator[] (int index) const;
  /*!
  * \brief Przeciazenie operatora []
  * \param1 int index - indeks danego skladnika
  * \return zwraca obecny indeks
  */
  TYP & operator[] (int index);
  /*!
  * \brief Przeciazenie operatora +
  * \param1 TWektor W- wektor zadanego typu i rozmiaru
  * \return zwraca nowy wektor
  */
  TWektor operator + (const TWektor & W) const;
  /*!
  * \brief Przeciazenie operatora +=
  * \param1 TWektor W- wektor zadanego typu i rozmiaru
  * \return zwraca nowy wektor
  */
  TWektor operator += (const TWektor & W);
  /*!
  * \brief Przeciazenie operatora -
  * \param1 TWektor W- wektor zadanego typu i rozmiaru
  * \return zwraca nowy wektor
  */
  TWektor operator - (const TWektor & W) const;
  /*!
  * \brief Przeciazenie operatora *
  * \param1 TWektor W- wektor zadanego typu i rozmiaru
  * \return wynik mnozenia danego typu
  */
  TYP operator * (const TWektor & W) const;
  /*!
  * \brief Przeciazenie operatora *
  * \param1 double l - liczba, przez ktora bedzie sie mnozyc
  * \return zwraca nowy wektor
  */
  TWektor operator * (double l) const;
  /*!
  * \brief Przeciazenie operatora /
  * \param1 double l - liczba, przez ktora bedzie sie dzielic
  * \return zwraca nowy wektor
  */
  TWektor operator / (double l) const;
  /*!
  * \brief Przeciazenie operatora ==
  * \param1 TWektor W - wektor zadanego typu i rozmiaru
  * \return true jesli wektory sa rowne i false gdy sa rozne
  */
  bool operator == (const TWektor & W) const;
  /*!
  * \brief Przeciazenie operatora !=
  * \param1 TWektor W - wektor zadanego typu i rozmiaru
  * \return false jesli wektory sa rowne i true gdy sa rozne
  */
  bool operator != (const TWektor & W) const;









  operator drawNS::Point3D(){return drawNS::Point3D(Twek[0],Twek[1], Twek[2]);}




  //double dlugosc() const; //modul
};
template <typename TYP, int ROZM>
istream & operator >> (istream & str, TWektor<TYP, ROZMIAR> & W);
template <typename TYP, int ROZM>
ostream & operator << (ostream & str, const TWektor<TYP, ROZMIAR> & W);



#endif
