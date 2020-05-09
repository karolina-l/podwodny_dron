#include "matrix.hh"
#include <cmath>

/*
  Komstruktor klasy TMacierzKw;
  tworzy MacierzKw, której elementy
  sa rowne 0.0
*/
template <typename TYP, int ROZM>
TMacierzKw<TYP,ROZM>:: TMacierzKw()
{
  for (int i=0; i<ROZMIAR; i++)
  {
    mtx[i]=TWektor<TYP,ROZM>();
  }
}

/*
  Konstruktor klasy TMacierzKw;
  tworzy MacierzKw, ktorego elementy maja wartosc
  rowna elementom danej tablicy tab
*/
template <typename TYP, int ROZM>
TMacierzKw<TYP,ROZM>:: TMacierzKw(const TWektor<TYP,ROZM> tab[ROZMIAR])
{
  for(int i=0; i<ROZMIAR; i++)
  {
      mtx[i]=tab[i];
  }
}

template <typename TYP, int ROZM>
bool TMacierzKw<TYP, ROZM>::operator == (const TMacierzKw<TYP, ROZM> & M) const
{
  int licznik=0;
  double eps=0.00000001;
  for(int i=0; i<ROZMIAR; i++)
  {
    for(int j; j<ROZMIAR; j++)
    {
      if(abs(M[i][j]-mtx[i][j])>eps)
      {
        licznik++;
      }
    }
  }

  if(licznik==ROZMIAR) return false;
  else return true;

}

  /*
    Przeciazenie operatora "[]"
    zwraca indeks obecnego elementu macierzy
    lub zwraca komunikat: "indeks poza zakresem"
    i konczy dzialanie programu, by uchronic
    przed naruszeniem pamieci
  */
template <typename TYP, int ROZM>
const TWektor<TYP,ROZM> & TMacierzKw<TYP,ROZM>:: operator[] (int index) const
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return mtx[index];
  }
}

/*
  Przeciazenie operatora "[]"
  zwraca indeks obecnego elementu macierzy
  lub zwraca komunikat: "indeks poza zakresem"
  i konczy dzialanie programu, by uchronic
  przed naruszeniem pamieci
*/
template <typename TYP, int ROZM>
TWektor<TYP,ROZM> & TMacierzKw<TYP,ROZM>::operator[] (int index)
{
  if (index < 0 || index > ROZMIAR)
  {
    cerr << "indeks poza zakresem" << endl;
    exit(1);
  }
  else
  {
    return mtx[index];
  }
}


/*
  Przeciazenie operatora "+"
  argumenty to 2 macierze
  zwraca nową macierz, ktorej elementy sa
  suma poszczegolnych elementow macierzy skladowych
*/
template <typename TYP, int ROZM>
const TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>:: operator + (const TMacierzKw<TYP,ROZM> & M)
{
  TWektor<TYP,ROZM> W[ROZMIAR];
    for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
        W[i][j]=mtx[i][j]+M[i][j];
    }
  }
  return(TMacierzKw(W));
}

/*
  Przeciazenie operatora "-"
  argumenty to 2 macierze
  zwraca nową macierz, ktorej elementy sa
  roznica poszczegolnych elementow macierzy skladowych
*/
template <typename TYP, int ROZM>
const TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>:: operator - (const TMacierzKw<TYP,ROZM> & M)
{
  TWektor<TYP,ROZM> W[ROZMIAR];
  //TMacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
        W[i][j]=mtx[i][j]-M[i][j];
    }
  }
  return(TMacierzKw(W));
}

/*
  Przeciazenie operatora "*"
  argumenty to 2 macierze
  zwraca nową macierz, ktorej elementy sa
  iloczynem poszczegolnych elementow macierzy skladowych
*/
template <typename TYP, int ROZM>
const TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>::  operator * (const TMacierzKw<TYP,ROZM> & M)
{
  TMacierzKw MA=M.transponuj();
  TMacierzKw(w);

  for (int i=0; i<ROZMIAR; i++)
  {
    for(int k=0; k<ROZMIAR; k++)
    {
      for(int j=0; j<ROZMIAR; j++)
      {
        w[i][k]+=mtx[i][j]*MA[k][j];
      }
    }
  }
  return w;
}

/*
  Przeciazenie operatora "*"
  argumenty to macierz i wektor
  zwraca nowy wektor, ktorego elementy sa
  iloczynem poszczegolnych elementow wektora i macierzy skladowej
*/
template <typename TYP, int ROZM>
const TWektor<TYP,ROZM> TMacierzKw<TYP,ROZM>::operator * (const TWektor<TYP,ROZM> & W)
{
  TMacierzKw MA=*this;
  TWektor<TYP,ROZM> wyn;
  for (int i=0; i<ROZMIAR; i++)
  {
    for (int j=0; j<ROZMIAR; j++)
    {
      wyn[i]+=MA[i][j]*W[j];
    }
  }
  return(wyn);
}

/*
  Przeciazenie operatora "*"
  argumenty to macierz i double
  zwraca nowa macierz, ktorej elementy sa
  iloczynem poszczegolnych elementow macierzy skladowej
  i liczby l
*/
template <typename TYP, int ROZM>
const TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>::  operator * (double l)
{
  TWektor<TYP,ROZM> w[ROZMIAR];
  for (int i=0; i<ROZMIAR; i++)
  {
    w[i]=mtx[i]*l;
  }
  return(TMacierzKw(w));
}

