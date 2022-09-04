#include "CWithdrawal.h"

#include <iostream>

std::string CWithdrawal::commandName() const
{
	return "withdraw money in an account";
}

void CWithdrawal::execute(AccountsManager& manager)
{
	using namespace std;
	string id;
	cout << "What account id you want to withdraw from?" << endl;
	cin >> id;
	if (manager.hasAccount(id))
	{
		Money amount;
		cout << "What is the amount you want to withdraw?" << endl;
		cin >> amount;
		Account& account = manager.getAccount(id);
		const bool amountIsValid = amount.get() > 0 && account.getMoney().get() - amount.get() >= 0;

		if (amountIsValid)
		{
			account.subtractFromBalance(amount);

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
