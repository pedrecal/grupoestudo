// icpc -openmp -mavx -lm numPrimos.cpp -o  numPrimos.o

#include <iostream>
#include <time.h>
#include <omp.h>
#include <math.h>

using namespace std;

int numerosPrimos(int);

int numerosPrimosParalelo(int, double*, double*);

int main(int argc, char const *argv[]) {
    int max;
    double startTime = 0.0;
    double endTime = 0.0;
    double time1 = 0.0;
    double time2 = 0.0;
    double avgTime = 0.0;
    double worstTime = 0.0;
    double bestTime = 0.0;
    int funcResult1 = 0;
    int funcResult2 = 0;
    int loopTimes;

    cout << "Search Prime Numbers until: ";
    cin >> max;
    cout << "Number of Loops: ";
    cin >> loopTimes;


    cout << "------------------------------ Serial ------------------------------" << endl;
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
    cout << "----------------------------- Parallel -----------------------------" << endl << endl;
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
        cout << "Loop " << i << ": Total of Prime Numbers: " << funcResult2 << " --- Time: " << time2 << "\n";
    }

    cout << "\n" << "BestTime: " << bestTime << "\tWorstTime: " << worstTime << "\tAverageTime: " << avgTime/loopTimes << "\n" << endl;

    return 0;
}

int numerosPrimos(int max)
{
    bool flag = true;
    int total = 1;
    int max2;

    for(int i = 3; i <= max; i++)
    {
        max2 = (int) sqrt(i);

        for(int j = 2; j <= max2; j++)
        {
            if(i % j == 0)
            {
                flag = false;
                j=i;
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

int numerosPrimosParalelo(int max, double* startTime, double* endTime)
{
    bool flag = true;
    int total = 1;
    int max2;

    *startTime = omp_get_wtime();

    omp_set_nested(1);

    #pragma omp parallel for reduction(+:total) private(max2)
        for(int i = 3; i <= max; i++)
        {
            max2 = (int) sqrt(i);

            for(int j = 2; j <= max2; j++)
            {
                if(i % j == 0)
                {
                    flag = false;
                    j = i;
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
