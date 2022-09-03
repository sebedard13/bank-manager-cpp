#include "Money.h"

#include <iostream>

const std::string Money::toString() const
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

const long long& Money::get() const
{
	return value;
}

std::ostream& operator<<(std::ostream& os, const Money& money)
{
	os << money.toString();
	return os;
}


