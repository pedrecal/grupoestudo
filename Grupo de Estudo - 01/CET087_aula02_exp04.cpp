// g++ -O2 CET087_aula02_exp04.cpp libOrdenacao.o -o CET087_aula02_exp04

#include "CET087_aula02_exp04_ordenacao.h"

int main(  int argc, char *argv[] )
{
  int i = 0;
  const int nElementos = 5;
  int vetorValores[nElementos] = { 5, 3, 7, 1, 4 };

  for ( i = 0; i < nElementos; i++ )
    cout << vetorValores[i] << " ";
  cout << endl;

  ordenaInsecao MyOrdenaInsercao;

  MyOrdenaInsercao.setOrdenaInsecao( nElementos, vetorValores );

  for ( i = 0; i < nElementos; i++ )
    cout << vetorValores[i] << " ";
  cout << endl;

  return 0;
}