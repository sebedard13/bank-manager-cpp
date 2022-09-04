#include "CTransfer.h"

#include <iostream>

std::string CTransfer::commandName() const
{
	return "transfer money between two accounts";
}

void CTransfer::execute(AccountsManager& manager)
{
	using namespace std;
	string idFrom;
	cout << "What account id you want to transfer from?" << endl;
	cin >> idFrom;
	if (!manager.hasAccount(idFrom))
	{
		cout << "Not a valid id" << endl;
		return;
	}
	string idTo;
	cout << "What account id you want to transfer to?" << endl;
	cin >> idTo;
	if (!manager.hasAccount(idTo))
	{
		cout << "Not a valid id" << endl;
		return;
	}

	Money amount;
	cout << "What is the amount you want to withdraw?" << endl;
	cin >> amount;
	Account& accountFrom = manager.getAccount(idFrom);
	Account& accountTo = manager.getAccount(idTo);
	const bool amountIsValid = amount.get() > 0 && accountFrom.getMoney().get() - amount.get() >= 0;

	if (amountIsValid)
	{
		accountFrom.subtractFromBalance(amount);
		accountTo.addToBalance(amount);

		cout << "The current balance of account id " << accountFrom.getId() << " is " << accountFrom.getMoney() << endl;
		cout << "The current balance of account id " << accountTo.getId() << " is " << accountTo.getMoney() << endl;
	}
	else
	{
		cout << "Amount is invalid" << endl;
	}
}
