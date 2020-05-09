#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "vector.hh"
#include <iostream>

using namespace std;

/*
  Klasa TMacierzKw:
   zawiera:
   - pole mtx - tablica wektorow,
     rozmiar zadany zewnetrznie
   - konstruktory elementow klasy TMacierzKw
   - przeciazenia operatorow klasy TMacierzKw
   - metode zwroc_kolumne(), zmien_kolumne(),
     odwroc(), wyznacznik(), transponuj()
*/

//reprezentacja wierszowa
template <typename TYP, int ROZM>
class TMacierzKw  {

protected:
  TWektor<TYP, ROZM> mtx[ROZMIAR];

  public:
  TMacierzKw();
  TMacierzKw(const TWektor<TYP,ROZM>  tab[ROZMIAR]);
  const TWektor<TYP, ROZM> & operator[] (int index) const;
  TWektor<TYP, ROZM> & operator[] (int index);
  const TMacierzKw  operator + (const TMacierzKw & M);
  const TMacierzKw  operator - (const TMacierzKw & M);
  const TMacierzKw  operator * (const TMacierzKw & M);
  const TWektor<TYP, ROZM> operator * (const TWektor<TYP, ROZM> & W);
  const TMacierzKw  operator * (double l);
  bool operator == (const TMacierzKw & M) const;
  //TMacierzKw  odwroc() const;
  TWektor<TYP, ROZM>  zwroc_kolumne(int ind); //dla interpretacji wierszowej
  void zmien_kolumne(int ind, TWektor<TYP, ROZM> W); //dla interpretacji wierszowej
  TYP wyznacznik()const;
  TMacierzKw transponuj() const;
};


template <typename TYP, int ROZM>
istream & operator >> (istream &str, TMacierzKw<TYP, ROZM> &M);

template <typename TYP, int ROZM>
ostream & operator << (ostream &str, const TMacierzKw<TYP, ROZM> &M);

#endif
