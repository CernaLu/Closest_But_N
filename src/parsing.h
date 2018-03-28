#ifndef __e37tg2t_PARSING_H
#define __e37tg2t_PARSING_H


#define MAX_LINELENGTH 1024


void parse_inputfile(int argc, char **argv, double **array,\
                     unsigned long int *N, unsigned long int *n,\
		     double *x);

void explain_useage_exit(char *myname);

unsigned long int count_file_entries(FILE *file);

unsigned long int read_numbers_from_file(FILE *file, double *array);


#endif
