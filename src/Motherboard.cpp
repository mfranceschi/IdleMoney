#include <chrono>
#include <thread>

#include "Motherboard.h"

void Motherboard::Init()
{
    // Create another thread for updating the player's data.
    using namespace std::chrono;
    using clock_type = steady_clock;
    milliseconds interval(1000);

    std::thread([&](){
        while(true)
        {
            time_point<clock_type> nextTime = clock_type::now() + interval;
            func();
            std::this_thread::sleep_until(nextTime);
        }
    }).detach();
}