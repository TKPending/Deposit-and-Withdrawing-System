#include <iostream>
#include <cstdlib>
#include "UserOriginalDeposit.h"
#include "UserOption.h"

// Welcome user
void welcoming()
{
	std::cout << "Welcome to the bank\n";
	std::cout << "Will be allowed to deposit and withdraw money\n" << '\n';
}

// Declaraing Beginning Account Balance
double accountBalance{ 0 };

int main()
{
	// Welcome User to program
	welcoming();

	// User adds original account balance
	accountBalance = UserOriginalDeposit::deposit(accountBalance);

	// Continue with program or close program
	if (accountBalance == 0)
		std::exit(0);
	else
		userOption();

	return 0;
}