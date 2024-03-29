// primeNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "primeNumber.h"

const int VALID_ARGUMENT_COUNT = 2;
const int MIN_NUMBER = 2;
const int MAX_NUMBER = 100000000;

void PrintUserHelp()
{
	std::cout << "Usage: primeNumber.exe <upperBound>\n";
}

bool IsValidUpperBound(int upperBound)
{
	return upperBound >= MIN_NUMBER && upperBound <= MAX_NUMBER;
}

int StringToInt(const std::string &str, bool &wasError)
{
	int result = 0;
	try
	{
		result = std::stoi(str);
	}
	catch (const std::invalid_argument &e)
	{
		wasError = true;
		std::cerr << e.what() << "\n";
	}
	catch (const std::out_of_range &e)
	{
		wasError = true;
		std::cerr << e.what() << "\n";
	}
	return result;
}

bool SieveEratosthenes(std::ostream &output, const std::string &upperBoundStr)
{
	bool wasError = false;
	int upperBound = StringToInt(upperBoundStr, wasError);
	if (wasError)
	{
		return false;
	}

	if (!IsValidUpperBound(upperBound))
	{
		std::cout << "upperBound must in a follow range [" << MIN_NUMBER << ", " << MAX_NUMBER << "]\n";
		PrintUserHelp();
		return false;
	}

	std::set<int> primeNumbers = GeneratePrimeNumber(upperBound);
	PrintPrimeNumber(output, primeNumbers);
	output << "count prime number: " << primeNumbers.size() << "\n";

	return true;
}

int main(int argc, char *argv[])
{
	if (argc != VALID_ARGUMENT_COUNT)
	{
		std::cout << "Invalid argument count\n";
		PrintUserHelp();
		return 1;
	}

	if (!SieveEratosthenes(std::cout, argv[1]))
	{
		return 1;
	}

	return 0;
}
