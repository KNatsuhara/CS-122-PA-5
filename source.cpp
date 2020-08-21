#include "header.h"

/*
Function: printCard(Card data)
Date Created: 3/27/2020
Description: Given the card data, this function will print out the card data accordingly
Input Parameters: void
Returns: void
*/
void printCard(Card data)
{
	cout << endl;
	cout << "Name: " << data.name << endl << "Level: " << data.level << endl << "Type: " << data.type << endl;
	cout << "Attack Points: " << data.attackPoints << endl << "Defense Points: " << data.defensePoints << endl;
	cout << endl;
}

/*
Function: selectCard()
Date Created: 3/27/2020
Description: Continues to prompt the user for a number between 1 and 5
Input Parameters: void
Returns: Integer (1-5)
*/
int selectCard()
{
	int option;
	do
	{
		cin >> option;
	} while (option < 1 || option > 5);
	return option;
}

/*
Function: selectQueue()
Date Created: 3/27/2020
Description: Continues to prompt the user for a number between 1 and 2
Input Parameters: void
Returns: Integer (1-2)
*/
int selectQueue()
{
	int option;
	do
	{
		cin >> option;
	} while (option < 1 || option > 2);
	return option;
}

/*
Function: randomNumber()
Date Created: 3/27/2020
Description: Will return a random integer that is either 1 or 2
Input Parameters: void
Returns: Integer 1 or 2
*/
int randomNumber()
{
	int i = 0;
	i = rand() % 2 + 1;
	return i;
}

/*
Function: printMenu()
Date Created: 3/27/2020
Description: Will print out the main menu for the players in Yu-gi-oh
Input Parameters: void
Returns: void
*/
void printMenu()
{
	cout << "========== Welcome to Yu-Gi-Oh! ==========\n";
	cout << "1. Create Players\n";
	cout << "2. Add Cards to a Player\n";
	cout << "3. Trade Cards with other Player\n";
	cout << "4. Battle other Player\n";
	cout << "5. Exit Game\n";
}

/*
Function: getOption()
Date Created: 3/27/2020
Description: Will prompt the user with the main menu until the user gives a valid option within the menu constraints
Input Parameters: void
Returns: Integer (1-5)
*/
int getOption()
{
	int option = NULL;
	do
	{
		system("PAUSE");
		system("CLS");
		printMenu();
		cout << "What option do you want to select?: ";
		cin >> option;
	} while (option < 1 || option > 5);
	return option;
}

/*
Function: addCardOption()
Date Created: 3/27/2020
Description: Prompts the user on which player they should add a card to
Input Parameters: void
Returns: Integer (1-2)
*/
int addCardOption()
{
	int option = NULL;
	do
	{
		cout << "Which player do you want to add cards to?: ";
		cin >> option;
	} while (option < 1 || option > 2);
	return option;
}