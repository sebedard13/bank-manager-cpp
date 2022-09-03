#pragma once
#include <string>

class Money
{
public:
	void set(const int value);

	const long long int& get() const;

	const std::string toString() const;

private:
	long long int value = 0;
};

std::ostream& operator<<(std::ostream& os, const Money& money);
