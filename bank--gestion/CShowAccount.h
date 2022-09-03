#pragma once
#include "Command.h"

class CShowAccount : public Command
{
public:
	std::string commandName() const override;
	void execute(AccountsManager&) override;
};

