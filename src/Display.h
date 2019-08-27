#pragma once
#include <string>

#include <PDCurses/curses.h>

#include "Globals.h"

class Motherboard;

class Display
{
    friend class Motherboard;
    using string = std::string;
public:

    string GetLastInput() const; // Returns last_input (full non-validated string).
    void WaitForInput(); // Just waits for the user to press any key.

    void SetMoney(money_t); // Sets cur_money and refresh.
    void SetIncome(money_t); // Sets cur_income and refresh.
    void SetMessage(money_t); // Sets text message (inheritance) and refresh.
    void SetMessage(const string&); // Sets text message and refresh.

    Display(); // Turns the console interface ON.
    ~Display(); // Destroys and turns the console interface OFF.

    /* Signals coming from user input */
    const int SIG_STOP = 1;
    const int SIG_BUY = 2;
    const int SIG_BET = 3;

protected:
    // Converts money_t to string.
    // Output format: $123.4M (for 123.4xx.xxx dollars).
    static std::string mtos(money_t); 

    string cur_money;
    string cur_income;
    string last_input;
    string message;
};
