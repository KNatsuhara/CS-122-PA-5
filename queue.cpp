#pragma once
#include "queue.h"
#include <iostream>

using namespace std;

/*
Function: DynCardQueue()
Date Created: 3/27/2020
Description: The constructor for the class DynCardQueue which will set the front and rear pointer to null and the numItems to 0;
Input Parameters: void
Returns: An instantiated DynCardQueue object
*/
DynCardQueue::DynCardQueue()
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}

/*
Function:enqueue(Card data)
Date Created: 3/27/2020
Description: Will add a card data to the queue
Input Parameters: void
Returns: void
*/
void DynCardQueue::enqueue(Card data)
{
	Node* newNode = nullptr;
	newNode = new Node; // malloc // Qnode *newNode = new QNode;

	newNode->data = data; //Set newNode's data to the card's data being added to the queue
	newNode->pNext = nullptr; //Set newnode's pNext to nullptr

	if (isQueueEmpty()) //If queue is empty set Node pointers front and rear pointing to the newNode
	{
		front = newNode;
		rear = newNode;
	}
	else //If queue is NOT empty, set the rear pointer toward the newNode (after the previous Node in line)
	{
		rear->pNext = newNode;
		rear = newNode; //set the newNode to be the last(rear) node in the queue
	}
	numItems++;
}

/*
Function: dequeue(Card &data)
Date Created: 3/27/2020
Description: Will delete the first node to enter in the queue and return the card struct data
Input Parameters: void
Returns: Card struct data
*/
void DynCardQueue::dequeue(Card& data)
{
	Node* temp = nullptr;

	if (isQueueEmpty())
		cout << "The queue is empty!" << endl;
	else
	{
		data = front->data;

		//remove the front of the queue
		temp = front;

		front = front->pNext;

		delete temp; // free() function in c

		numItems--;
	}
}

/*
Function: isQueueEmpty()
Date Created: 3/27/2020
Description: Will check if the queue is empty
Input Parameters: void
Returns: boolean
*/
bool DynCardQueue::isQueueEmpty() //Check if the queue is empty
{
	bool status;
	if (numItems > 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}
	return status;
}

/*
Function: queueCount()
Date Created: 3/27/2020
Description: Will return the number of cards in the queue
Input Parameters: void
Returns: integer
*/
int DynCardQueue::queueCount()
{
	return numItems;
}

/*
Function: queueClear()
Date Created: 3/27/2020
Description: Will delete all the cards in the queue
Input Parameters: void
Returns: void
*/
void DynCardQueue::queueClear()
{
	Card data;
	while (!isQueueEmpty())
	{
		dequeue(data);
	}
}
