#pragma once
#include <map>
#include <string>
#include "Account.h"


class AccountsManager
{
public:
	void loadAccounts();
	Account& createNewCompte();
	bool hasAccount(std::string id) const;
	Account& getCompte(std::string id);
	void forAll(void (*func)(Account&));

private:
	short maxid {0};
	std::map<std::string, Account> comptes = std::map<std::string, Account>();
};

