#include <iostream>
#include "Motherboard.h"

int main(int args, char ** argc)
{
	Motherboard * mb = new Motherboard;
	delete mb;
	int nbr;
	std::cin >> nbr;
	return EXIT_SUCCESS;
}
