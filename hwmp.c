#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
int nthreads, tid;

#pragma omp parallel private(nthreads, tid) num_threads(8)
  {

  tid = omp_get_thread_num();
  printf("Hello World from thread = %d\n", tid);

  if (tid == 0)
    {h
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }

  }

}
