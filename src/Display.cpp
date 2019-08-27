#include <algorithm>
#include <sstream>

#include "Display.h"

constexpr static money_t operator"" _mt(unsigned long long integer)
{return money_t(integer);}

const std::string Display::MSG_FOR_INHERITANCE = "Congrats, you won %s from someone's legacy!";

Display::Display() 
{
    initscr();
    move(0, 0);
    printw("==================== IDLE MONEY ====================");
    move(1, 0);
    printw("Current money: $476.6M       Money/s: $819.0K");
    move(3, 0);
    printw("What's next?: ");

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

void Display::SetMoney(money_t money)
{
    move(1, 15); /* TODO */
    cur_money = mtos(money);
    printw("        ");
    move(1, 15);
    printw(cur_money.c_str());
    refresh();
}

void Display::SetIncome(money_t money)
{
    move(1, 999); /// TODO
    cur_income = mtos(money);
    printw("      ");
    move(1, 999);
    printw(cur_income.c_str());
    refresh();
}

void Display::SetMessage(money_t money)
{
    char buf [100];
    std::snprintf(buf, 100, MSG_FOR_INHERITANCE.c_str(), mtos(money).c_str());
    SetMessage(buf);
}

void Display::SetMessage(const std::string& msg)
{
    message = msg;
    move(5, 0);
    printw(message.c_str());
    refresh();
}

std::string Display::mtos(money_t money)
{
    if (money < 1000)
    {
        return std::string("$") + std::to_string(money);
    }
    else
    {
        std::ostringstream oss("$");
        std::string int_part_s, dec_part_s;
        money_t powOf10, int_part_i, dec_part_i;
        char unit;

        if (money >= 1000000000_mt) // money >= 10^9
        {
            powOf10 = 1000000000_mt;
            unit = 'B';
        }
        else if (money >= 1000000_mt) // money >= 10^6
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
        dec_part_i = money_t((money - int_part_i * powOf10) / 100.0f);
        dec_part_s = std::to_string(dec_part_i);
        oss << int_part_s << ".";
        oss << dec_part_s.substr(0, std::max<money_t>(4 - int_part_s.length(), dec_part_s.length()));
        oss.put(unit);
        
        return oss.str();
    }
}
