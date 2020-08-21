#pragma once

#ifndef STACK_H
#define STACK_H
#include "header.h"


#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Stack {
private:
	Node* top;
	int numCards;
public:
	Stack();
	Card pop(); //Removes the node from the top of the stack and returns the card data
	void push(Card data); //Adds node to the top of the stack with card data
	bool isEmpty(); //Checks if the stack is empty
	int count(); //Returns numItems
	void clear(); //Clears the stack of all nodes
	void displayStack(); //Displays all cards in the stack
	Card deleteCard(int index); //Deletes card from location in the stack and returns the card data
};

#endif