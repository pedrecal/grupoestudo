// icpc -openmp -v hello.cpp -o helloP

#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char const *argv[]) {

    #pragma omp parallel num_threads(3)
    {
      int NCPU, tid, NPR, NTHR;

      NCPU = omp_get_num_procs();   // Pega o numero total de CPUs/cores disponiveis pro OpemMP
      tid = omp_get_thread_num();   // Pega o ID do thread atual na região paralela
      NPR = omp_get_num_threads();  // Pega o numero total de threads disponiveis nessa região paralela
      NTHR = omp_get_max_threads(); // Pega o numero total de threads requisitados

      if (tid == 0) {
        cout << tid << ": NCPU\t= " << NCPU << endl;
        cout << tid << ": NTHR\t= " << NTHR << endl;
        cout << tid << ": NPR\t= " << NPR << endl;
      }

      cout << tid << " hello multicore user!! Im thread " << tid << " out of " << NPR <<endl;
    }
    
    #pragma omp parallel
    {
      int NCPU, tid, NPR, NTHR;

      NCPU = omp_get_num_procs();   // Pega o numero total de CPUs/cores disponiveis pro OpemMP
      tid = omp_get_thread_num();   // Pega o ID do thread atual na região paralela
      NPR = omp_get_num_threads();  // Pega o numero total de threads disponiveis nessa região paralela
      NTHR = omp_get_max_threads(); // Pega o numero total de threads requisitados

      if (tid == 0) {
        cout << tid << ": NCPU\t= " << NCPU << endl;
        cout << tid << ": NTHR\t= " << NTHR << endl;
        cout << tid << ": NPR\t= " << NPR << endl;
      }

      cout << tid << " hello multicore user!! Im thread " << tid << " out of " << NPR <<endl;
    }

    return 0;
}
