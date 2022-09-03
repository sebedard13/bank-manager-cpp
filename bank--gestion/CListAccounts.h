#pragma once

#include "Command.h"

class CListAccounts : public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;

private:
	static void listAccount(Account&);
};

