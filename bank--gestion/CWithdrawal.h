#pragma once
#include "Command.h"
class CWithdrawal :public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;
};

