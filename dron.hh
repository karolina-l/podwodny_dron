#ifndef DRON
#define DRON

#include <iostream>
#include "prostopadloscian.hh"
#include "rysowanie_int.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/////////// KLASA NIEDOKONCZONA, WSZYSTKIE POTRZEBNE RZECZY W "PROSTOPADLOSCIAN.HH"
class Dron: public Prostopadloscian{

public:
  Dron(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w): Prostopadloscian(plot, sr,mat,w)


}


#enfif
