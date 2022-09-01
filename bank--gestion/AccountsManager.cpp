#include "AccountsManager.h"

#include <algorithm>

void AccountsManager::loadAccounts()
{

	Account a = Account("a", 0);
	Account b = Account("b", 200);
	Account c = Account("c", 35200);

	comptes.emplace(a.getId(), a);
	comptes.emplace(b.getId(), b);
	comptes.emplace(c.getId(), c);
}

Account AccountsManager::createNewCompte()
{
	return Account("aff", 0);
}

bool AccountsManager::hasAccount(std::string id) const
{
	return comptes.find(id) != comptes.end();
}

Account AccountsManager::getCompte(std::string value) const
{
	return comptes.at(value);
}

void AccountsManager::forAll(void(*func)(Account&))
{
	std::for_each(comptes.begin(), comptes.end(), [&](std::pair<std::string, Account> p)
		{
			func(p.second);
		});
}

