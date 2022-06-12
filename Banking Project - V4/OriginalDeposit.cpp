#include <iostream>
#include <cstdlib>

#define MIN_DEPOSIT 1
#define MAX_DEPOSIT 10000

// Introduce the original deposit rules
void depositRules()
{
	std::cout << "You can only deposit between $1 and $10,000\n";
	std::cout << "NOTE: If you enter the wrong value 3 times, the program will close\n" << '\n';
}

namespace UserOriginalDeposit
{
	// Deposit Amount
	double depositProcess()
	{
		double depositAmount{};
		std::cin >> depositAmount;

		return depositAmount;
	}

	// Requesting Deposit Amount
	double userRequestedDeposit(int Attempts)
	{
		// First Deposit Attempt
		if (Attempts == 3)
		{
			std::cout << "How much do you want to deposit: $";
			return depositProcess();
		}
		// Second+ Deposit Attempt
		else
		{
			std::cout << "Invalid Deposit Amount\nPlease try again...\n" << '\n';
			std::cout << "How much do you want to deposit: $";
			return depositProcess();
		}
	}

	// Validating Deposit Amount
	double validityDepositRequest()
	{
		// First Deposit Attempt
		int depositAttempts{ 3 };
		double depositRequest{ userRequestedDeposit(depositAttempts) };
		--depositAttempts;

		// If invalid we run through this
		for (; depositRequest < MIN_DEPOSIT || depositRequest > MAX_DEPOSIT || depositAttempts <= 0; --depositAttempts)
		{
			if (depositAttempts > 0)
			{  // User Deposit Amount
				std::cout << "You have " << depositAttempts << " left.\n" << '\n';
				depositRequest = userRequestedDeposit(depositAttempts);
			}
			else
				// Return nothing
				return 0;
		}

		// Return the Deposit Amount
		return depositRequest;
	}

	// Depositing into Account
	double deposit(double AccountBalance)
	{
		// Get Deposit Amount
		double depositAmount{ validityDepositRequest() };

		// Update Account Balance
		return AccountBalance += depositAmount;
	}
}
