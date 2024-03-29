// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include "CarController.h"

int main()
{
	CCar car;
	CCarController carController(car, std::cin, std::cout);

	while (!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "> ";

		if (!carController.HandleCommand())
		{
			std::cout << "Unknown command!\n";
		}
	}

	return 0;
}
