#pragma once
#include <string>

class Money
{
public:
	Money() = default;

	explicit Money(long long value) : value(value)
	{
	}

	void set(const int value);
	void set(const long long value);

	const long long int& get() const;

	const std::string toString() const;

	Money& operator+=(const Money&);
	Money& operator-=(const Money&);

private:
	long long int value = 0;
};

std::ostream& operator<<(std::ostream& os, const Money& money);
std::istream& operator>>(std::istream& os, Money& money);

