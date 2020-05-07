#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "rozmiar.h"

using namespace std;

template <typename TYP, int ROZM>
class TWektor{
  TYP Twek[ROZM];
public:
  TWektor();
  TWektor(TYP tab[ROZM]);
  const TYP & operator[] (int index) const;
  TYP & operator[] (int index);
  TWektor operator + (const TWektor & W) const;
  TWektor operator += (const TWektor & W);
  TWektor operator - (const TWektor & W) const;
  TYP operator * (const TWektor & W) const;
  TWektor operator * (double l) const;
  TWektor operator / (double l) const;
  bool operator == (const TWektor & W) const;
  bool operator != (const TWektor & W) const;









  operator drawNS::Point3D(){return drawNS::Point3D(Twek[0],Twek[1], Twek[2]);}




  //double dlugosc() const; //modul
};
template <typename TYP, int ROZM>
istream & operator >> (istream & str, TWektor<TYP, ROZMIAR> & W);
template <typename TYP, int ROZM>
ostream & operator << (ostream & str, const TWektor<TYP, ROZMIAR> & W);



#endif
