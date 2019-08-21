#include <chrono>
#include "RandomService.h"

RandomService::RandomService() :
    engine(),
    boolGen(BOOL_DISTRIB_PARAM),
    normGen(NORM_DISTRIB_MEAN, NORM_DISTRIB_SIGMA)
{}

money_t RandomService::Bet(money_t amount)
{
    if (boolGen(engine))
        return int(amount*normGen(engine));
    else
        return 0;
}

void RandomService::SetSeed(unsigned int val)
{
    engine.seed(val);
}

void RandomService::SetSeedTimestamp()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    unsigned int newseed = now.time_since_epoch().count();
    SetSeed(newseed);
}
