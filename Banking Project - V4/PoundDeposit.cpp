#include <iostream>

// The amount of coins the user wants to deposit
namespace CoinDeposit
{
	double depositAmountRequest(double CoinAmount);

	double depositAmount()
	{
		// Find each individual amounts
		double fiftyP{ depositAmountRequest(0.50) };
		double onePound{ depositAmountRequest(1.00) };
		double twoPound{ depositAmountRequest(2.00) };
		double fivePound{ depositAmountRequest(5.00) };
		double tenPound{ depositAmountRequest(10.00) };

		// Return the deposit amount
		return fiftyP + onePound + twoPound + fivePound + tenPound;
	}

	// Calculate how much the user wants to deposit
	double depositAmountRequest(double CoinAmount)
	{
		std::cout << "How many $" << CoinAmount << " do you want to deposit: ";
		int howManyCoins{};
		std::cin >> howManyCoins;

		if (howManyCoins < 0)
		{
			std::cout << '\n' << "This will be represented as 0\n" << '\n';
			howManyCoins = 0;
		}

		std::cout << '\n';

		return CoinAmount * howManyCoins;
	}
}