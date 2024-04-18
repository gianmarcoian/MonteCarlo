#ifndef ARGS_H
#define ARGS_H

typedef struct
{
  int initialValue = 1;
  float avgReturn = 0.07;
  float standardDev = 0.15;
  int simulationCnt;
  int years = 10;
} Args;

#define ARG_CNT 2

Args check_args(int argc, char **argv, int rank);

#endif