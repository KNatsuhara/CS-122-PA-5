#pragma once
#include "player.h"
#include <iostream>

using namespace std;

/*
Function: Player()
Date Created: 3/27/2020
Description: Constructor for player class, sets lifepoints to 8000
Input Parameters: void
Returns: Instantiated player object
*/
Player::Player()
{
	lifePoints = 8000;
}

/*
Function: fillDeck(int player)
Date Created: 3/27/2020
Description: Depending on the player (integer parameter) this function will fill a player object's deck with 36 cards by reading a
specific csv file.
Input Parameters: void
Returns: void
*/
void Player::fillDeck(int player)
{
	char buffer[256];
	char newLine[50];
	char* tok;
	int level = 0;
	char type[50];
	int attack = 0;
	int defense = 0;
	Card data;

	fstream dataFile; //opens csv file

	if (player == 1) //determines which selection of cards to choose from depending on player
	{
		dataFile.open("cards.csv", ios::in);
	}
	if(player == 2)
	{
		dataFile.open("cards2.csv", ios::in);
	}


	if (!dataFile.is_open()) //Checks if file opened
	{
		cout << "Card file did not open!\n";
	}


	for (int i = 0; i < 36; i++)
	{
		dataFile.getline(buffer, 100);
		tok = strtok(buffer, ","); //Gets the Name of the card
		strcpy(newLine, tok);
		data.name = newLine; //Setting name

		tok = strtok(NULL, ","); //Gets the level of the card
		level = stoi(tok);
		data.level = level; //Setting level

		tok = strtok(NULL, ","); //Gets the type of the card
		strcpy(type, tok);
		data.type = type; //Setting type

		tok = strtok(NULL, ","); //Gets the attack points
		attack = stoi(tok);
		data.attackPoints = attack; //Setting attack pts

		tok = strtok(NULL, ","); //Gets the defense points
		defense = stoi(tok);
		data.defensePoints = defense; //Setting defense pts

		deck.push(data); //Adds the card data to the deck/stack
	}
	
	dataFile.close(); //Closes file 
}

/*
Function: printDeck()
Date Created: 3/27/2020
Description: Will print out a players deck by calling upon displayStack()
Input Parameters: void
Returns: void
*/
void Player::printDeck()
{
	deck.displayStack();
}

/*
Function: fillHand()
Date Created: 3/27/2020
Description: Will automatically check and see if a player's hand is missing cards and fill up the cards by drawing from the players deck
Input Parameters: void
Returns: void
*/
void Player::fillHand()
{
	Card data;

	for (int i = 0; i < 5; i++)
	{
		if (hand[i].name == "")
		{
			data = deck.pop();
			hand[i].name = data.name;
			hand[i].type = data.type;
			hand[i].level = data.level;
			hand[i].attackPoints = data.attackPoints;
			hand[i].defensePoints = data.defensePoints;
		}
	}
}

/*
Function: displayHand()
Date Created: 3/27/2020
Description: Will display the player's hand
Input Parameters: void
Returns: void
*/
void Player::displayHand()
{
	for (int i = 0; i < 5; i++)
	{
		cout << "=========================================\n";
		cout << "INDEX: " << i+1 << endl;
		cout << "Name: " << hand[i].name << endl << "Level: " << hand[i].level << endl << "Type: " << hand[i].type << endl;
		cout << "Attack Points: " << hand[i].attackPoints << endl << "Defense Points: " << hand[i].defensePoints << endl;
	}
}

/*
Function: setAtkQ()
Date Created: 3/27/2020
Description: This function will prompt the user to choose which card to add to the atk queue and do so accordingly
Input Parameters: void
Returns: void
*/
void Player::setAtkQ()
{
	displayHand();
	Card data;
	int index = NULL;
	cout << "What card do want to put in the Attack Queue?: ";
	index = selectCard();
	index--;
	
	data = hand[index];
	attackQ.enqueue(data);

	hand[index] = {"", NULL };
}

/*
Function: setDefQ()
Date Created: 3/27/2020
Description: This function will prompt the user to choose which card to add to the def queue and do so accordingly
Input Parameters: void
Returns: void
*/
void Player::setDefQ()
{
	displayHand();
	Card data;
	int index = NULL;
	cout << "What card do want to put in the Defense Queue?: ";
	index = selectCard();
	index--;

	data = hand[index];
	defenseQ.enqueue(data);

	hand[index] = {"", NULL };
}

/*
Function: printAtkQ()
Date Created: 3/27/2020
Description: This function will print out the first card in the attack queue by dequeueing
Input Parameters: void
Returns: Card
*/
Card Player::printAtkQ()
{
	Card data;
	attackQ.dequeue(data);
	printCard(data);
	return data;
}

