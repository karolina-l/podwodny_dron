#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "vector.hh"
#include <iostream>

using namespace std;

/*!
* \brief Klasa i szablon reprezentujaca obiekt TMacierzKw
*/

//reprezentacja wierszowa
template <typename TYP, int ROZM>
class TMacierzKw  {

protected:
  /*!
  * \brief macierz zadabego typu i rozmiaru
  */
  TWektor<TYP, ROZM> mtx[ROZMIAR];

  public:
  /*!
  * \brief Konstruktor klasy TMacierzKw
  */
  TMacierzKw();
  /*!
  * \brief Konstruktor klasy TMacierzKw
  * \param1 TWektor<TYP,ROZM> tab[ROZMIAR] - wektor zadanego typu i rozmiaru
  */
  TMacierzKw(const TWektor<TYP,ROZM>  tab[ROZMIAR]);
  /*!
  * \brief Przeciazenie operatora []
  * \param1 int index - indeks danego skladnika
  * \return zwraca obecny indeks
  */
  const TWektor<TYP, ROZM> & operator[] (int index) const;
  /*!
  * \brief Przeciazenie operatora []
  * \param1 int index - indeks danego skladnika
  * \return zwraca obecny indeks
  */
  TWektor<TYP, ROZM> & operator[] (int index);
  /*!
  * \brief Przeciazenie operatora +
  * \param1 TMacierzKw M - macierz zadanego typu i rozmiaru
  * \return zwraca nowa macierz
  */
  const TMacierzKw  operator + (const TMacierzKw & M);
  /*!
  * \brief Przeciazenie operatora +
  * \param1 TMacierzKw M - macierz zadanego typu i rozmiaru
  * \return zwraca nowa macierz
  */
  const TMacierzKw  operator - (const TMacierzKw & M);
  /*!
  * \brief Przeciazenie operatora -
  * \param1 TMacierzKw M - macierz zadanego typu i rozmiaru
  * \return zwraca nowa macierz
  */
  const TMacierzKw  operator * (const TMacierzKw & M);
  /*!
  * \brief Przeciazenie operatora *
  * \param1 TWektor W - wektor zadanego typu i rozmiaru
  * \return zwraca nowa macierz
  */
  const TWektor<TYP, ROZM> operator * (const TWektor<TYP, ROZM> & W);
  /*!
  * \brief Przeciazenie operatora *
  * \param1 double l - liczba, przez ktora bedzie sie mnozyc
  * \return zwraca nowa macierz
  */
  const TMacierzKw  operator * (double l);
  /*!
  * \brief Przeciazenie operatora ==
  * \param1 TMacierzKw M - macierz zadanego typu i rozmiaru
  * \return true jesli macierze sa rowne i false gdy sa rozne
  */
  bool operator == (const TMacierzKw & M) const;
  //TMacierzKw  odwroc() const;
  /*!
  * \brief metoda zwraca kolumne macierzy o danym indeksie
  * \param1 int ind - indeks kolumny
  * \return zadana kolumna
  */
  TWektor<TYP, ROZM>  zwroc_kolumne(int ind); //dla interpretacji wierszowej
  /*!
  * \brief metoda zmienia wartosci danej kolumny na inne
  * \param1 int ind - indeks kolumny
  * \param2 TWektor<TYP, ROZM> W - wektor danego typu i rozmiaru
  */
  void zmien_kolumne(int ind, TWektor<TYP, ROZM> W); //dla interpretacji wierszowej
  /*!
  * \brief metoda oblicza wyznacznik danej miacierzy
  * \return wyznacznik macierzy danego typu
  */
  TYP wyznacznik()const;
  /*!
  * \brief metoda transponuje dana macierz
  * \return macierz po transpozycji
  */
  TMacierzKw transponuj() const;
};

/*!
* \brief przeciazenie operatora >>
* \param1 istream str - strumien wejsciowy
* \param2 TMacierzKw<TYP, ROZM> M - macierz danego typu i rozmiaru
* \return zwraca strumien wejsciowy
*/
template <typename TYP, int ROZM>
istream & operator >> (istream &str, TMacierzKw<TYP, ROZM> &M);
/*!
* \brief przeciazenie operatora <<
* \param1 ostream str - strumien wyjsciowy
* \param2 TMacierzKw<TYP, ROZM> M - macierz danego typu i rozmiaru
* \return zwraca strumien wyjsciowy
*/
template <typename TYP, int ROZM>
ostream & operator << (ostream &str, const TMacierzKw<TYP, ROZM> &M);

#endif
