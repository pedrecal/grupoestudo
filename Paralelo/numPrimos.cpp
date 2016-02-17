// icpc -openmp numPrimos.cpp -o  numPrimos.o
#include <iostream>
#include <time.h>
#include <omp.h>

using namespace std;

int numerosPrimos(int);

int numerosPrimosParalelo(int);

int main(int argc, char const *argv[]) {
    int max = 100000000;
    double startTime = 0.0;
    double endTime = 0.0;
    double tempo1 = 0.0;
    double tempo2 = 0.0;
    int funcResult1;
    int funcResult2;

    cout << "------------------------------ Serial ------------------------------" << endl;
    startTime = clock()/CLOCKS_PER_SEC;
    funcResult1 = numerosPrimos(max);
    endTime = clock()/CLOCKS_PER_SEC;
    tempo1 = endTime - startTime;

    cout << endl << "Total numeros primos: " << funcResult1 << " --- Tempo Serial: "<< tempo1 << endl << endl;

    cout << "----------------------------- Parallel -----------------------------" << endl;
    startTime = omp_get_wtime();
    funcResult2 = numerosPrimosParalelo(max);
    endTime = omp_get_wtime();
    tempo2 = endTime - startTime;

    cout << endl << "Total numeros primos: " << funcResult2 <<" --- Tempo Paralelo: "<< tempo2 << endl;

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
            //cout << " " << i;
            //cout << " . ";
        }

        flag = true;
    }
    cout << endl;

    return numeros;
}

int numerosPrimosParalelo(int max)
{
    bool flag = true;
    int numeros = 0;

    #pragma omp parallel for shared(numeros)
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
                //cout << " " << i;
                //cout << " . ";
            }

            flag = true;
        }

    return numeros;
}
