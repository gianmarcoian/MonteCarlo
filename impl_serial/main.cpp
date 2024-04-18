
#include <cstdlib>
#include <random>
#include <vector>

#include "args.h"
#include "microtime.h"
#include "monte_carlo.h"
#include "stats.h"

int main(int argc, char **argv) {

  double time1, time2, t;

  // Parse command line arguments
  Args args = check_args(argc, argv, 0);

  // Initialize the random number generator
  std::default_random_engine generator{std::random_device{}()};

  // Initialize the vector of values
  std::vector<float> values(args.simulationCnt);

  // measure time
  time1 = microtime();

  // Run the simulations
  for (int i = 0; i < args.simulationCnt; ++i) {
    values[i] = markov_chain(args.initialValue, args.avgReturn,
                             args.standardDev, args.years, generator);
  }

  time2 = microtime();
  t = time2 - time1;

  // Print the stats
  print_stats(make_stats(values));

  // Print results
  printf("\nTime = %g us\n", t);
  printf("Timer Resolution = %g us\n", getMicrotimeResolution());
  // printf("Performance = %g Gflop/s\n", 2.0 * n * n * 1e-3 / t);

  return 0;
}