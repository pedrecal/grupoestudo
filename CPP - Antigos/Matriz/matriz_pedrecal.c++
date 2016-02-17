#include <iostream>
#include <time.h>
using namespace std;

const int w = 4096;

long matrizlinha()
{
	int **m = new int*[w];
	int z = 0;
	long s = 0;

	if (m == NULL)
	{
		cout << "Error!!";
		return -1;
	}

	for (int i = 0; i < w; ++i)
	{
		m[i] = new int[w];
		if (m[i] == NULL)
		{
			cout << "Error!";
			return -1;
		}
	}
	
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			m[i][j] = z;
			z++;
			s += m[i][j];
		}
	}

	/*for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << m[i][j]<<"\t";
		}
		cout << "\n";
	}
	cout << s;
	cout << "\n";*/

	for (int i=0;i<w;i++)
	{
		delete[] m[i];
	}
	delete[] m;

	return s;
}

long matrizcoluna()
{
	int **m = new int*[w];
	int z = 0;
	long s = 0;

	if (m == NULL)
	{
		cout << "Error!!";
		return -1;
	}

	for (int i = 0; i < w; ++i)
	{
		m[i] = new int[w];
		if (m[i] == NULL)
		{
			cout << "Error!";
			return -1;
		}
	}
	
	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			m[i][j] = z;
			z++;
		}
	}

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			s += m[j][i];
		}
	}
	/*for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cout << m[i][j]<<"\t";
		}
		cout << "\n";
	}
	cout << s;
	cout << "\n";*/

	for (int i=0;i<w;i++)
	{
		delete[] m[i];
	}
	delete[] m;

	return s;
}

int main(  int argc, char *argv[] )
{
    double timeResult1 = 0.0;
    double timeResult2 = 0.0;
    double startTime = 0.0;
    double endTime = 0.0;
    long funcResult = 0;

    startTime = clock();
    funcResult = matrizlinha();
    endTime = clock();
    timeResult1 = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
    cout << "Soma pela linha\nResultado: " << funcResult << "\nTempo: " << timeResult1 << endl;

	startTime = clock();
	funcResult = matrizcoluna();
	endTime = clock();
	timeResult2 = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	cout << "Soma pela coluna\nResultado: " << funcResult << "\nTempo: " << timeResult2 << endl;

	cout << "Diferença: " << timeResult2-timeResult1 << endl;

	return 0;
}