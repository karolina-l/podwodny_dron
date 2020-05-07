#ifndef RYSUJ_INTERFEJS
#define RYSUJ_INTERFEJS

#include "Dr3D_gnuplot_api.hh"


class Rysuj{

protected:
  std::shared_ptr<drawNS::Draw3DAPI> gnuplot;
public:
  Rysuj(drawNS::Draw3DAPI*plot):gnuplot(plot){}
  virtual  ~Rysuj(){}
  virtual void rysuj_ksztalt()=0;

};



#endif
