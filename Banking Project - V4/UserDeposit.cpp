#include <iostream>
#include <cstdlib>
#include "UserOriginalDeposit.h"

extern double accountBalance;

#define MIN_DEPOSIT 1

bool validateUserDeposit(double DepositAmount);

// Ask user how much they want to deposit
double depositAmount()
{
	double userDepositAmount{};

	for (int count{ 2 }; userDepositAmount < 1; --count)
	{
		// Attempts
		if (count < 0)
			break;

		// Calculate the Deposit Amount
		userDepositAmount = CoinDeposit::depositAmount();
		
		// Check if deposit amount is valid
		bool validityOfDeposit{ validateUserDeposit(userDepositAmount) };
		if (validityOfDeposit == true)
			break;
		else
		{
			if (count == 0)
				break;
			else
				std::cout << "You have " << count << " attempts left.\n";
		}
	}

	if (userDepositAmount < 1)
		// If Amount == 0 then return no amount
		userDepositAmount = 0;

	std::cout << '\n' << "Depositing $" << userDepositAmount << "...";

	// Return the deposit amount
	return userDepositAmount;
}

// Deposit Amount
void depositingFunds()
{
	accountBalance += depositAmount();
}

// Validate Deposit Amount
bool validateUserDeposit(double DepositAmount)
{
	if (DepositAmount <= MIN_DEPOSIT)
	{
		std::cout << '\n' << "Invalid Amount\n" << '\n';
		return false;
	}
	else
		return true;
}
