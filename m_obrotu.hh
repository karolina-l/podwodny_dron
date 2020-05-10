#ifndef M_OBR
#define M_OBR

#include "matrix.hh"
#include "vector.hh"

/*!
* \brief Klasa reprezentujaca macierz obrotu
*/
class M_obr: public TMacierzKw<double,3>{

public:
  /*!
  * \brief Konstruktor obiektu M_obr
  * \param1 TMacierzKw<double,3> mtx - macierz,
  * na podstawie ktorej tworzona jest M_obr
  *  sprawdza czy dana macierz jest macierza obrotu
  */
  explicit M_obr(const TMacierzKw<double,3> & mtx);
  /*!
  * \brief Konstruktor obiektu M_obr
  *  Konstruktor bezparametryczny, wypelnia obiekt zerami
  */
  M_obr();
  /*!
  * \brief metoda tworzaca M_obr z zadanego kata
  * \param1 double kat - kat, na podstawie ktorego tworzona
  * jest M_obr
  * \return nowy obiekt klasy M_obr 
  */
  M_obr utworz_mRz(const double &kat);
};



#endif
