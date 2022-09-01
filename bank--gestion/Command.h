#pragma once
#include <string>

#include "AccountsManager.h"

class Command
{
public:
	virtual std::string commandName() = 0;

	virtual void execute(AccountsManager&) = 0;

	virtual ~Command() = default;

};

