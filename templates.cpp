#include "vector.cpp"
#include  "matrix.cpp"

using namespace std;


template class TWektor<double,3>;
template istream & operator >> (istream & str, TWektor<double,3> & W);
template ostream & operator << (ostream & str, const TWektor<double, 3> & W);

template class TMacierzKw<double,3>;
template istream & operator >> (istream & str, TMacierzKw<double,3> & M);
template ostream & operator << (ostream & str, const TMacierzKw<double, 3> & M);
