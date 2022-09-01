#pragma once
#include "Command.h"

class CShowAccount : public Command
{
public:
	std::string commandName() override;
	void execute(AccountsManager&) override;
	~CShowAccount() = default;
};

