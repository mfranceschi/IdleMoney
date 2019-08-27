#include "Player.h"

Player::Player() :
    cur_money(PLAYER_INITIAL_MONEY),
    cur_income(PLAYER_INITIAL_INCOME),
    nbr_stores(PLAYER_INITIAL_STORES),
    rand(),
    ID(1)
{
    rand.SetSeedTimestamp();
}

void Player::Buy(money_t price, money_t new_income)
{
    cur_money -= price;
    cur_income = new_income;
    ++nbr_stores;
}

money_t Player::Bet(money_t amount)
{
    money_t bet_res = rand.Bet(amount);
    cur_money += bet_res - amount;
    return bet_res;
}

void Player::ApplyTheIncomes()
{
    cur_money += cur_income;
}

bool Player::CanSpend(money_t amount) const
{
    return cur_money - amount >= 0;
}
