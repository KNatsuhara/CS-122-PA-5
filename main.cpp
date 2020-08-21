#pragma once
#include "header.h"
#include "player.h"
#include <iostream>

using namespace std;

/**********************************************************
Programmer: Koji Natsuhara
Class: CptS 122, Spring 2020, Lab Section 3
Programming Assignment: Programming Assignment 5: Implement Yu Gi Oh! Card Game
Date: March 27, 2020
Description: This program will implement constructors and compare and contrast
between public and private functions/variables. This programming assignment will
also require the implementation of queues and stacks.
**********************************************************/

int main() {
	int option = NULL, check = 0, EXIT = 0, cardOption = NULL;
	Card card1, card2;
	Player player1, player2;
	while (EXIT == 0) {
		option = getOption();
		switch (option) {
		case 1:
			player1.fillDeck(1);
			player2.fillDeck(2);
			check = 1;
			cout << "Players have been successfully created!\n";
			break;
		case 2:
			cardOption = addCardOption();
			if (cardOption == 1)
				player1.addCard();
			else
				player2.addCard();
			break;
		case 3:
			if (check == 0)
				cout << "Players have not been set yet!";
			else
			{
				card1 = player1.trading(1);
				card2 = player2.trading(2);
				player1.completeTrade(card2);
				player2.completeTrade(card1);
				cout << "Trade has been successful!\n";
			} break;
		case 4:
			if (check == 0)
				cout << "Players have not been set yet!\n";
			else
				player1.battlePhase(player2);
			break;
		case 5:
			EXIT = 1;
			break;
		}
	}
	return 0;
}