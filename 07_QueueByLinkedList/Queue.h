#pragma once
#include <stdio.h>

template<typename T>
class Queue
{
public:
	struct Node;

public:
	Queue()
	{

	}

	~Queue()
	{
		while (IsEmpty() == false)
		{
			Node* node = Dequeue();
			DestroyNode(&node);
		}
	}

	void Enqueue(Node* node)
	{
		if (front == NULL)
		{
			front = node;
			rear = node;

			count++;

			return;
		}

		rear->Next = node;
		rear = node;

		count++;
	}

	Node* Dequeue()
	{
		Node* node = front;

		if (front->Next == NULL)
			front = rear = NULL;
		else
			front = front->Next;

		count--;

		return node;
	}

	int Size() { return count; }

	bool IsEmpty()
	{
		return front == NULL;
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = NULL;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}

public:
	struct Node
	{
		T Data;
		Node* Next;
	};

private:
	int count = 0;

	Node* front = NULL;
	Node* rear = NULL;
};
