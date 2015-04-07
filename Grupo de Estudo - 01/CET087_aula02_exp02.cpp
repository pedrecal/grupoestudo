// g++ CET087_aula02_exp02.cpp -o CET087_aula02_exp02 && CET087_aula02_exp02

// g++ -v -O2 CET087_aula02_exp02.cpp -o CET087_aula02_exp02 && CET087_aula02_exp02

// g++ -v -O2 -msse2 CET087_aula02_exp02.cpp -o CET087_aula02_exp02 && CET087_aula02_exp02

// g++ -v -O2 -msse2 -ftree-vectorize -ftree-vectorizer-verbose=3 CET087_aula02_exp02.cpp
//        -o CET087_aula02_exp02 && CET087_aula02_exp02

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

int loopTest02( int x )
{
	int i = 0;
	int *vTemp;
	int *vTempPtr;
	int result = 0;

	vTemp = new int[x];
	vTempPtr = new int[x];
	vTempPtr = &vTemp[0];

	for ( i = 0; i < x; i++ )
		*vTempPtr++ = i;

	vTempPtr = &vTemp[0];
	for ( i = 0; i < x; i++ )
		result += *vTempPtr++;

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

	startTime = clock();
	funcResult = loopTest02( nCycles );
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
	printf( "loopTest02 -> Função: %i \t Duração: %f\n", funcResult, timeResult );

	return 0;
}