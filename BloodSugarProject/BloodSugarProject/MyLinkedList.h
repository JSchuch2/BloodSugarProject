//James Schuchardt
//Begun: October 12th, 2018
//Last Edited: October 26th, 2018
//Computer Science II Cosc 2030
//Blood Sugar Project
//This Headerfile has similar code from Paul Programming: https://www.youtube.com/watch?v=H5lkmKkfjD0&list=PLTxllHdfUq4fewZGVFPhzbmHTQC2UH7PJ


#ifndef LIST_H
#define LIST_H
class MyLinkedList
{
private:
	//Creates structure for node to work off of.
	typedef struct node
	{
		int data;
		node* next;

	}* nodePtr;

	//creates pointers for the nodes.
	nodePtr Top;
	nodePtr Position;
	nodePtr Holder;


public: //Initialize Functions for MyLinkedList to use.
	MyLinkedList();
	void NewNode(int addData);
	void NodeRemoval(int delData);
	int FindBiggest();
	int FindSmallest();
	int NodeSummary();
	int NodeTotal();
	void NegativeDeletion();
};


#endif
