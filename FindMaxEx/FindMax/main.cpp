#include "stdafx.h"
#include "FindMaxEx.h"
#include <iostream>
#include <string>

struct Sportsman
{
	Sportsman(std::string const& lfm = "", int growth = 190, int weight = 100)
		: lfm(lfm)
		, growth(growth)
		, weight(weight)
	{
	}

	bool operator<(Sportsman const& other)
	{
		return lfm < other.lfm;
	}

	std::string lfm;
	int growth;
	int weight;
};


bool operator==(Sportsman const& lhs, Sportsman const& rhs)
{
	return lhs.lfm == rhs.lfm && lhs.growth == rhs.growth && lhs.weight == rhs.growth;
}

std::ostream& operator<<(std::ostream& os, Sportsman const& sportsman)
{
	os << "sportsman " << sportsman.lfm << " have growth " << sportsman.growth << " and weight " << sportsman.weight;
	return os;
}

int main()
{
	{
		Sportsman lhs("12", 12, 12);
		Sportsman rhs("12", 12, 12);

		std::cout << (lhs == rhs) << std::endl;
	}
	std::vector<int> v = { 1, 2 ,3, -4, 55, -56, 45 };

	int maxValue = 0;
	if (FindMax(v, maxValue, [](int lhs, int rhs)
	{
		return lhs < rhs;
	}))
	{
		std::cout << maxValue << std::endl;
	}

	std::vector<Sportsman> sportsmans = {
		{ "Ovechkin", 180, 110},
		{ "Chara", 186, 114},
		{ "Crosby", 180, 90},
		{ "Panarin", 180, 80}
	};

	Sportsman sportsman("", 2, 3);

	if (FindMax(sportsmans, sportsman, [](Sportsman const& lhs, Sportsman const& rhs)
	{
		return lhs.growth < rhs.growth;
	}))
	{
		std::cout <<  "name: " << sportsman.lfm << "\n"
			<< "growth: " << sportsman.growth << "\n"
			<< "weight: " << sportsman.weight << "\n";
	}
	
	Sportsman s("", 2, 3);

	if (FindMax(sportsmans, s, [](Sportsman const& lhs, Sportsman const& rhs)
	{
		return lhs.weight < rhs.weight;
	}))
	{
		std::cout <<  "name: " << s.lfm << "\n"
			<< "growth: " << s.growth << "\n"
			<< "weight: " << s.weight << "\n";
	}
	{
		std::cout << FindMax(sportsmans, sportsman) << std::endl;
		std::cout << sportsman << std::endl;
	}

	{
		std::vector<int> v = { 31, 2, 3, 4 };
		int maxValue = 0;
		if (FindMax(v, maxValue))
		{
			std::cout << "max value: " << maxValue << std::endl;
		}
		else
		{
			std::cout << "not found max element" << std::endl;;
		}
	}

    return 0;
}

