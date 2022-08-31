
#include <iostream>
#include <vector>

#include "Command.h"
#include "CShowCompte.h"
#include "GestionCompte.h"

int main()
{
	using namespace std;

	GestionCompte comptes = GestionCompte();
	comptes.loadCompte();

	auto commands = vector<unique_ptr<Command>>();

	commands.push_back(make_unique<CShowCompte>());


	commands.front()->execute(comptes);


}

