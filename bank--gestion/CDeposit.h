#pragma once
#include "Command.h"
class CDeposit :public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;
};

