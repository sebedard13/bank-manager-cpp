#pragma once
#include <map>
#include <string>
#include "Compte.h"


class GestionCompte
{
public:
	void loadCompte();
	Compte createNewCompte();
	Compte getCompte(std::string)const;
	void forAll(void (*func)(Compte));

private:
	std::map<std::string, Compte> comptes = std::map<std::string, Compte>();
};

