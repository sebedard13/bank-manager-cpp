#pragma once

#include "Command.h";
class CAddAccount : public Command
{
public:
	std::string commandName() const override;

	void execute(AccountsManager& manager) override;
};

