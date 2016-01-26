//icpc testeLoop.cpp - o testeLoop

#include <iostream>
#include <omp.h>
#include <time.h>
#include <math.h>

using namespace std;

double rzf(int, long); //riemann zieta func
double rzfParallel(int, long);

int main(int argc, char const *argv[])
{
	double startTime = 0.0;
	double endTime = 0.0;
	double funcResult = 0.0;
	double timeResult = 0.0;
	double avgTime = 0.0;
	double bestTime = 0.0;
	double worstTime = 0.0;
	long inf = 1000000000;
	int n = 2;
	int numb = 5;
	worstTime = timeResult;

	cout << "-------------------------SERIAL------------------------" << endl;

	for(int i = 0; i < numb; i++)//Exec Func and register time
	{
		startTime = clock();
		funcResult = rzfParallel(n, inf);
		endTime = clock();
		timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);

		avgTime += timeResult;

		if(i == 0)
		{
			bestTime = timeResult;
		}
		if(timeResult < bestTime)//Search for bestTime
		{
			bestTime = timeResult;
		}
		if(timeResult > worstTime)//Search for worstTime
		{
			worstTime = timeResult;
		}

		cout << "Id: " << i
		<< "\t Time Result: " << timeResult
		<< "\t FuncResult: " << funcResult
		<<  endl;
	}//End for

cout << "BestTime: " << bestTime
<< "\tWorstTime: " << worstTime
<< "\tAverageTime: " << avgTime/numb
<< endl;

//_//_//_//_//_//_//_//_//END OF SERIAL EXEC//_//_//_//_//_//_//_//_//_//_//_//

cout << endl << "----------------PARALLEL---------------------" << endl;
avgTime = 0;

for(int i = 0; i < numb; i++)//Exec Func and register time
{
	startTime = clock();
	funcResult = rzf(n, inf);
	endTime = clock();
	timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);

	avgTime += timeResult;

	if(i == 0)
	{
		bestTime = timeResult;
	}
	if(timeResult < bestTime)//Search for bestTime
	{
		bestTime = timeResult;
	}
	if(timeResult > worstTime)//Search for worstTime
	{
		worstTime = timeResult;
	}

	cout << "Id: " << i
	<< "\t Time Result: " << timeResult
	<< "\t FuncResult: " << funcResult
	<<  endl;
}//End for

cout << "BestTime: " << bestTime
<< "\tWorstTime: " << worstTime
<< "\tAverageTime: " << avgTime/numb
<< endl;
return 0;
}//End Main

//Riemann Zieta Funcs
double rzfParallel(int n, long inf)
{
	double sum = 0.0;
	#pragma omp parallel for reduction(+:sum) num_threads(8)						//CHECK X
		for(int k = 1; k <= inf; k++)
			sum += 1.0/pow(k, (double)n);

	return sum;
}

double rzf(int n, long inf)
{
	double sum = 0.0;
		for(int k = 1; k <= inf; k++)
			sum += 1.0/pow(k, (double)n);

	return sum;
}
