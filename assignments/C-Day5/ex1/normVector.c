#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

int main(int argc, char **argv) {

  //
  // create vector with random numbers
  //

 
  if (argc != 2) {
    printf("Error correct usage: app vectorSize\n");
    return 0;
  }
  int vectorSize = atoi(argv[1]);
  
  double *globalVector = (double*)malloc(sizeof(double) * vectorSize);
  srand(50);
  for (int i = 0; i < vectorSize; i++) {
    double random_number = 1.0 + (double)rand() / RAND_MAX;
    globalVector[i] = random_number;
  }  

  //
  // calculate norm
  //

  
  double norm = 0;
  double contributions[64];
  for (int i=0; i<64; i++)
    contributions[i] = 0;

#pragma omp parallel
  { 
    double myContribution = 0;
    int tid = omp_get_thread_num();
    int numP = omp_get_num_threads();
    for (int i=tid; i<vectorSize; i+=numP) { 
    myContribution += globalVector[i]*globalVector[i];
  }
  contributions[tid] = myContribution;
}
 
  for (int i = 0; i<64; i++)
  norm += contributions[i];

 norm = sqrt(norm);

  //
  // print norm
  //
  
  printf("Norm = %f \n", norm);
  
  return 0;
}
