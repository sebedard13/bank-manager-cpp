#include "AccountsManager.h"

#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>

void AccountsManager::loadAccounts()
{
	using namespace  std;
	ifstream file(path);
	if (file.good())
	{
		string line;
		getline(file, line);
		maxid = stoi(line);

		while (getline(file, line))
		{
			string id{ line };
			getline(file, line);
			long long money = stoll(line);
			accounts.emplace(id, Account{ id,money });
		}
	}
	file.close();
}

void AccountsManager::saveAccounts()
{
	using namespace  std;
	ofstream file(path);
	if (file.good())
	{

		file << maxid << endl;

		for (auto& account : accounts)
		{
			file << account.second.getId() << endl;
			file << account.second.getMoney().get() << endl;
		}
	}
	file.close();
}

Account& AccountsManager::createNewAccount()
{
	maxid++;
	std::stringstream stream;
	stream << "0x"
		<< std::setfill('0') << std::setw(3)
		<< std::hex << maxid;
	const auto idHex = stream.str();
	const auto id = idHex.substr(2, idHex.length());

	auto account = Account(id, 0);

	const auto pair = accounts.emplace(id, account);

	return pair.first->second;
}

void AccountsManager::deleteAccount(const std::string& id)
{
	accounts.erase(id);
}

bool AccountsManager::hasAccount(const std::string& id) const
{
	return accounts.find(id) != accounts.end();
}

Account& AccountsManager::getAccount(const std::string& value)
{
	return accounts.at(value);
}

const Account& AccountsManager::getAccountC(const std::string& id) const
{
	return accounts.at(id);
}

void AccountsManager::forAll(void (func)(Account&))
{
	std::for_each(accounts.begin(), accounts.end(), [&](std::pair<std::string, Account> p)
		{
			func(p.second);
		});
}

