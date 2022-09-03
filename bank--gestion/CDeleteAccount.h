#pragma once
#include "Command.h"

class CDeleteAccount : public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;
};

