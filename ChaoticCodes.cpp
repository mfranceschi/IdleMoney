#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <regex>
#include <random>

// Creates a new thread that performs a periodic action.
// "func" is what to do and "interval" is the time period.
// Code from https://stackoverflow.com/a/43373364.
void DoPeriodically(const std::function<void(void)>& func, unsigned int interval)
{
    using namespace std::chrono;
    std::thread([&](){
        while(true)
        {
            time_point nextTime = steady_clock::now() + milliseconds(interval);
            func();
            std::this_thread::sleep_until(nextTime);
        }
    }).detach();
}

// Compares the input string to regex.
// Returns the resulting "regex_match" object.
std::cmatch ValidateInput(const std::string& input)
{
    const char* pattern_cstring = R"regex(buy \d|bet \d|quit)regex";
    std::regex pattern(pattern_cstring);
    std::cmatch results;
    std::regex_match(input.c_str(), results, pattern);
    return results;
}

// Returns the value to add to the user's money account.
int InheritanceBet(int bet)
{
    std::bernoulli_distribution boolDistrib(0.1);
    std::normal_distribution<int> binomDistrib(10, 1);
    std::default_random_engine engine;

    if (boolDistrib(engine))
        return bet*binomDistrib(engine);
    else
        return 0;
}
