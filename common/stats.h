#pragma once

#include <vector>

struct Stats {
  float min;
  float max;
  float avg;
  float stdDev;
};

auto make_stats(const std::vector<float> &values) -> Stats;
void print_stats(Stats stats);