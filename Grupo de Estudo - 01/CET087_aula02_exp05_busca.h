#include <iostream>

#include "../CET087_aula02_exp04/CET087_aula02_exp04_ordenacao.h"

using namespace std;

class buscaBinaria : private ordenaInsecao {
  public:
    buscaBinaria();
    ~buscaBinaria();
    int setBuscaBinaria( int nElementos, int *vetorValores );

    int getPosicao( int posicao );
    int getValor( int valor );
  private:
    int nEle;
    int *vValores;
    int performBB( int valor, int pos );
};
