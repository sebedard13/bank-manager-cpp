#include "CShowAccount.h"

#include <iostream>

std::string CShowAccount::commandName()
{
	return "show account info by id";
}

void CShowAccount::execute(AccountsManager& manager)
{
	using namespace std;

	string id;
	cout << "Get id" << endl;
	cin >> id;
	if (manager.hasAccount(id))
	{
		auto account = manager.getCompte(id);
		cout << "id : " << account.getId() << ", balance : " << account.getMoney().toString() << endl;
	}
	else
	{
		cout << "Not a valid id" << endl;
	}
}
