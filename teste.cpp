#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int loopTest01(int x)
{
	float Kms[10] = {240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3};
	float Lts[10] = {10.3, 15.6, 8.7, 14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4};
	float KpL[10], *ptrv1, *ptrv2, *ptrv3;
	int i;

	*ptrv1 = &Kms[0];
	*ptrv2 = &Lts[0];
	*ptrv3 = &KpL[0];


		for (i = 0; i < 10; ++i)
		{
			
			*ptrv3++ = *ptrv1++ / *ptrv2++;
		}

		ptrv3 = &KpL[0];

		for (i = 0; i < 10; ++i, ptrv3++)
		{
			printf("%f\n", *ptrv3);
		}
	

	return 0;
}

int loopTest02(int x)
{
	float Kms[10] = {240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3};
	float Lts[10] = {10.3, 15.6, 8.7, 14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4};
	float KpL[10];
	int i;

	for (i = 0; i < 10; ++i)
	{
		KpL[i] = Kms[i] / Lts[i];
	}

	for (i = 0; i < 10; ++i)
	{
		printf("%f\n", KpL[i]);
	}
	return 0;
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