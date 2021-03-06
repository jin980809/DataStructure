#include <iostream>
#include "DLinkedList.h"
using namespace std;

Node * Create(DataType data)
{
	Node* node = new Node();

	node->PrevNode = NULL;
	node->Data = data;
	node->NextNode = NULL;

	return node;
}

void Destroy(Node ** node)
{
	delete* node;
	*node = NULL;
}

void Push(Node ** head, Node * node)
{
	if ((*head) != NULL)
	{
		Node* tail = (*head);

		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
		node->PrevNode = tail;
	}
	else
	{
		*head = new Node();
	}
}

void Insert(Node * current, Node * node)
{
	node->NextNode = current->NextNode;
	node->PrevNode = current;


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


void Remove(Node ** head, Node * remove)
{
	if (*head == remove)
	{
		*head = remove->NextNode;

		if (*head != NULL)
			(*head)->PrevNode = NULL;

		remove->PrevNode = NULL;
		remove->NextNode = NULL;
	}
	else
	{
		Node* current = remove;

		remove->PrevNode->NextNode = current->NextNode;
		if (remove->NextNode != NULL)
			remove->NextNode->PrevNode = current->PrevNode;

		remove->PrevNode = NULL;
		remove->NextNode = NULL;
	}
}
