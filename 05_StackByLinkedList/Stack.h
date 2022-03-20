#pragma once

#include <stdio.h>

struct Node
{
	int Data;

	Node* NextNode;
};

class Stack
{
public:
	Stack();
	~Stack();

	void Push(Node* node);
	Node* Pop();

	Node* Top() { return top; }
	int Size();
	bool IsEmpty() { return list == NULL; }

	static Node* CreateNode(int data);
	static void DestoryNode(Node** node);

private:
	Node* list = NULL;
	Node* top = NULL;
};