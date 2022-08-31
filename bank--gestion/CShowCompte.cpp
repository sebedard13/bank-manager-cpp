#include "CShowCompte.h"

#include <iostream>

CShowCompte::CShowCompte()
{
}

std::string CShowCompte::commandeName()
{
	return "Show all acounts";
}

void CShowCompte::execute(GestionCompte& comptes)
{
	comptes.forAll(showCompte);
}

CShowCompte::~CShowCompte()
{
}


void CShowCompte::showCompte(Compte compte)
{
	std::cout << "Compte id " + compte.getId() + ", money " + compte.getMoney().toString() + "\n";
}
