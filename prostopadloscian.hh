#ifndef PROSTOPADLOSCIAN
#define PROSTOPADLOSCIAN

#include "rysowanie_int.hh"
#include "vector.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


class Prostopadloscian:public Bryla{

protected:
  TWektor<double,3> t[8];

public:

  Prostopadloscian(drawNS::APIGnuPlot3D*plot, TWektor<double,3>*wierzcholki): Bryla(plot)
  {
    for(int i=0; i<8; i++)
    {
      tablica[i]=wierzcholki[i];
    }
  }
  virtual ~Bryla(){}
  /*void rysuj_ksztalt()
  {
    gnuplot->draw_polyhedron (vector<vector<drawNS::Point3D>>
    {
      {
        tablica[0],tablica[1],tablica[2],tablica[3]},{tablica[4],tablica[5],tablica[6],tablica[7]}},"blue");
  }*/
    //moze nie musi byc



};



#endif
