#pragma once
#include <map>
#include <string>
#include "Account.h"


class AccountsManager
{
public:
	void loadAccounts();
	Account createNewCompte();
	bool hasAccount(std::string id) const;
	Account getCompte(std::string id) const;
	void forAll(void (*func)(Account&));

private:
	std::map<std::string, Account> comptes = std::map<std::string, Account>();
};

