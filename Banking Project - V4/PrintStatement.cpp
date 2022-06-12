#include <iostream>

// Current Account Balance
extern double accountBalance;


// Print the user bank statement
namespace BankStatement
{
	void printStatement()
	{
		std::cout << '\n' << "Your current account balance is $" << accountBalance << '\n' << '\n';
	}
}
