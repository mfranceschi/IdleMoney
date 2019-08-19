#include <functional>
#include <regex>
#include <string>

// Creates a new thread that performs a periodic action.
// "func" is what to do and "interval" is the time period.
// Code from https://stackoverflow.com/a/43373364.
void DoPeriodically(const std::function<void(void)>& func, unsigned int interval);

// Compares the input string to regex.
// Returns the resulting "regex_match" object.
std::cmatch ValidateInput(const std::string& input);

// Returns the value to add to the user's money account.
int InheritanceBet(int bet);

void TestCurses();
