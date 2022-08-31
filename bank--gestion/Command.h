#pragma once
#include <string>

#include "GestionCompte.h"

class Command
{
public:
	virtual std::string commandeName() = 0;

	virtual void execute(GestionCompte&) = 0;

	virtual ~Command();

};

