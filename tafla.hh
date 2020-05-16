#ifndef TAFLA
#define TAFLA

#include "powierzchnia.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Tafla: public Powierzchnia{

int nazwa;

public:

  Tafla(drawNS::APIGnuPlot3D*plot): Powierzchnia(plot), nazwa(0){}

  void rysuj_ksztalt() override;

};

#endif
