#pragma once
#include <map>
#include <string>
#include "Account.h"


class AccountsManager
{
public:
	void loadAccounts();
	void saveAccounts();
	Account& createNewAccount();
	void deleteAccount(const std::string& id);
	bool hasAccount(const std::string& id) const;
	Account& getAccount(const std::string& id);
	const Account& getAccountC(const std::string& id) const;
	void forAll(void (func)(Account&));

private:
	short maxid{ 0 };
	std::map<std::string, Account> accounts{  };
	const std::string path{ "bankSave.txt" };
};

