#pragma once
#include <string>

#include "Money.h"


class Compte
{
public:
	Compte(const std::string& id, const int money) : id(id)
	{
		this->money.set(money);
	}

	std::string getId() const
	{
		return id;
	}

	Money getMoney() const
	{
		return money;
	}

private:
	std::string id;
	Money money;
};

