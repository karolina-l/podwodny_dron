#include <cmath>
#include "m_obrotu.hh"

using namespace std;

M_obr::M_obr(const TMacierzKw<double,3> & mtx): TMacierzKw<double, 3>(mtx)
{
  int flag=0;
  TMacierzKw pom=mtx;

  if(abs(pom.wyznacznik())!=1) flag=-1;

  if(!(pom*pom.transponuj()==pom.transponuj()*pom)) flag=-1;

  if(flag==-1)
  {
    cerr<<"Podana macierz nie jest macierza obrotu"<<endl;
    exit(1);
  }
}
