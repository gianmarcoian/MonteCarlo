#define OMPI_SKIP_MPICXX 1
#include <mpi.h>

#include "main.hpp"
#include "microtime.h"

int main(int argc, char **argv) {
  auto [rank, size] = mpi_init(argc, argv);
  double time1 = 0, time2, t;

  // measure time
  if (rank == 0)
    time1 = microtime();

  Args args = check_args(argc, argv, rank);
  std::default_random_engine generator{std::random_device{}() + rank};

  size_t localRuns = args.simulationCnt / size;
  auto localSamples = compute_local(args, localRuns, generator);
  auto result = make_results_vector(rank, localRuns * size);

  MPI_Gather(localSamples.data(), localSamples.size(), MPI_FLOAT, result.data(),
             localSamples.size(), MPI_FLOAT, 0, MPI_COMM_WORLD);

  master_finalize(result, args, rank, size, generator);

  if (rank == 0) {
    time2 = microtime();

    t = time2 - time1;

    // Print results
    printf("\nTime = %g us\n", t);
    printf("Timer Resolution = %g us\n", getMicrotimeResolution());
    // printf("Performance = %g Gflop/s\n", 2.0 * n * n * 1e-3 / t);
  }

  MPI_Finalize();
  return 0;
}

// ------------------------ Helpers ------------------------- //

auto mpi_init(int argc, char **argv) -> std::pair<int, int> {
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  return {rank, size};
}

void compute_remainder(std::vector<float> &values, Args args, size_t size,
                       std::default_random_engine &generator) {
  size_t start = values.size() - (args.simulationCnt % size);
  std::transform(values.begin() + start, values.end(), values.begin() + start,
                 [&](float) {
                   return markov_chain(args.initialValue, args.avgReturn,
                                       args.standardDev, args.years, generator);
                 });
}

auto compute_local(Args args, size_t size,
                   std::default_random_engine &generator)
    -> std::vector<float> {
  std::vector<float> values(size);
  std::transform(values.begin(), values.end(), values.begin(), [&](float) {
    return markov_chain(args.initialValue, args.avgReturn, args.standardDev,
                        args.years, generator);
  });
  return values;
}

auto make_results_vector(int rank, size_t size) -> std::vector<float> {
  if (rank != 0)
    return {};

  return std::vector<float>(size);
}

void master_finalize(std::vector<float> &result, Args args, int rank, int size,
                     std::default_random_engine &generator) {
  if (rank == 0) {
    result.resize(args.simulationCnt);
    compute_remainder(result, args, size, generator);
    Stats stats = make_stats(result);
    print_stats(stats);
  }
}