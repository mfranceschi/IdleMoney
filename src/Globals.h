#pragma once

/*
    This file contains all global types, among others.
*/

typedef unsigned long money_t;

constexpr money_t PLAYER_INITIAL_MONEY = 0;
constexpr money_t PLAYER_INITIAL_INCOME = 1;
constexpr money_t PLAYER_INITIAL_STORES = 1;

constexpr static float BOOL_DISTRIB_PARAM = 0.1f;
constexpr static float NORM_DISTRIB_MEAN = 10.0f;
constexpr static float NORM_DISTRIB_SIGMA = 1.0f;