#include "Stack.h"

Stack::Stack()
{
}

Stack::~Stack()
{
	while (IsEmpty() == false)
	{
		Node* node = Pop();
		DestoryNode(&node);
	}

	list = NULL;
	top = NULL;
}

void Stack::Push(Node * node)
{
	if (list != NULL)
	{
		Node* tail = list;
		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
	}
	else
	{
		list = node;
	}
	
}

Node * Stack::Pop()
{
	if (list == top)
	{
		list = NULL;
		top = NULL;
	}
	else
	{
		Node* tail = list;
		while (tail != NULL && tail->NextNode != top)
			tail = tail->NextNode;

		top = tail;
		tail->NextNode = NULL;
	}

	return top;
}

int Stack::Size()
{
	int count = 0;
	Node* node = list;

	while (node != NULL)
	{
		node = node->NextNode;
		count++;
	}

	return count;
}

Node * Stack::CreateNode(int data)
{
	Node* node = new Node();
	node->Data = data;
	node->NextNode = NULL;

	return node;
}

void Stack::DestoryNode(Node ** node)
{
	delete* node;
	*node = NULL;
}
