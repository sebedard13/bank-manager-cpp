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

	return str.insert(str.length() - 2, ".") + "$";
}

Money& Money::operator+=(const Money& right)
{
	this->value += right.value;
	return *this;
}

Money& Money::operator-=(const Money& right)
{
	this->value -= right.value;
	return *this;
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

std::istream& operator>>(std::istream& os, Money& money)
{
	double amount;
	os >> amount;

	money.set(round(amount * 100));
	return os;
}


