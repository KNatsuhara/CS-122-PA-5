#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

struct Card {
	string name;
	int attackPoints;
	int defensePoints;
	string type;
	int level;
};

struct Node {
	Card data;
	struct Node *pNext;
};

void printCard(Card data);
int selectCard();
int selectQueue();
int randomNumber();
void printMenu();
int getOption();
int addCardOption();

#endif