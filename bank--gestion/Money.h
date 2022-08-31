#pragma once
#include <string>

class Money
{
public:
	void set(const int value);
	void modify(const int value);

	std::string toString();
private:
	long long int value = 0;
};

