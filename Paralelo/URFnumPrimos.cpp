// icpc -openmp -mavx URFnumPrimos.cpp -o  URFnumPrimos.o -lm

#include <iostream>
#include <time.h>
#include <omp.h>
#include <math.h>

using namespace std;

int primeNumbers(int);

int primeNumbersParallel(int, double*, double*, int);

int main(int argc, char const *argv[]) {
    int max = 0;
    double startTime = 0.0;
    double endTime = 0.0;
    double time1 = 0.0;
    double time2 = 0.0;
    double avgTime = 0.0;
    double worstTime = 0.0;
    double bestTime = 0.0;
    int funcResult1 = 0;
    int funcResult2 = 0;
    int loopTimes = 0;
    double speedUp = 0.0;
    int numT = 0;
    double efficiency = 0.0;

    cout << "Search Prime Numbers until: ";
    cin >> max;
    cout << "Number of Loops: ";
    cin >> loopTimes;
    cout << "Number of Threads to use: ";
    cin >> numT;

    cout << "------------------------------ Serial ------------------------------" << endl;
    for(int i = 0; i < loopTimes; i++)
    {
        startTime = (double) clock()/CLOCKS_PER_SEC;
        funcResult1 = primeNumbers(max);
        endTime = (double) clock()/CLOCKS_PER_SEC;
        time1 = endTime - startTime;
        if(i == 0)
            worstTime = bestTime = time1;
        else if (bestTime > time1)
            bestTime = time1;
        else if(worstTime < time1)
            worstTime = time1;
        avgTime += time1;
        cout << "Loop " << i << ": Total of Prime Numbers: " << funcResult1 << " --- Time: " << time1;
    }

    cout << "\n\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n\n";

    avgTime = worstTime = bestTime = 0.0;
    cout << "----------------------------- Parallel -----------------------------" << endl << endl;
    for(int i = 0; i < loopTimes; i++)
    {
        funcResult2 = primeNumbersParallel(max, &startTime, &endTime, numT);
        time2 = endTime - startTime;
        if(i == 0)
            worstTime = bestTime = time2;
        else if (bestTime > time2)
            bestTime = time2;
        else if(worstTime < time2)
            worstTime = time2;
        avgTime += time2;
        cout << "Loop " << i << ": Total of Prime Numbers: " << funcResult2 << " --- Time: " << time2 << "\n";
    }

    speedUp = time1 / time2;
    efficiency = speedUp / numT;

    cout << "\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n" << endl;
    cout << "SpeedUp calc is: " << speedUp << endl << "Efficiency calc is: " << efficiency << endl;
    return 0;
}

int primeNumbers(int max)
{
    bool flag = true;
    int total = 1;
    int max2;

    for(int i = 3; i <= max; i++)
    {
        max2 = (int) sqrt(i);

        if(i % 2 == 0)
        {
            flag = false;
        }
        else
        {
            for(int j = 2; j <= max2; j++)
            {
                if(i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            total++;
        }

        flag = true;

    }

    cout << endl;

    return total;
}

int primeNumbersParallel(int max, double* startTime, double* endTime, int numT)
{
    bool flag = true;
    int total = 1;
    int max2;

    *startTime = omp_get_wtime();
    omp_set_num_threads(numT);
    #pragma omp parallel for reduction(+:total) private(max2)
        for(int i = 3; i <= max; i++)
        {
            max2 = (int) sqrt(i);

            if(i % 2 == 0)
            {
                flag = false;
            }
            else
            {
                for(int j = 2; j <= max2; j++)
                {
                    if(i % j == 0)
                    {
                        flag = false;
                        j = i;
                    }
                }
            }
            if(flag)
            {
                total++;
            }

            flag = true;
        }

    *endTime = omp_get_wtime();

    return total;
}
