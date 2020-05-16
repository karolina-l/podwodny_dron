#ifndef POWIERZCHNIA
#define POWIERZCHNIA

#include "rysowanie_int.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Powierzchnia: public Rysuj{

public:

  Powierzchnia(drawNS::APIGnuPlot3D*plot): Rysuj(plot){}
  virtual ~Powierzchnia() {}
  virtual void rysuj_ksztalt()=0;

};


#endif
