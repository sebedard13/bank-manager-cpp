#include "Account.h"

Account::Account(const std::string& id, const int money)
{
	this->id = id;
	this->money.set(money);
}

Account::Account(const std::string& id, const long long money)
{
	this->id = id;
	this->money.set(money);
}

const std::string& Account::getId() const
{
	return this->id;
}

void Account::addToBalance(const Money& value)
{
	money += value;
}

void Account::subtractFromBalance(const Money& value)
{
	money -= value;
}

const Money& Account::getMoney() const
{
	return money;
}