/*
  metoda odwroc zwraca nowa macierz
  odwrotna do danej
*/
/*template <typename TYP, int ROZM>
TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>::odwroc() const
{
 TMacierzKw pom=*this;
 TWektor<TYP,ROZM> W[ROZMIAR], M[ROZMIAR];
 int licznik=0;
 for(int i=0; i<ROZMIAR; i++)
 {
   for (int j=0; j<ROZMIAR; j++)
   {
     if(i==j)
     W[i][j]=1;
     else
     W[i][j]=0;
   }
 }
 for(int i=0; i<ROZMIAR; i++)
 {
   for (int j=0; j<ROZMIAR; j++)
   {
     M[i][j]=pom[i][j];
   }
 }
 while(licznik<ROZMIAR)
 {
   W[0]=W[0]/M[0][licznik];
   M[0]=M[0]/M[0][licznik];

   for(int i=1; i<ROZMIAR; i++)
   {
     W[i]=W[i]-(W[0]*M[i][licznik]);
     M[i]=M[i]-(M[0]*M[i][licznik]);
   }
   licznik++;
   TWektor<TYP,ROZM>  buf;
   for(int x=0; x<ROZMIAR; x++)
   {
     if(x==0)
     buf=M[x];
     if(x!=(ROZMIAR-1))
     {
       M[x]= M[x+1];
     }
     else
     {
       M[x]= buf;
     }
   }
   for(int x=0; x<ROZMIAR; x++)
   {
     if(x==0)
     buf=W[x];
     if(x!=(ROZMIAR-1))
     {
       W[x]= W[x+1];
     }
     else
     {
       W[x]= buf;
     }
   }
 }

 return TMacierzKw(W);
}*/

/*
  metoda zwroc_kolumne zwraca wektor,
  rowny i-tej kolumnie macierzy
  na podstawie przekazanego nr indeksu
*/
template <typename TYP, int ROZM>
TWektor<TYP,ROZM> TMacierzKw<TYP,ROZM>:: zwroc_kolumne(int ind)
{
  TYP zwr[ROZMIAR];
  for (int i=0; i<ROZMIAR; i++)
  {
    zwr[i]=mtx[i][ind];
  }
  return TWektor<TYP,ROZM>(zwr);
}

/*
  metoda zmien_kolumne
  zmienia i-ta kolumne macierzy na dany wektor
  na podstawie przekazanego nr indeksu
*/
template <typename TYP, int ROZM>
void TMacierzKw<TYP,ROZM>::zmien_kolumne(int ind, TWektor<TYP,ROZM> W)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    mtx[i][ind]=W[i];
  }
}

/*
metoda wyznacznik zwraca liczbe double,
ktora jest wyznacznikiem danej miacierzy
*/
template <typename TYP, int ROZM>
TYP TMacierzKw<TYP,ROZM>:: wyznacznik() const
{
  TMacierzKw pom=*this;
  TYP mnoz, wyn; //kiedys LZespolona
  //mnoz=1.0;
  wyn=1.0;//kiedys LZespolona
  double eps=0.000000001;
  int w, k, i, x, licznik;
  licznik=0;
  for (k=0; k<ROZMIAR-1; k++)
  {

      for (w=k+1; w<ROZMIAR; w++)
      {
        if(pom[k][k]>eps || pom[k][k]*(-1.0)>eps)
        {
          mnoz=pom[w][k]/pom[k][k];
          for(x=k; x<ROZMIAR; x++)
          {
            pom[w][x]=pom[w][x]-(pom[k][x]*mnoz);

          }
        }

      else
      {
        for(i=k+1; i<ROZMIAR; i++)
        {
          if(pom[i][k]>eps || pom[i][k]*(-1.0)>eps)
          {
            TWektor<TYP,ROZM> buf;
            buf=pom[k];
            pom[k]=pom[i];
            pom[i]=buf;
            licznik++;
            i=ROZMIAR;
          }
        }
      }
    }
  }

 for(int j=0; j<ROZMIAR; j++)
  {
    wyn=wyn*pom[j][j];
    if(licznik%2!=0)
    wyn=wyn*(-1.0);
  }

  return wyn;
}

/*
  metoda transponuj zwraca nowa macierz
  ktorej kolumny zamienione zostaly z wierszami
  wzgledem danej macierzy
*/
template <typename TYP, int ROZM>
TMacierzKw<TYP,ROZM> TMacierzKw<TYP,ROZM>::transponuj() const
{
  TWektor<TYP,ROZM> W[ROZMIAR];
  TMacierzKw pom=*this;
  for (int i=0; i<ROZMIAR; i++)
  {
    W[i]=pom.zwroc_kolumne(i);
  }
  return(TMacierzKw(W));
}

/*
  Przeciazenie operatora ">>"
  dla klasy TMacierzKw
  zwraca strumien przesuniecia bitowego w prawo
*/
template <typename TYP, int ROZM>
istream & operator >> (istream &str, TMacierzKw<TYP,ROZM> &M)
{
  TWektor<TYP,ROZM> W;
  for (int i=0; i<ROZMIAR; i++)
  {
    str >> W;
    M[i]=W;
  }
  return str;
}

/*
  Przeciazenie operatora "<<"
  dla klasy TMacierzKw
  zwraca strumien przesuniecia bitowego w prawo
*/
template <typename TYP, int ROZM>
ostream & operator << (ostream &str, const TMacierzKw<TYP,ROZM> &M)
{
  for (int i=0; i<ROZMIAR; i++)
  {
    str << M[i];
    if(i!= (ROZMIAR-1))
    str << endl;
  }
  return str;
}
