#include "CAddAccount.h"

#include <iostream>

std::string CAddAccount::commandName()
{
    return "create a new account";
}

void CAddAccount::execute(AccountsManager& manager)
{
    using namespace std;
    auto account = manager.createNewCompte();

    cout << "New account id " << account.getId() << " created with a balance of " << account.getMoney() << endl;;

}

CAddAccount::~CAddAccount()
{
}
