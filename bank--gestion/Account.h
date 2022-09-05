#pragma once
#include <string>

#include "Money.h"


class Account
{
public:
	Account(const std::string& id, const int money);
	Account(const std::string& id, const long long money);

	const std::string& getId() const;


	void addToBalance(const Money& value);
	void subtractFromBalance(const Money& value);

	const Money& getMoney() const;


private:
	std::string id;
	Money money;
};

