#include <iostream>

namespace CoinWithdrawal
{
	double withdrawAmountRequest(double CoinAmount);

	// Calculate Withdrawal Amount
	double withdrawalAmount()
	{
		double fiftyP{ withdrawAmountRequest(0.50) };
		double onePound{ withdrawAmountRequest(1.00) };
		double twoPound{ withdrawAmountRequest(2.00) };
		double fivePound{ withdrawAmountRequest(5.00) };
		double tenPound{ withdrawAmountRequest(10.00) };

		// Return Withdrawal Amount
		return fiftyP + onePound + twoPound + fivePound + tenPound;
	}

	// How many coins does user want to withdraw
	double withdrawAmountRequest(double CoinAmount)
	{
		std::cout << "How many $" << CoinAmount << " do you want to withdraw: ";
		int howManyCoins{};
		std::cin >> howManyCoins;

		// If user enters number < 0, then we will just count that as 0
		if (howManyCoins < 0)
		{
			std::cout << '\n' << "This will be represented as 0\n" << '\n';
			howManyCoins = 0;
		}

		std::cout << '\n';

		// Return Coin Amount
		return CoinAmount * howManyCoins;
	}
}