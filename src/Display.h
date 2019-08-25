#include <PDCurses/curses.h>
#include <string>

#include "Globals.h"

class Display
{
    using string = std::string;
public:

    string GetLastInput() const; // Returns last_input (full non-validated string).
    void WaitForInput(); // Just waits for the user to press any key.

    void SetMoney(money_t); // Sets cur_money.
    void SetIncome(money_t); // Sets cur_income.
    void SetMessage(money_t); // Sets text message (inheritance)
    void SetMessage(const string&); // Sets text message.
    void SetSecondStep(money_t); /* wut */

    Display();
    ~Display();

    /* Signals coming from user input */
    const int SIG_STOP = 1;

protected:
    // Converts money_t to string.
    // Output format: $123.4M (for 123.4xx.xxx dollars).
    static std::string mtos(money_t); 

    string cur_money;
    string cur_income;
    string last_input;
    string message;
};
