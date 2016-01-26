// icpc -o omptest -fopenmp omptest.c

#include <iostream>
#include <omp.h>
#include <time.h>
#include <math.h>

using namespace std;

double rzf(int, long);
double rzfParallel(int, long);

int main(int argc, char const *argv[]) {

	double startTime = 0.0;
	double endTime = 0.0;
	double funcResult = 0.0;
	double timeResult = 0.0;
	double avgTime = 0.0;
	double bestTime = 0.0;
	double worstTime = 0.0;
	long inf = 1000000000;
	int n = 2;
	int numb = 10;

  cout << "-------------------SERIAL---------------------" << endl;

	for(int i = 0; i < numb; i++)
	{
		startTime = clock();
		funcResult = rzf(n, inf);
		endTime = clock();
		timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);

		if(i == 0)
			bestTime = worstTime = timeResult;
		else if(timeResult < bestTime)
			bestTime = timeResult;
			else if(timeResult > worstTime)
				worstTime = timeResult;

		avgTime += timeResult;

		cout << "Id: " << i << "\t Time Result: " << timeResult << "\t FuncResult: " << funcResult <<  endl;
	}

	cout << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/numb << endl;
