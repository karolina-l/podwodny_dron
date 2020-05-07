#include <iostream>
#include "bryla.hh"
#include "vector.hh"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != 'a');
}

int main()
{
  TWektor<double,3> tab[8];

  for(int i=0; i<8; i++)
  {
    std::cin>>tab[i];
  }


  drawNS::APIGnuPlot3D *wsk=new drawNS::APIGnuPlot3D(-5,5,-5,5,-5,5,1000);
  Bryla p(wsk,tab);
  p.rysuj_ksztalt();
  wait4key();


return 0;
}
