#include <iostream>
#include "Display.h"

int main(int args, char ** argc)
{
	Display * d = new Display;
	d->WaitForInput();
	d->SetMessage(737);
	d->SetMoney(123);
	d->WaitForInput();
	delete d;
	int nbr;
	std::cin >> nbr;
	return EXIT_SUCCESS;
}
