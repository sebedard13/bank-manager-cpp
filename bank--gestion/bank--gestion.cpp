
#include <iostream>
#include <vector>

#include "Command.h"
#include "CListAccounts.h"
#include "AccountsManager.h"
#include "CShowAccount.h"

int main()
{
	using namespace std;

	AccountsManager manager = AccountsManager();
	manager.loadAccounts();

	auto commands = vector<unique_ptr<Command>>();

	commands.push_back(make_unique<CListAccounts>());
	commands.push_back(make_unique<CShowAccount>());

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
			cout << "Not a valid command" << std::endl;
		}
		else
		{
			commands.at(value)->execute(manager);
		}
		std::cout << std::endl;
	}
}

