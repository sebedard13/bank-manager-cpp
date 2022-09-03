#include "CShowAccount.h"

#include <iostream>

std::string CShowAccount::commandName() const
{
	return "show account info by id";
}

void CShowAccount::execute(AccountsManager& manager)
{
	using namespace std;

	string id;
	cout << "Account id you want to get info" << endl;
	cin >> id;
	if (manager.hasAccount(id))
	{
		const auto& account = manager.getAccount(id);
		cout << "id : " << account.getId() << ", balance : " << account.getMoney().toString() << endl;
	}
	else
	{
		cout << "Not a valid id" << endl;
	}
}
