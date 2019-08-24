#include <PDCurses/curses.h>
#include <string>

#include "Globals.h"

class Display
{
    using string = std::string;
public:

    string GetLastInput() const; // Returns last_input (full non-validated string).

    void SetMoney(money_t); // Sets cur_money.
    void SetIncome(money_t); // Sets cur_income.
    void SetInheritance(money_t); // Sets inheritance (non-mandatory).
    void SetSecondStep(money_t); /* wut */

protected:
    string cur_money;
    string cur_income;
    string last_input;
    string inheritance;
};
