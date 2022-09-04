
#include <iostream>
#include <vector>

#include "Command.h"
#include "CListAccounts.h"
#include "CAddAccount.h"
#include "AccountsManager.h"
#include "CShowAccount.h"
#include "CDeleteAccount.h"
#include "CDeposit.h"
#include "CTransfer.h"
#include "CWithdrawal.h"

int main()
{
	using namespace std;

	AccountsManager manager{};
	manager.loadAccounts();

	vector<unique_ptr<Command>> commands{};

	commands.push_back(make_unique<CListAccounts>());
	commands.push_back(make_unique<CShowAccount>());
	commands.push_back(make_unique<CAddAccount>());
	commands.push_back(make_unique<CDeposit>());
	commands.push_back(make_unique<CWithdrawal>());
	commands.push_back(make_unique<CTransfer>());
	commands.push_back(make_unique<CDeleteAccount>());

	std::string a{ "aa" };

	bool run = true;
	while (run)
	{
		for (int i = 0; i < commands.size(); ++i)
		{
			cout << "Press " << i << " to " << commands.at(i)->commandName() << endl;
		}

		cout << "Press " << commands.size() << " to quit" << endl;

		int value;
		cin >> value;
		if (value == commands.size())
		{
			run = false;
		}
		else if (value<0 || value>commands.size())
		{
			cout << "Not a valid command" << endl;
		}
		else
		{
			commands.at(value)->execute(manager);
		}
		cout << endl;
		cin.clear();
	}
}

