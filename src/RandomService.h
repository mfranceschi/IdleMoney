#pragma once
#include <random>
#include <string>
#include "Globals.h"

class RandomService
{
public:
    money_t Bet(money_t amount); // Returns the money won by player.
    void SetSeed (unsigned int); // Sets the initial seed (single-call method).
    void SetSeedTimestamp(); // Uses current timestamp as initial seed.
    RandomService();

protected:
    std::minstd_rand engine;
    std::bernoulli_distribution boolGen;
    std::normal_distribution<float> normGen;
};
