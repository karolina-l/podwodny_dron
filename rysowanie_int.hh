#ifndef RYSUJ_INTERFEJS
#define RYSUJ_INTERFEJS

#include "Dr3D_gnuplot_api.hh"

/*!
* \brief Klasa reprezentujaca obiekt Rysuj
*/
class Rysuj{
protected:
  /*!
  * \brief wskaznik na dane pole rysowania
  */
  std::shared_ptr<drawNS::Draw3DAPI> gnuplot;
public:
  /*!
  * \brief Konstruktor klasy Rysuj
  * \param1 drawNS::Draw3DAPI *plot - wskaznik na dane pole rysowania
  */
  Rysuj(drawNS::Draw3DAPI*plot):gnuplot(plot){}
  /*!
  * \brief wirtualny destruktor klasy Rysuj
  */
  virtual  ~Rysuj(){}
  /*!
  * \brief Naglowek wirtualnej metody odpowiadajacej za rysowanie bryl
  */
  virtual void rysuj_ksztalt()=0;

};



#endif
