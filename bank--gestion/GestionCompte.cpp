#include "GestionCompte.h"

void GestionCompte::loadCompte()
{

	Compte a = Compte("a", 0);
	Compte b = Compte("b", 200);
	Compte c = Compte("c", 35200);

	comptes.emplace(a.getId(), a);
	comptes.emplace(b.getId(), b);
	comptes.emplace(c.getId(), c);
}

void GestionCompte::forAll(void(*func)(Compte))
{
	for (auto element : comptes)
	{
		func(element.second);
	}
}

