#ifndef DNO
#define DNO

#include "powierzchnia.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

class Dno: public Powierzchnia{

int nazwa;

public:

  Dno(drawNS::APIGnuPlot3D*plot): Powierzchnia(plot), nazwa(0){}

  void rysuj_ksztalt() override;

};

#endif
