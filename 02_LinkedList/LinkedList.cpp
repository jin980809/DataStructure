#include <iostream>
#include "LinkedList.h"
using namespace std;

Node * Create(DataType data)
{
	Node* node = new Node();

	node->Data = data;
	node->NextNode = NULL;

	return node;
}

void Destroy(Node * node)
{
	delete node;
	node = NULL;
}

void Push(Node ** head, Node * node)
{
	if ((*head) != NULL)
	{
		Node* tail = (*head);

		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
	}
	else
	{
		*head = new Node();
	}
}

void Insert(Node * current, Node * node)
{
	node->NextNode = current->NextNode;
	current->NextNode = node;
}

void InsertHead(Node ** current, Node * head)
{
	if (*current == NULL)
	{
		*current = head;
	}
	else
	{
		head->NextNode = *current;
		*current = head;
	}
}

void Remove(Node ** head, Node * remove)
{
	if (*head == remove)
	{
		*head = remove->NextNode;
	}
	else
	{
		Node* current = *head;
		while (current != NULL && current->NextNode != remove)
			current = current->NextNode;

		if (current != NULL)
			current->NextNode = remove->NextNode;
	}
}

Node * GetNode(Node * head, int index)
{
	Node* current = head;

	while (current != NULL && (--index >= 0))
		current = current->NextNode;

	return current;
}

int GetNodeCount(Node * head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->NextNode;
		count++;
	}

	return count;
}


