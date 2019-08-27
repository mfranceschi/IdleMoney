// Class that holds app logic.
#pragma once

#include <string>

#include "Globals.h"
#include "Player.h"
#include "Display.h"

class Motherboard
{
public:
    bool PlayerBuyStore();
    money_t PriceOfNextStore() const;

    Motherboard();
    ~Motherboard();

    static const std::string 
        MSG_NO_MONEY, 
        MSG_FOR_INHERITANCE, 
        MSG_NEW_STORE;

protected:
    Player p1;
    Display d;
};
