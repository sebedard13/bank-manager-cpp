#pragma once
#include <string>

class Money
{
public:
	void set(const int value);
	void modify(const int value);

	std::string toString() const;

private:
	long long int value = 0;
};

std::ostream& operator<<(std::ostream& os, const Money& money);
