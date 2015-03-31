// g++ -v -O2 -c CET087_aula02_exp04_ordenacao.cpp -o libOrdenacao.o

#include "CET087_aula02_exp04_ordenacao.h"

ordenaInsecao::ordenaInsecao()
{
}

ordenaInsecao::~ordenaInsecao()
{
}

int ordenaInsecao::setOrdenaInsecao(int nElementos, int *vetorValores )
{
  int i = 0;
  int j = 0;
  int tmp = 0;

  for ( i = 1; i < nElementos; i++ )
  {
    for ( j = i; j >= 1; j-- )
    {
      if ( vetorValores[j] < vetorValores[j-1] )
      {
	tmp = vetorValores[j-1];
	vetorValores[j-1] = vetorValores[j];
	vetorValores[j] = tmp;
      }
    }
  }
  return 0;
}
