# Idle Money - Just a test project for me to exercise in unexplored domains of C++

## Motivation

This game is inspired by the "Idle X Tycoon" games that can be found on smartphone's stores.
I figured out that, even with my limited knowledge of C++ and the fact that I do not plan to lean GUI in C++, many of these games' aspects could be reproduced.
This repo is just a demonstration of my work and does not have the purpose of being marketed.

## Description

* Video game in Command-Line Interface for a single player
* The player has a certain amount of money, it begins at $0.
* The player has owns a certain number of stores, it begins at 1.
* Each store makes the player earn $1 per 1 second.
* The player can buy stores. The price of the next store is 5 the price of the last bought store. The price of the first store is $10.
* The player can summon inheritance by betting money. It has 10% chance of giving him/her back 25x the bet.
* The amount of money and the amount of stores are always displayed on the screen.
* The player can type commands on the keyboard and what is typen is displayed.
* The last player's validated input is displayed on screen during 5 seconds at max.
* The game stops when the player reaches $999B or when the player presses Ctrl+D.

## Interface samples

### Example 1

```{shell}
==================== IDLE MONEY ====================
Current money: $476.6M       Money/s: $819.0K

What's next?:

Congrats, you won 200.0M with Mr Johnson's legacy!
```

On the previous example, the player has `476.6 * 10^6` dollars.
He/she earns `819.0 * 10^3` dollars per seconds.
He/she wrote no next command.
He/she won some money from legacy a few seconds ago.
