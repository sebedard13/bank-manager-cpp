#pragma once

#include "Command.h"

class CListAccounts : public Command
{
public:
	CListAccounts() = default;

	std::string commandName() override;
	void execute(AccountsManager&) override;
	~CListAccounts() override;

private:
	static void listAccount(Account&);
};

