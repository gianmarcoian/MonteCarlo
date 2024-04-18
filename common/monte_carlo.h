#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

#include <cstddef>
#include <random>

/**
 * @brief
 *
 * @param float initialValue
 * @param float avgReturn
 * @param float standardDev
 * @param int sampleCnt
 * @return float*
 */
float markov_chain(float, float, float, size_t, std::default_random_engine &);

#endif