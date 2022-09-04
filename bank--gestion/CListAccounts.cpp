#include "CListAccounts.h"

#include <iostream>

std::string CListAccounts::commandName() const
{
	return "list all account ids and balance";
}

void CListAccounts::execute(AccountsManager& manager)
{
	std::cout << "Account id" << std::endl;
	manager.forAll(listAccount);
}

void CListAccounts::listAccount(Account& account)
{
	std::cout << account.getId() << " | " << account.getMoney() << std::endl;
}
