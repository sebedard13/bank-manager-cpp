#include "CDeleteAccount.h"

#include <iostream>

std::string CDeleteAccount::commandName() const
{
	return "delete an account by id";
}

void CDeleteAccount::execute(AccountsManager& manager)
{
	using namespace std;
	cout << "What is the account id you want to delete?" << endl;
	string id;
	cin >> id;

	if (manager.hasAccount(id)) {
		cout << "Are you sure you want to delete account id " << id << "?" << endl;
		cout << "Rewrite the account id to confirm" << endl;
		string idConfirm;
		cin >> idConfirm;
		if (id == idConfirm) {
			manager.deleteAccount(id);
			cout << "Account id " << id << " was deleted" << endl;
		}
		else
		{
			cout << "Abort delete account id " << id << endl;
		}
	}
	else {
		cout << "Account id not found" << endl;
	}


}
