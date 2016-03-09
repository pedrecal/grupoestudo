// icpc -openmp -mavx numPrimos.cpp -o  numPrimos.o
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int numerosPrimos(int);

int numerosPrimosParalelo(int, double*, double*, int);

int main(int argc, char const *argv[])
{
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
    double efficiency = 0.0;
    int numT;

    cout << "Search Prime Numbers until: ";
    cin >> max;
    cout << "Number of Loops: ";
    cin >> loopTimes;
    cout << "Number of Threads to use: ";
    cin >> numT;

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
        cout << "Loop " << i << ": Total of Prime Numbers: " << funcResult1 << " --- Time: " << time1;
    }

    cout << "\n\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n\n";

    avgTime = worstTime = bestTime = 0.0;
    cout << "----------------------------- Parallel -----------------------------" << endl;
    for(int i = 0; i < loopTimes; i++)
    {
        funcResult2 = numerosPrimosParalelo(max, &startTime, &endTime, numT);
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

int numerosPrimos(int max)
{
    bool flag = true;
    int numeros = 0;

    for(int i = 2; i < max; i++)
    {
        for(int j = 2; j < i - 1; j++)
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

int numerosPrimosParalelo(int max, double* startTime, double* endTime, int numT)
{
    int tid;
    int total = 0;
    bool flag = true;

    *startTime = omp_get_wtime();
    omp_set_num_threads(numT);
    #pragma omp parallel for reduction(+:total)
        for(int i = 2; i < max; i++)
        {
            //#pragma omp parallel for
            for(int j = 2; j < i - 1; j++)
            {
                if(i % j == 0)
                {
                    flag = false;
                    j = i - 1;
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
