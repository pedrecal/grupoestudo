#define N 4096
#include <iostream>
#include <time.h>
using namespace std;
long matrizIJ()
{
	int **mat;
	int i;
	int j;
	int n = 0;
	long soma = 0;
	mat = new int*[N];
	if(mat == NULL)
	{
		cout << "Error" << endl;
		return -1;
	}
	for(i=0;i<N;i++)
	{
		mat[i] = new int[N];
		if(mat[i] == NULL)
		{
			cout << "Error" << endl;
			return -1;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			mat[i][j] = n;
			soma += mat[i][j];
			n++;
		}
	}
	for (i=0;i<N;i++)
		delete[] mat[i];
	delete[] mat;
	return soma;
}

long matrizJI()
{
	int **mat;
	int i;
	int j;
	int n = 0;
	long soma = 0;
	mat = new int*[N];
	if (mat == NULL)
	{
		cout << "Error\n";
		return -1;
	}
	for(i=0;i<N;i++)
	{
		mat[i] = new int[N];
		if (mat[i]==NULL)
		{
			cout << "Error\n";
			return -1;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			mat[i][j] = n;
			n++;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			soma+= mat[j][i];
	}
	for(i=0;i<N;i++)
		delete[] mat[i];
	delete[] mat;
	return soma;
}

long vetor()
{
	int *vet;
	int i;
	int n = 0;
	long soma = 0;
	vet = new int [N * N];
	if(vet==NULL)
	{
		cout << "Error" << endl;
		return -1;
	}
	for(i=0;i<N*N;i++)
	{
		vet[i] = n;
		soma += vet[i];
		n++;
	}
	delete[] vet;
	return soma;
}
int main(  int argc, char *argv[] )
{
        double timeResult = 0.0;
        double startTime = 0.0;
        double endTime = 0.0;
        long funcResult = 0;

        startTime = clock();
        funcResult = matrizIJ();
        endTime = clock();
        timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
        cout << "Soma linha/coluna\nResultado: " << funcResult << "\nTempo: " << timeResult << endl;

	startTime = clock();
	funcResult = matrizJI();
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Soma coluna/linha\nResultado: " << funcResult << "\nTempo: " << timeResult << endl;

	startTime = clock();
	funcResult = vetor();
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Soma vetor\nResultado: " << funcResult << "\nTempo: " << timeResult << endl;

	return 0;
}

