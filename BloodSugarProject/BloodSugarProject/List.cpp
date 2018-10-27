//James Schuchardt
//Begun: October 12th, 2018
//Last Edited: October 26th, 2018
//Computer Science II Cosc 2030
//Blood Sugar Project
//This file has similar code from Paul Programming: https://www.youtube.com/watch?v=H5lkmKkfjD0&list=PLTxllHdfUq4fewZGVFPhzbmHTQC2UH7PJ


#include <iostream>

#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() 
{
	Top = NULL;
	Position = NULL;
	Holder = NULL;
};

//Adds a Node next to the tail, unless the LinkedList is empty. Then it will add it to the top.
void MyLinkedList::NewNode(int Number)
{
	nodePtr NewNode = new node;
	NewNode->next = NULL;
	NewNode->data = Number;

	if (Top != NULL)
	{
		Position = Top;
		while (Position->next != NULL)
		{
			Position = Position->next;
		}
		Position->next = NewNode;
	}
	else
	{
		Top = NewNode;
		
	}
};

//Removes a specific Node containing a data we wish to be gone.
void MyLinkedList::NodeRemoval(int BadNumber)
{
	nodePtr Deletion = NULL;
	Holder = Top;
	Position = Top;
	while (Position != NULL && Position->data != BadNumber)
	{
		Holder = Position;
		Position = Position->next;
	}
	if (Position == NULL)
	{
		delete Deletion;
	}
	else
	{
		Deletion = Position;
		Position = Position->next;
		Holder->next = Position;
		if (Deletion == Top)
		{
			Top = Top->next;
			Holder = NULL;
		}
		delete Deletion;
	}
};

//Iterates through the list and compares all of the data pointers of nodes in order to find the highest value stored.
int MyLinkedList::FindBiggest()
{
	int max = 0;
	Position = Top;
	while (Position != NULL) {
		if (max < Position->data)
			max = Position->data;
		Position = Position->next;
	}
	return max;
};


//Iterates through the list and compares all of the data pointers of nodes in order to find the lowest value stored.
int MyLinkedList::FindSmallest()
{
	NodeRemoval(0);
	int min = INT_MAX;
	Position = Top;
	while (Position != NULL) {
		if (min > Position->data)
		{
			min = Position->data;
			Position = Position->next;
		}
		else
		{
			Position = Position->next;
		}
		
	}
		
	
	return min;
};

//Finds the Sum of all the Nodes in a LinkedList
int MyLinkedList::NodeSummary()
{
	int overflow = 0;
	int sum = 0;
	Position = Top;
	while (Position != NULL)
	{
	sum += Position->data;
	Position = Position->next;
	}
	return sum;

}

//Finds the total amount of elements in a certain LinkedList
int MyLinkedList::NodeTotal()
{
	int Total = 0;
	Position = Top;
	while (Position != NULL)
	{
		Total++;
		Position = Position->next;
	}
	return Total;
}

//Deletes all negative numbers currently in LinkedList
void MyLinkedList::NegativeDeletion()
{
	Position = Top;
	while (Position != NULL)
	{
		if (Position->data < 0)
		{
			Holder = Position;
			Position = Position->next;
			NodeRemoval(Holder->data);
		}
		else
		{
			Position = Position->next;
		}
	}

}