#include <chrono>
#include <thread>

#include "Motherboard.h"

const std::string Motherboard::MSG_NO_MONEY = "You don't have enough money!";
const std::string Motherboard::MSG_FOR_INHERITANCE = "Congrats, you won %s from someone's legacy!";
const std::string Motherboard::MSG_NEW_STORE = "Congrats, you now have a new store!";

bool Motherboard::PlayerBuyStore()
{
    money_t price = PriceOfNextStore();
    if (p1.CanSpend(price))
    {    
        p1.Buy(price, p1.GetCurIncome() + 10);
        d.SetMoney(p1.GetCurMoney());
        d.SetIncome(p1.GetCurIncome());
        d.SetMessage(MSG_NEW_STORE);
        return true;
    }
    else
    {
        d.SetMessage(MSG_NO_MONEY);
        return false;
    }
}

money_t Motherboard::PriceOfNextStore() const
{

}


Motherboard::Motherboard()
{
    // Create another thread for updating the player's data.
    using namespace std::chrono;
    using clock_type = steady_clock;

    std::thread([&](){
        time_point<clock_type> nextTime;
        milliseconds interval(1000);
        while(true)
        {
            nextTime = clock_type::now() + interval;
            p1.ApplyTheIncomes();
            d.SetMoney(p1.GetCurMoney());
            std::this_thread::sleep_until(nextTime);
        }
    }).detach();
}

Motherboard::~Motherboard() {}
