#include "AccountsManager.h"

#include <algorithm>
#include <sstream>
#include <iomanip>

void AccountsManager::loadAccounts()
{

	Account& a { createNewCompte()};
	Account& b { createNewCompte()};
	Account& c { createNewCompte()};

	a.getMoney().set(2);
		b.getMoney().set(200);
		c.getMoney().set(10);
}

Account& AccountsManager::createNewCompte()
{
	maxid++;
	std::stringstream stream;
	stream << "0x"
		<< std::setfill('0') << std::setw(3)
		<< std::hex << maxid;
	auto idHex= stream.str();
	auto id = idHex.substr(2, idHex.length());

	auto account = Account(id, 0);

	auto pair = comptes.emplace(id, account);

	return pair.first->second;
}

void AccountsManager::deleteAccount(std::string const id)
{
	comptes.erase(id);
}

bool AccountsManager::hasAccount(std::string id) const
{
	return comptes.find(id) != comptes.end();
}

Account& AccountsManager::getCompte(std::string value)
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

