#ifndef INTERFEJS_DRONA
#define INTERFEJS_DRONA

#include "rysowanie_int.hh"
#include "vector.hh"
#include "m_obrotu.hh"
#include "prostopadloscian.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Interfejs: public Prostopadloscian{

public:

Interfejs(drawNS::APIGnuPlot3D*plot, const TWektor<double,3> &sr, const TMacierzKw<double,3> &mat, TWektor<double,3>*w):Prostopadloscian(plot,sr,mat,w){}

virtual ~Interfejs(){};

};

#endif
