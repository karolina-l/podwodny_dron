#include "vector.cpp"

using namespace std;


template class TWektor<double,3>;
template istream & operator >> (istream & str, TWektor<double,3> & W);
template ostream & operator << (ostream & str, const TWektor<double, 3> & W);
