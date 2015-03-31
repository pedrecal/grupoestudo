// g++ CET087_aula02_exp01.cpp -o CET087_aula02_exp01

// g++ -O2 CET087_aula02_exp01.cpp -o CET087_aula02_exp01

#include <stdio.h>
#include <time.h>

int loopTest01( int x )
{
	int i = 0;
	int *vTemp;
	int result = 0;

	vTemp = new int[x];
	for ( i = 0; i < x; i++ )
		vTemp[i] = i;
	for ( i = 0; i < x; i++ )
		result += vTemp[i];
	delete []vTemp;
	return result;
}

int main(  int argc, char *argv[] )
{
	double timeResult = 0.0;
	double startTime = 0.0;
	double endTime = 0.0;
	int funcResult = 0;
	const int nCycles = 100000000;

	startTime = clock();
	funcResult = loopTest01( nCycles );
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	printf( "loopTest01 -> Função: %i \t Duração: %f\n", funcResult, timeResult );
	return 0;
}
