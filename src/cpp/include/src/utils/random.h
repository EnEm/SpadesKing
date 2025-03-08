#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <random>

static std::mt19937 rng(
    std::chrono::steady_clock::now().time_since_epoch().count());

#endif  // RANDOM_H
