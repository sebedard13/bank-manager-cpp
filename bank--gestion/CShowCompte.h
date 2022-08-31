#pragma once

#include "Command.h"

class CShowCompte : public Command
{
public:
	CShowCompte();

	std::string commandeName() override;
	void execute(GestionCompte&) override;
	~CShowCompte() override;

private:
	static void showCompte(Compte);
};

