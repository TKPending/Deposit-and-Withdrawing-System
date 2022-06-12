#include <iostream>
#include <cstdlib>

#include "PrintStatement.h"

bool validateChoice(char UserChoice);
char invalidChoice();

// User chooses to deposit or withdraw
// Checks whether user choice is valid or not
char userPickOption()
{
	// Ask user: Deposit or Withdraw
	std::cout << "Do you want to deposit or withdraw (D or W): ";
	char chosenOption{};
	std::cin >> chosenOption;

	// Check if answer is valid (d or w)
	bool checkUserDecision{ validateChoice(chosenOption) };

	// If answer is false, user chooses again
	if (checkUserDecision == false)
		chosenOption = invalidChoice();

	return chosenOption;
}

// If user chooses an invalid answer
char invalidChoice()
{
	char userSecondChoice{};

	// If answer isn't d or w, loop till out of tries
	for (int tries{ 2 }; userSecondChoice != 'd' && userSecondChoice != 'w' && userSecondChoice == 'x' && userSecondChoice == 'p'; --tries)
	{
		if (tries == 0)
			return 'x';

		std::cout << "You have " << tries << " left\n" << '\n';
		std::cout << "Invalid Answer.\nPlease Try Again...\n" << '\n';
		std::cout << "Do you want to deposit or withdraw (D or W): ";
		std::cin >> userSecondChoice;
	}
	return userSecondChoice;
}

// Checks if user choice is valid or not
bool validateChoice(char UserChoice)
{
	if (UserChoice == 'd' || UserChoice == 'w' || UserChoice == 'x' || UserChoice == 'p')
	{
		return true;
	}
	else
		return false;
}


// Declaring Functions To Deposit & Withdraw
void depositingFunds();
void withdrawalFunds();



// Runs everything
// User chooses option, program reacts
// Sends to deposit, withdraw or closes program.
void userOption()
{
	bool loopProgram{ true };
	while (loopProgram)
	{
		char userChoice = userPickOption();

		switch (userChoice)
		{
		case 'd':
			std::cout << '\n' << "Depositing....\n" << '\n';
			depositingFunds();
			break;
		case 'w':
			std::cout << '\n' << "Withdrawing\n" << '\n';
			withdrawalFunds();
			break;
		case 'p':
			BankStatement::printStatement();
			break;
		case 'x':
			loopProgram = false;
			break;
		default:
			std::exit(0);
		}
	}

	std::cout << '\n' << "Closing Program...\n";
}