// g++ -O2 CET087_aula02_exp03.cpp -o CET087_aula02_exp03
#include <iostream>

using namespace std;

class ordenaInsecao {
  public:
    ordenaInsecao();
    ~ordenaInsecao();
    int setOrdenaInsecao(int compValores, int *vetorValores );
  private:
    int valorTemp;
};

ordenaInsecao::ordenaInsecao()
{
  valorTemp = 0;
}

ordenaInsecao::~ordenaInsecao()
{
  valorTemp = 0;
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