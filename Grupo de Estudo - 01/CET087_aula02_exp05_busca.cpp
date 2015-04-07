// g++ -v -O2 -c CET087_aula02_exp05_busca.cpp -o libBusca.o

#include "CET087_aula02_exp05_busca.h"

buscaBinaria::buscaBinaria()
{
  nEle = 0;
}

buscaBinaria::~buscaBinaria()
{
  if ( nEle == 0 )
    delete []vValores;
}

int buscaBinaria::setBuscaBinaria( int nElementos, int *vetorValores )
{
  int i = 0;

  nEle = nElementos;
  vValores = new int[nEle];

  for ( i = 0; i < nEle; i++ )
    vValores[i] = vetorValores[i];

  setOrdenaInsecao( nEle, vValores );

  for ( i = 0; i < nEle; i++ )
    cout << vValores[i] << " ";
  cout << endl;

  return 0;
}

int buscaBinaria::getPosicao( int posicao )
{
  if ( nEle == 0 || posicao >= nEle )
    return -1;
  else
    return vValores[posicao];
}

int buscaBinaria::getValor( int valor )
{
  return performBB( valor, (int)(nEle / 2) );
}

int buscaBinaria::performBB( int valor, int pos )
{
  int newPos = 0;

  if ( pos >= nEle || pos < 0 )
    return -1;
  if ( vValores[pos] == valor )
  {
    return pos;
  }
  else
  {
	 if ( pos >= (nEle-1) || pos == 0 )
		return -1;
	 
    if ( valor > vValores[pos])
    {
      newPos = pos + (int)( (nEle-pos) / 2);
      if ( newPos <= pos )
			return -1;
		else
      	return performBB( valor, newPos );
    }
    else
    {
      newPos = (int)(pos / 2);
      if ( newPos >= pos )
			return -1;
		else
      	return performBB( valor, newPos );
    }
  }
}
