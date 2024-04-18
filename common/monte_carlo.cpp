
#include <math.h>
#include <random>
#include <stdlib.h>

#include "monte_carlo.h"

/**
 * @brief Generate a Monte Carlo simulation of a stock price.
 *
 * @param initialValue
 * @param avgReturn
 * @param standardDev
 * @param sampleCnt
 * @return float
 */
float markov_chain(float value, float avgReturn, float standardDev,
                   size_t years, std::default_random_engine &generator) {
  std::lognormal_distribution<float> distribution(avgReturn, standardDev);

  for (size_t i = 0; i < years; ++i) {
    value *= distribution(generator);
  }

  return value;
}