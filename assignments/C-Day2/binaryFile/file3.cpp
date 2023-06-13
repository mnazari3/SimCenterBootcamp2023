
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  if (argc != 3) {
    cerr << "ERROR correct usage appName inputFile outputBinaryFile\n";
    return -1;
  }

  //
  // read from ascii file
  //
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 100;
  double *vector1 = new double [maxVectorSize];
  double *vector2 = new double [maxVectorSize];  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      double *tmpVector1 = new double [2*vectorSize];
      double *tmpVector2 = new double [2*vectorSize];
      for (int j=0; j<vectorSize; j++) { 
	tmpVector1[j] = vector1[j];
	tmpVector2[j] = vector2[j];
      }

      delete(vector1);
      delete(vector2);

      vector1 = tmpVector1;
      vector2 = tmpVector2;

      maxVectorSize *= 2;

      // some code needed here I think .. programming exercise
    }
  }
  
  fclose(filePtr);

  //
  // write data to binary file
  //
  
  FILE *filePtrB = fopen(argv[2],"wb");
  
  // some missing code to write vector1, followed by vector 2
  fwrite(vector1, sizeof(double), vectorSize, filePtrB);
  fwrite(vector2, sizeof(double), vectorSize, filePtrB);
  
  fclose(filePtrB);  
}
