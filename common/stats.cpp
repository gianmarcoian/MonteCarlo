

#include "stats.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <numeric>

auto make_stats(const std::vector<float> &values) -> Stats {
  float mean = std::accumulate(values.begin(), values.end(), 0.0f) /
               static_cast<float>(values.size());

  std::vector<float> diff(values.size());
  std::transform(values.begin(), values.end(), diff.begin(),
                 [mean](float x) { return x - mean; });
  float sq_sum =
      std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  float stdev = std::sqrt(sq_sum / static_cast<float>(values.size()));

  float min = *std::min_element(values.begin(), values.end());
  float max = *std::max_element(values.begin(), values.end());

  Stats stats{
      min,
      max,
      mean,
      stdev,
  };

  return stats;
}

void print_stats(Stats stats) {
  printf("Min: %f\n", stats.min);
  printf("Max: %f\n", stats.max);
  printf("Avg: %f\n", stats.avg);
  printf("StdDev: %f\n", stats.stdDev);
}