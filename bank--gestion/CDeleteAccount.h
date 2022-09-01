#pragma once
#include "Command.h"

class CDeleteAccount : public Command
{
public:
	virtual std::string commandName() override;
	virtual void execute(AccountsManager&) override;
};