/*
Function: printdefQ()
Date Created: 3/27/2020
Description: This function will print out the first card in the defense queue by dequeueing
Input Parameters: void
Returns: Card
*/
Card Player::printDefQ()
{
	Card data;
	defenseQ.dequeue(data);
	printCard(data);
	return data;
}

/*
Function: playerAlive()
Date Created: 3/27/2020
Description: Will check if the player is below 0 life points, if the player is below 0, return false, else return true
Input Parameters: void
Returns: boolean
*/
bool Player::playerAlive()
{
	bool alive = true;
	if (lifePoints <= 0)
	{
		alive = false;
	}
	return alive;
}

/*
Function: battlePhase(Player p2)
Date Created: 3/27/2020
Description: Requires two player objects and requires both player's decks to be filled beforehand. In this function, the players
battle each other with their cards and lose life points based on the rules of the game. The game goes on until a player's life points
goes below 0;
Input Parameters: void
Returns: void
*/
void Player::battlePhase(Player p2) //Precondition: Player's deck needs to be filled beforehand
{
	int coin;
	int p1Fight = 0;
	int p2Fight = 0;
	Card p1Card;
	Card p2Card;
	cout << "---------------------------------------------\n";
	cout << "*************LET THE DUEL BEGIN!*************\n";
	cout << "---------------------------------------------\n";
	cout << endl << endl;

	fillHand(); //Sets up each players hands
	p2.fillHand();

	coin = randomNumber(); //Decides who goes first

	while (playerAlive() && p2.playerAlive()) //While loop until a player's life points go below 0
	{
		cout << "================Player 1's Hand ================\n";
		setAtkQ(); //asks player 1 to setup their queues
		system("PAUSE");
		system("CLS");
		cout << "================Player 1's Hand ================\n";
		setDefQ();
		system("PAUSE");
		system("CLS");
		fillHand(); //refills player 1's hand

		cout << "================Player 2's Hand ================\n";
		p2.setAtkQ(); //asks player 2 to setup their queues
		system("PAUSE");
		system("CLS");
		cout << "================Player 2's Hand ================\n";
		p2.setDefQ();
		system("PAUSE");
		system("CLS");
		p2.fillHand(); //refills player 2's hand

		if (coin == 1)
		{
			cout << "========= Player 1 goes first =========\n";
			cout << "Player 1: Do you want to attack = 1 or defend = 2?: ";
			p1Fight = selectQueue();
			if (p1Fight == 1)
			{
				p1Card = printAtkQ(); //dequeues card from attack queue
				cout << "Player 1 chooses " << p1Card.name << " in attack mode!\n";
			}
			else
			{
				p1Card = printDefQ(); //dequeues card from defense queue
				cout << "Player 1 chooses " << p1Card.name << " in defense mode!\n";
			}

			cout << "Player 2: Do you want to attack = 1 or defend = 2?: ";
			p2Fight = selectQueue();
			if (p2Fight == 1)
			{
				p2Card = p2.printAtkQ(); //dequeues card from attack queue
				cout << "Player 2 chooses " << p2Card.name << " in attack mode!\n";
			}
			else
			{
				p2Card = p2.printDefQ(); //dequeues card from defense queue
				cout << "Player 2 chooses " << p2Card.name << " in defense mode!\n";
			}
		}
		else
		{
			cout << "========= Player 2 goes first =========\n";
			cout << "Player 2: Do you want to attack = 1 or defend = 2?: ";
			p2Fight = selectQueue();
			if (p2Fight == 1)
			{
				p2Card = p2.printAtkQ(); //dequeues card from attack queue
				cout << "Player 2 chooses " << p2Card.name << " in attack mode!\n";
			}
			else
			{
				p2Card = p2.printDefQ(); //dequeues card from defense queue
				cout << "Player 2 chooses " << p2Card.name << " in defense mode!\n";
			}

			cout << "Player 1: Do you want to attack = 1 or defend = 2?: ";
			p1Fight = selectQueue();
			if (p1Fight == 1)
			{
				p1Card = printAtkQ(); //dequeues card from attack queue
				cout << "Player 1 chooses " << p1Card.name << " in attack mode!\n";
			}
			else
			{
				p1Card = printDefQ(); //dequeues card from defense queue
				cout << "Player 1 chooses " << p1Card.name << " in defense mode!\n";
			}
		}

		if (p1Fight == 1 && p2Fight == 1)
		{
			//Both attack, whoever has the highest attack wins
			if (p1Card.attackPoints > p2Card.attackPoints) //p1 has a higher attack
			{
				p2.setLifePoints(p2.getLifePoints() - (p1Card.attackPoints - p2Card.attackPoints)); //setting p2's new amount of life points
				cout << "Player 1 wins the duel! " << "Player 2 loses " << p1Card.attackPoints - p2Card.attackPoints << " points!\n";
			}
			else if (p1Card.attackPoints < p2Card.attackPoints) //p2 has a higher attack
			{
				setLifePoints(getLifePoints() - (p2Card.attackPoints - p1Card.attackPoints)); //setting p1's new amount of life points
				cout << "Player 2 wins the duel! " << "Player 1 loses " << p2Card.attackPoints - p1Card.attackPoints << " points!\n";
			}
			else //p1 and p2 have the same attack points
			{
				cout << "The duel ends in a tie! No one loses any life points!\n";
			}
		}
		else if (p1Fight == 1 && p2Fight == 2)
		{
			//P1 attacks and P2 defends
			if (p1Card.attackPoints >= p2Card.defensePoints) //If player 1's atk is higher than player 2's def
			{
				p2.setLifePoints(p2.getLifePoints() - (p1Card.attackPoints - p2Card.defensePoints)); //setting p2's new amount of life points
				cout << "Player 1 wins the duel!" << "Player 2 loses " << p1Card.attackPoints - p2Card.defensePoints << " points!\n";
			}
			else
			{
				p2.setLifePoints(p2.getLifePoints() - (p1Card.attackPoints - p2Card.defensePoints)); //setting p2's new amount of life points
				cout << "Player 2 wins the duel!" << "Player 2 gains " << p2Card.defensePoints - p1Card.attackPoints << " points!\n";
			}

		}
		else if (p1Fight == 2 && p2Fight == 1)
		{
			//P2 attacks and P1 defends
			if (p2Card.attackPoints >= p1Card.defensePoints) //If player 1's atk is higher than player 2's def
			{
				setLifePoints(getLifePoints() - (p2Card.attackPoints - p1Card.defensePoints)); //setting p1's new amount of life points
				cout << "Player 2 wins the duel!" << "Player 1 loses " << p2Card.attackPoints - p1Card.defensePoints << " points!\n";
			}
			else
			{
				setLifePoints(getLifePoints() - (p2Card.attackPoints - p1Card.defensePoints)); //setting p1's new amount of life points
				cout << "Player 1 wins the duel!" << "Player 1 gains " << p1Card.defensePoints - p2Card.attackPoints << " points!\n";
			}
		}
		else
		{
			//Both defend, nothing happens and both get cards discarded
			cout << "Both players chose to defend! No one loses any life points!\n";
		}
		system("PAUSE");
		system("CLS");

		cout << "/******************************/\n";
		cout << "Player 1's life points: " << getLifePoints() << endl;
		cout << "Player 2's life points: " << p2.getLifePoints() << endl;
		cout << "/******************************/\n";
	}

	if (playerAlive())
	{
		cout << "==============Player 1 has won the entire duel!==============\n";
	}
	else
	{
		cout << "==============Player 2 has won the entire duel!==============\n";
	}
}

