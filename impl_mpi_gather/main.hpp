#pragma once

#include <algorithm>
#include <random>
#include <vector>

#include "args.h"
#include "monte_carlo.h"
#include "stats.h"
#include "values.h"

auto mpi_init(int, char **) -> std::pair<int, int>;
void compute_remainder(std::vector<float> &, Args, size_t,
                       std::default_random_engine &);
auto compute_local(Args, size_t, std::default_random_engine &)
    -> std::vector<float>;
auto make_results_vector(int, size_t) -> std::vector<float>;
void master_finalize(std::vector<float> &result, Args args, int rank, int size,
                     std::default_random_engine &generator);