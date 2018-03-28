#include "libraries.h"


void file_output(double *array, int N, char *filename)
{
int row;
FILE *file;

file = fopen(filename, "w");
if(NULL == file)
  {
  printf("\n\nCould not open file '%s' for writing.\n\n", filename);
  exit(0);
  }

for(row = 0; row < N; row++)
  {
  fprintf(file, "%.16f\n", array[row]);
  }

fclose(file);
}
