#include <iostream>
#include <thread>
#include <chrono>
#include "Motherboard.h"

int main(int args, char ** argc)
{
	using MB = Motherboard;
	MB* mb = new MB;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	delete mb;
	int nbr;
	std::cin >> nbr;
	return EXIT_SUCCESS;
}
