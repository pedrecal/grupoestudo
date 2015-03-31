// g++ -v -O2 CET087_aula02_exp05.cpp libBusca.o ../CET087_aula02_exp04/libOrdenacao.o -o CET087_aula02_exp05

#include "CET087_aula02_exp05_busca.h"

int main(  int argc, char *argv[] )
{
  int i = 0;
  const int nElementos = 5;
  int vetorValores[nElementos] = { 5, 3, 7, 1, 4 };
  int Posicao = 3;
  int Valor = 3;

  for ( i = 0; i < nElementos; i++ )
    cout << vetorValores[i] << " ";
  cout << endl;

  buscaBinaria MyBuscaBinaria;

  MyBuscaBinaria.setBuscaBinaria( nElementos, vetorValores );

  cout << "Valor da Posição " << Posicao << " : " << MyBuscaBinaria.getPosicao( Posicao ) << endl;
  cout << "Posição do Valor " << Valor << " : " << MyBuscaBinaria.getValor( Valor ) << endl;

  return 0;
}