#pragma once

#include "stack.h"
#include <iostream>

using namespace std;

/*
Function: Stack()
Date Created: 3/27/2020
Description: Is the constructor for the Stack class. Sets top pointer to null and numCards to 0;
Input Parameters: void
Returns: An instantiated stack object
*/
Stack::Stack()
{
	top = nullptr;
	numCards = 0;
}

/*
Function: pop()
Date Created: 3/27/2020
Description: Will return a Card struct data and delete the first node from the stack
Input Parameters: void
Returns: Card struct data
*/
Card Stack::pop() //Precondition, the stack must not be empty
{
	Node* temp = nullptr;
	Card data;
	data = top->data;
	temp = top;
	top = top->pNext;
	delete temp; //free() function in c
	numCards--;
	return data;
}

/*
Function: push(Card data)
Date Created: 3/27/2020
Description: Will add a new Node to the top of the stack
Input Parameters: void
Returns: void
*/
void Stack::push(Card data)
{
	Node* newNode = new Node; //Malloc memory for the new Node

	newNode->data = data; //Adding data to the newNode
	newNode->pNext = nullptr; //Initializing the pNext pointer in newNode

	if (isEmpty())
	{
		newNode->pNext = nullptr; //NewNode pNext points to nullptr
		top = newNode; //Sets top to the newNode (The top of the stack is the newNode)
	}
	else
	{
		newNode->pNext = top; //NewNode pNext points to nullptr
		top = newNode; //Sets top to the newNode (The top of the stack is the newNode)
	}

	numCards++;
}

/*
Function: isEmpty()
Date Created: 3/27/2020
Description: Checks if the stack is empty
Input Parameters: void
Returns: boolean
*/
bool Stack::isEmpty()
{
	bool status = false;
	if (numCards == 0)
	{
		status = true;
	}
	return status;
}

/*
Function: count()
Date Created: 3/27/2020
Description: returns the number of cards in the stack
Input Parameters: void
Returns: integer
*/
int Stack::count()
{
	return numCards;
}

/*
Function: clear()
Date Created: 3/27/2020
Description: Clears the entire stack and deletes all the nodes
Input Parameters: void
Returns: void
*/
void Stack::clear()
{
	Card data;

	while (!isEmpty())
	{
		data = pop();
	}
}

/*
Function: displayStack()
Date Created: 3/27/2020
Description: Will print out the cards in the stack from top to bottom
Input Parameters: void
Returns: void
*/
void Stack::displayStack() //Displays Deck
{
	Node *temp = nullptr;
	Node *current = top;
	Card data;
	int i = 1;

	while (current != nullptr)
	{
		data = current->data;
		temp = current;
		current = current->pNext;
		cout << i << ". Name: " << data.name << " Attack Points: " << data.attackPoints << " Defense Points: " << data.defensePoints << endl;
		i++;
	}
}

/*
Function: deleteCard(int index)
Date Created: 3/27/2020
Description: Given the chosen index of where the card is, this function will delete the card from the stack and return the card data
Input Parameters: void
Returns: Card struct data
*/
Card Stack::deleteCard(int index)
{
	Node* temp1 = top; //temp node
	Card data;
	
	if (index == 1)
	{
		top = temp1->pNext;
		data = temp1->data;
		delete temp1;
		return data;
	}

	for (int i = 0; i < index-2; i++)
	{
		temp1 = temp1->pNext; //traverses until one node before the desired node
	}
	
	Node* temp2 = temp1->pNext;
	data = temp2->data;
	temp1->pNext = temp2->pNext;

	delete temp2; //free() function in c

	numCards--;

	return data;
}

