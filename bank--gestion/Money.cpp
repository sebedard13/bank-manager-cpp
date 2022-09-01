#include "Money.h"

#include <iostream>

void Money::modify(const int value)
{
	this->value += value;
}

std::string Money::toString() const
{
	using namespace std;
	auto str = to_string(value);

	while (str.length() < 3)
	{
		str.insert(0, "0");
	}

	return str.insert(str.length() - 2, ".");
}

void Money::set(const int value)
{
	this->value = value;
}

std::ostream& operator<<(std::ostream& os, const Money& money)
{
	os << money.toString();
	return os;
}


