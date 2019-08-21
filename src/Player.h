#pragma once

#include "Globals.h"
#include "RandomService.h"

class Player
{
public:
    const int ID;

    void Buy(); // Try to buy the next store.
    money_t Bet(money_t); // Bet some money: spends it and returns the eventual amount.
    void ApplyTheIncomes(); // Add cur_income to cur_money.
    bool CanSpend(money_t) const; // Indicated whether player can spend that money.
    
    inline money_t GetCurMoney() const {return cur_money;}
    inline money_t GetCurIncome() const {return cur_income;}
    
    Player();

protected:
    money_t cur_money;
    money_t cur_income;
    size_t nbr_stores;
    RandomService rand;
};