/*
Function: addCard()
Date Created: 3/27/2020
Description: Will prompt the user for entries into the card struct and then add that card to the stack
Input Parameters: void
Returns: void
*/
void Player::addCard()
{
	Card data;
	string name;
	int atkPts;
	int defPts;
	string type;
	int level;
	
	cout << "What is the name of the card?: "; //prompt for name
	cin >> name;

	cout << "What is the type of the card?: "; //prompt for type
	cin >> type;

	cout << "What is the level of the card?: "; //prompt for level
	cin >> level;

	cout << "How many attack points does this card have?: "; //prompt for attack points
	cin >> atkPts;

	cout << "How many defense points does this card have?: "; //prompt for defense points
	cin >> defPts;

	data.name = name; //setting up the card struct data variables
	data.type = type;
	data.level = level;
	data.attackPoints = atkPts;
	data.defensePoints = defPts;

	deck.push(data); //pushes new card to the top of the player's deck
	cout << "Successfully added card!\n";
}

/*
Function: trading(int n)
Date Created: 3/27/2020
Description: Will ask the player to give the index of the card they would like to trade and deletes 
the card from deck and returns the card struct data
Input Parameters: void
Returns: Card
*/
Card Player::trading(int n)
{
	int trade1;
	Card card1;

	cout << "================ Displaying Player " << n << "'s Deck! ================\n";
	printDeck();
	cout << "Player " << n << ": What card do you want to trade?: ";
	do
	{
		cin >> trade1;
	} while (trade1 < 1 || trade1 > deck.count());
	card1 = deck.deleteCard(trade1);

	printCard(card1);

	return card1;
}

/*
Function: completeTrade(Card data)
Date Created: 3/27/2020
Description: Adds the struct Card data to a player's stack/deck
Input Parameters: void
Returns: void
*/
void Player::completeTrade(Card data)
{
	deck.push(data);
}