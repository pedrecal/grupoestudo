// icpc -openmp -mavx numPrimos.cpp -o  numPrimos.o
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int numerosPrimos(int);

int numerosPrimosParalelo(int, double*, double*);

int main(int argc, char const *argv[]) {
    int max = 1000000;
    double startTime = 0.0;
    double endTime = 0.0;
    double time1 = 0.0;
    double time2 = 0.0;
    double avgTime = 0.0;
    double worstTime = 0.0;
    double bestTime = 0.0;
    int funcResult1 = 0;
    int funcResult2 = 0;
    int loopTimes = 5;

    cout << "------------------------------ Serial ------------------------------";
    for(int i = 0; i < loopTimes; i++)
    {
        startTime = (double) clock()/CLOCKS_PER_SEC;
        funcResult1 = numerosPrimos(max);
        endTime = (double) clock()/CLOCKS_PER_SEC;
        time1 = endTime - startTime;
        if(i == 0)
            worstTime = bestTime = time1;
        else if (bestTime > time1)
            bestTime = time1;
        else if(worstTime < time1)
            worstTime = time1;
        avgTime += time1;
        cout << "Loop " << i << ": Total of Cousin Numbers: " << funcResult1 << " --- Time: " << time1;
    }

    cout << "\n\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n\n";

    avgTime = worstTime = bestTime = 0.0;
    cout << "----------------------------- Parallel -----------------------------" << endl;
    for(int i = 0; i < loopTimes; i++)
    {
        funcResult2 = numerosPrimosParalelo(max, &startTime, &endTime);
        time2 = endTime - startTime;
        if(i == 0)
            worstTime = bestTime = time2;
        else if (bestTime > time2)
            bestTime = time2;
        else if(worstTime < time2)
            worstTime = time2;
        avgTime += time2;
        cout << "Loop " << i << ": Total  of Cousin Numbers: " << funcResult2 << " --- Time: " << time2 << "\n";
    }

    cout << "\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n" << endl;

    return 0;
}

int numerosPrimos(int max)
{
    bool flag = true;
    int numeros = 0;

    for(int i = 1; i < max; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            numeros++;
        }

        flag = true;
    }
    cout << endl;

    return numeros;
}

int numerosPrimosParalelo(int max, double* startTime, double* endTime)
{
    int NCPU = omp_get_num_procs();
    int tid;
    int *numeros = new int[NCPU];
    int total = 0;
    bool flag = true;

    for(int i = 0; i < NCPU; i++)
        numeros[i] = 0;

    *startTime = omp_get_wtime();

    #pragma omp parallel for
        for(int i = 1; i < max; i++)
        {
            tid = omp_get_thread_num();

            for(int j = 2; j < i; j++)
            {
                if(i % j == 0)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                numeros[tid]++;
            }

            flag = true;
        }

    *endTime = omp_get_wtime();

    for(int i = 0; i < NCPU; i++)
        total += numeros[i];

    delete [] numeros;

    return total;
}
