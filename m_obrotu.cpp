#include <cmath>
#include "m_obrotu.hh"

using namespace std;

M_obr::M_obr(const TMacierzKw<double,3> & mtx): TMacierzKw<double, 3>(mtx)
{
  double blad=0.0001;
  int flag=0;
  TMacierzKw pom=mtx;

  if(abs(pom.wyznacznik()-1)>blad) flag=-1;

  if(!(pom*pom.transponuj()==pom.transponuj()*pom)) flag=-1;

  if(flag==-1)
  {
    cerr<<"Podana macierz nie jest macierza obrotu"<<endl;
    exit(1);
  }
}

M_obr::M_obr()
{
  for(int i=0; i<ROZMIAR; i++)
  {
    mtx[i]=TWektor<double,3>();
  }
}

M_obr M_obr::utworz_mRz(const double &kat)
{
  TMacierzKw<double,3> pom;
  pom[0][0]=cos(kat*M_PI/180.0);
  pom[0][1]=sin(kat*M_PI/180.0)*(-1);
  pom[0][2]=0.0;
  pom[1][0]=sin(kat*M_PI/180.0);
  pom[1][1]=cos(kat*M_PI/180.0);
  pom[1][2]=0.0;
  pom[2][0]=0.0;
  pom[2][1]=0.0;
  pom[2][2]=1.0;
  M_obr nmob(pom); // czy jest M obr?

  return nmob;
}
