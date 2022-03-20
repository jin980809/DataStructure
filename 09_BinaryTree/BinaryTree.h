#pragma once

#include <iostream>
using namespace std;

template<typename T>
class BTree
{
public:
	struct Node;

public:
	BTree()
	{
	
	}

	~BTree()
	{
		Destroy(root);
	}

public:
	void PreOrder(Node* node)
	{
		if (node == NULL) return;

		cout << " " << node->Data;

		PreOrder(node->Left);
		PreOrder(node->Right);
	}

	void InOrder(Node* node)
	{
		if (node == NULL) return;

		InOrder(node->Left);

		cout << " " << node->Data;

		InOrder(node->Right);
	}

	void PostOrder(Node* node)
	{
		if (node == NULL) return;

		PostOrder(node->Left);
		PostOrder(node->Right);

		cout << " " << node->Data;
	}

private:
	void Destroy(Node* node)
	{
		if (node == NULL) return;

		Destroy(node->Left);
		Destroy(node->Right);

		DestroyNode(&node);
	}

public:
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;

		return node;
	}

	static void DestroyNode(Node** node)
	{
		delete* node;
		*node = NULL;
	}

public:
	void Root(Node* node) { root = node; }

public:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};

private:
	Node* root;
};