#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include "header.h"

#include <time.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class DynCardQueue {
private:
	//Queue Components
	Node* front;
	Node* rear;
	int numItems;
public:
	//Queue Operations
	DynCardQueue();
	void enqueue(Card data);
	void dequeue(Card& data);

	bool isQueueEmpty(); //Check if the queue is empty
	int queueCount();
	void queueClear();
};

#endif