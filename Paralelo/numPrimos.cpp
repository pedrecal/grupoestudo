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
    double tempo1 = 0.0;
    double tempo2 = 0.0;
    int funcResult1;
    int funcResult2;

    cout << "------------------------------ Serial ------------------------------" << endl;
    startTime = (double) clock()/CLOCKS_PER_SEC;
    funcResult1 = numerosPrimos(max);
    endTime = (double) clock()/CLOCKS_PER_SEC;
    tempo1 = endTime - startTime;

    cout << endl << "Total numeros primos: " << funcResult1 << " --- Tempo: "<< tempo1 << endl << endl;

    cout << "----------------------------- Parallel -----------------------------" << endl;
    //startTime = omp_get_wtime();
    funcResult2 = numerosPrimosParalelo(max, &startTime, &endTime);
    //endTime = omp_get_wtime();
    tempo2 = endTime - startTime;

    cout << endl << "Total numeros primos: " << funcResult2 <<" --- Tempo: "<< tempo2 << endl;

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
