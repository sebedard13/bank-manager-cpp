#pragma once
#include "Command.h"
class CTransfer :
	public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;
};

