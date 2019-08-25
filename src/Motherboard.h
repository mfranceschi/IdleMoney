// Class that holds app logic.

#include "Player.h"
#include "Display.h"

class Motherboard
{
public:
    void Init();
    void Main();
    void Exit();

protected:
    Player p1;
    Display d;
};
