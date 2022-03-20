#pragma once

#include <stdio.h>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

template<typename T>
class Tree
{
public:
	struct Node;

public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->LeftChild == NULL)
		{
			parent->LeftChild = child;

			return;
		}

		Node* node = parent->LeftChild;
		while (node->RightSibling != NULL)
			node = node->RightSibling;

		node->RightSibling = child;
	}

	void PrintNode(Node* node, int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "-";

		cout << node->Data << endl;
		queue.push(node->Data);
		stack.push(node);
		
		if (node->LeftChild != NULL)
			PrintNode(node->LeftChild, depth + 1);

		if(node->RightSibling != NULL)
			PrintNode(node->RightSibling, depth);
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->LeftChild = node->RightSibling = NULL;

		return node;
	}

	static void DestoryNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}

public:
	stack<Node *>* Stack() { return &stack; }
	queue<T>* Queue() { return &queue; }

public:
	struct  Node
	{
		T Data;

		Node* LeftChild;
		Node* RightSibling;

		~Node()
		{
			Data = 0;

			LeftChild = NULL;
			RightSibling = NULL;
		}
	};

private:
	queue<T> queue;
	stack<Node *> stack;
};