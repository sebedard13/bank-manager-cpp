#include "Account.h"

Account::Account(const std::string& id, const int money)
{
	this->id = id;
	this->money.set(money);
}

const std::string& Account::getId() const
{
	return this->id;
}

void Account::addToBalance(const int& value)
{
	money.set(money.get() + value);
}

const Money& Account::getMoney() const
{
	return money;
}
