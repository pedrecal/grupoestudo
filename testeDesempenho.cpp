#include <iostream>
#include <math.h>
#include <time.h>
#include <omp.h>

using namespace std;

double rzf()
{
    //Riemann zeta function
    //        ∞      1
    //ζ(n) =  ∑     ____
    //        k=1   k^n
    int n = 2;
    double sum = 0.0;
    long inf = 1000000;
    for(int k = 1; k <= inf; k++)
        sum += 1.0/pow(k, (double) n);

    return sum;
}

double rzfParallel()
{
    //Riemann zeta function
    //        ∞      1
    //ζ(n) =  ∑     ____
    //        k=1   k^n
    double sum = 0.0;
    int n = 2;
    long inf = 1000000000; //ou 1000000 1000000000

    #pragma omp parallel for reduction(+:sum) num_threads(4)
        for(int k = 1; k <= inf; k++)
            sum += 1.0/pow(k, (double) n);

    return sum;
}

int main(int argc, char const *argv[])
{
    double sum = 0.0;
    double timeResult = 0.0;
	double startTime = 0.0;
	double endTime = 0.0;
    double bestTime;
    double worstTime;
    double avgTime = 0.0;

    startTime = clock();
    sum = rzfParallel();
    endTime = clock();
    timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
    cout << "ID: 0" << "\tTime passed: " << timeResult;
    cout << "\tRiemann zeta function result is: " << sum << endl;
    bestTime = worstTime = avgTime = timeResult;

#pragma omp parallel for num_threads(8)
    for(int i = 1; i < 5; i++)
    {
        startTime = clock();
        sum = rzfParallel();
        endTime = clock();
        timeResult = (endTime/CLOCKS_PER_SEC) - (startTime/CLOCKS_PER_SEC);
        cout << "ID: " << i << "\tTime passed: " << timeResult;
        cout << "\tRiemann zeta function result is: " << sum << endl;
        if(bestTime > timeResult)
            bestTime = timeResult;
        if(worstTime < timeResult)
            worstTime = timeResult;
        avgTime += timeResult;
    }

    avgTime /= 5;
    cout << "Best Time: " << bestTime << "\tWorst Time: " << worstTime << "\tAverage Time: " << avgTime << endl;
    return 0;
}
