#include "libraries.h"


void parse_inputfile(int argc, char **argv, double **array,\
                     unsigned long int *N, unsigned long int *n,\
		     double *x)
{
FILE *file;

if(argc!=4)
  {
  explain_useage_exit(argv[0]);
  }

file = fopen(argv[1], "r");
if(NULL == file)
  {
  printf("\n\nCould not open file '%s' for reading.\n\n", argv[1]);
  exit(0);
  }

if(1 != sscanf(argv[2], "%lu", n))
  {
  explain_useage_exit(argv[0]);
  }

if(*n < 0)
  {
  explain_useage_exit(argv[0]);
  }

if(1 != sscanf(argv[3], "%le", x))
  {
  explain_useage_exit(argv[0]);
  }

*N = count_file_entries(file);

allocate_doublearray(array, *N);

read_numbers_from_file(file, *array);

fclose(file);
}
  


void explain_useage_exit(char *myname)
{
printf("\n\nUseage:\n\n%s  File  n  x\n\n"\
       "Will read numbers from the ASCII file 'File',\n"\
       "and dtermine the closest-but-n to the number x.\n\n"\
       "'File' is expected to contain one number per line\n"\
       "IN ASCENDING ORDER.\n\n\n",\
       myname);
exit(0); 
}




unsigned long int count_file_entries(FILE *file)
{
unsigned long int linecounter = 0;
char line[MAX_LINELENGTH];

fseek(file, 0, SEEK_SET);
while(fgets(line, MAX_LINELENGTH, file)!=NULL)
  {
  linecounter++;
  }
fseek(file, 0, SEEK_SET);

return(linecounter);
}



unsigned long int read_numbers_from_file(FILE *file, double *array)
{
unsigned long int linecounter = 0;
char line[MAX_LINELENGTH];

fseek(file, 0, SEEK_SET);
while(fgets(line, MAX_LINELENGTH, file)!=NULL)
  {
  if( 1 != sscanf(line, "%le", array+linecounter) )
    {
    printf("\n\nCould not read line #%ld of input file.\n\n", 1 + linecounter);
    }
  linecounter++;
  }
fseek(file, 0, SEEK_SET);

return(linecounter);
}

