#include <algorithm>
#include <sstream>

#include "Display.h"

constexpr static money_t operator"" _mt(unsigned long long integer)
{return money_t(integer);}

Display::Display() 
{
    initscr(); // Init screen and functions.
    move(0, 0);
    printw("==================== IDLE MONEY ====================");
    move(1, 0);
    printw("kk");

    refresh();
}

Display::~Display()
{
    endwin();
}

std::string Display::GetLastInput() const
{
    return last_input;
}

void Display::WaitForInput()
{
    getch();
}

void Display::SetMoney(money_t)
{

}

void Display::SetIncome(money_t)
{

}

void Display::SetMessage(money_t)
{
    // Call SetMessage with formatted string.
}

void Display::SetMessage(const std::string& msg)
{
    message = msg;
    // Apply to screen.
}

std::string Display::mtos(money_t money)
{
    if (!(money / 1000))
    {
        // Special case if money < 1000, let's get done with it fast.
        return std::string("$") + std::to_string(money);
    }
    else
    {
        std::ostringstream oss("$");
        std::string int_part_s, dec_part_s;
        money_t powOf10, int_part_i, dec_part_i;
        char unit;

        if (money / 1000000000_mt) // money >= 10^9
        {
            powOf10 = 1000000000_mt;
            unit = 'B';
        }
        else if (money / 1000000_mt) // money >= 10^6
        {
            powOf10 = 1000000_mt;
            unit = 'M';
        }
        else // money >= 10^3
        {
            powOf10 = 1000_mt;
            unit = 'K';
        }

        int_part_i = money / powOf10;
        int_part_s = std::to_string(int_part_i);
        dec_part_i = money_t((money - int_part_i * powOf10) / 100.0L);
        dec_part_s = std::to_string(dec_part_i);
        oss << int_part_s << ".";
        oss << dec_part_s.substr(0, std::max<money_t>(4 - int_part_s.length(), dec_part_s.length()));
        oss.put(unit);
        
        return oss.str();
    }
}
