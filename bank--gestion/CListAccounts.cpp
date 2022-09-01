#include "CListAccounts.h"

#include <iostream>

std::string CListAccounts::commandName()
{
	return "list all acount ids";
}

void CListAccounts::execute(AccountsManager& manager)
{
	std::cout << "Account id " << std::endl;
	manager.forAll(listAccount);
}

CListAccounts::~CListAccounts()
{
}

void CListAccounts::listAccount(Account& account)
{
	std::cout << account.getId() << std::endl;
}
