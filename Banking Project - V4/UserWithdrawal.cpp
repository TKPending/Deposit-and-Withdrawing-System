#include "UserWithdrawal.h"
#include <iostream>

extern double accountBalance;
double withdrawalRequest();
double validateWithdrawal(double WithdrawalAmount);

// Withdraw Amount
void withdrawalFunds()
{
	double withdrawalAmount{ withdrawalRequest() };

	// Update account balance
	accountBalance -= withdrawalAmount;
}

// Break loop or continue looping
bool endRequest(double WithdrawalAmount)
{
	if (WithdrawalAmount < accountBalance)
		return false;
	else
		return true;
}

// Process of withdrawing
double withdrawalRequest()
{
	bool withdrawalAlert{ true };
	double withdrawalAmount{};

	while (withdrawalAlert)
	{
		// How much user wants to withdraw
		double withdrawalAmountRequest{};
		withdrawalAmountRequest = CoinWithdrawal::withdrawalAmount();

		// Check the withdrawal amount 
		withdrawalAmount = validateWithdrawal(withdrawalAmountRequest);
		withdrawalAlert = endRequest(withdrawalAmount);
	}
	return withdrawalAmount;
}

// Validate the withdrawal amount
double validateWithdrawal(double WithdrawalAmount)
{
	for (int count{ 2 }; WithdrawalAmount > accountBalance; --count)
	{
		// Attempts
		if (count == 0)
		{
			std::cout << "You won't be able to withdraw anything...\n" << '\n';
			WithdrawalAmount = 0;
			break;
		}
			
		// Show how the user entered an incorrect amount
		std::cout << "Invalid Amount\n" << '\n';
		std::cout << "Your account balance is $" << accountBalance << ", you tried to withdraw $" << WithdrawalAmount;
		double overLimit{ WithdrawalAmount - accountBalance };
		std::cout << '\n' << "You are $" << overLimit << " over the limit\n" << '\n';

		// User try again
		std::cout << "You have " << count << " attempts left\n" <<  '\n';
		WithdrawalAmount = CoinWithdrawal::withdrawalAmount();
	}

	// Return the withdrawal amount
	std::cout << "Withdrawing $" << WithdrawalAmount << '\n';
	return WithdrawalAmount;
}