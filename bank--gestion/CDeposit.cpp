#include "CDeposit.h"

#include <iostream>

std::string CDeposit::commandName() const
{
	return "deposit money in an account";
}

void CDeposit::execute(AccountsManager& manager)
{
	using namespace std;
	string id;
	cout << "What account id you want to deposit in?" << endl;
	cin >> id;
	if (manager.hasAccount(id))
	{
		Money amount;
		cout << "What is the amount you want to deposit?" << endl;
		cin >> amount;
		Account& account = manager.getAccount(id);
		const bool amountIsValid = amount.get() > 0;
		if (amountIsValid)
		{

			account.addToBalance(amount);

			cout << "The current balance of account id " << account.getId() << " is " << account.getMoney() << endl;
		}
		else
		{
			cout << "Amount is invalid" << endl;
		}

	}
	else
	{
		cout << "Not a valid id" << endl;
	}


}
