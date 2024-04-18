
#include "args.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Check the command line arguments and return them in a struct.
 *
 * @param argc
 * @param argv
 * @return Args
 */
Args check_args(int argc, char **argv, int rank)
{
  if (argc != ARG_CNT && rank==0)
  {
    printf("Usage: %s <number of simulations>\n", argv[0]);
    exit(1);
  }

  Args args;
  // args.initialValue = atoi(argv[1]);
  // args.avgReturn = (float)atof(argv[1]);
  // args.standardDev = (float)atof(argv[3]);
  args.simulationCnt = atoi(argv[1]);
  // args.years = atoi(argv[5]);

  return args;
}