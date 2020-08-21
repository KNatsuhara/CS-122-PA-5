#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef PLAYER_H
#define PLAYER_H

#include "header.h"
#include "queue.h"
#include "stack.h"

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Player {
private:
	Stack deck;
	DynCardQueue attackQ;
	DynCardQueue defenseQ;
	Card hand[5];
	int lifePoints;
public:
	Player();
	int getLifePoints()
	{
		return lifePoints;
	}
	void setLifePoints(int points)
	{
		lifePoints = points;
	}
	void fillDeck(int player);
	void printDeck();
	void fillHand();
	void displayHand();
	void setAtkQ();
	void setDefQ();
	Card printAtkQ();
	Card printDefQ();
	bool playerAlive();
	void battlePhase(Player p2);
	void addCard();
	Card trading(int n);
	void completeTrade(Card data);
};

#endif