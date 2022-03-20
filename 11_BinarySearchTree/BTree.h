#pragma once

#include <iostream>
using namespace std;

template<typename T>
class BTree
{
public:
	struct Node;

public:
	BTree() { }
	~BTree()
	{
			
	}

	void Insert(Node** parent, Node* child)
	{
		if ((*parent)->Data < child->Data)
		{
			if ((*parent)->Right == NULL)
				(*parent)->Right = child;
			else
				Insert(&(*parent)->Right, child);
		}
		else if ((*parent)->Data > child->Data)
		{
			if ((*parent)->Left == NULL)
				(*parent)->Left = child;
			else
				Insert(&(*parent)->Left, child);
		}
	}

	Node* Search(Node* node, T data, int& depth)
	{
		if (node == NULL)
			return NULL;

		depth++;

		if (node->Data == data)
			return node;
		else if (node->Data > data)
			return Search(node->Left, data, depth);
		else if (node->Data < data)
			return Search(node->Right, data, depth);

		return NULL;
	}

	void InOrder(Node* node, int depth)
	{
		if (node == NULL)
			return;

		depth++;

		InOrder(node->Left, depth);

		cout << " " << node->Data << "|" << depth;

		InOrder(node->Right, depth);
	}

	Node* Remove(Node* node, Node* parent, T data)
	{
		Node* remove = NULL;
		if (node == NULL)
			return NULL;

		if (node->Data > data)
		{
			remove = Remove(node->Left, node, data);
		}
		else if (node->Data < data)
		{
			remove = Remove(node->Right, node, data);
		}
		else //탐색 완료, 노드 삭제
		{
			remove = node;

			if (node->Left == NULL && node->Right == NULL)
			{
				if (parent->Left == node)
					parent->Left = NULL;
				else
					parent->Right = NULL;
			}
			else
			{
				if (node->Left != NULL && node->Right != NULL) //양쪽 모두 존재
				{
					Node* minNode = SearchMinValue(node->Right);

					minNode = Remove(node, NULL, minNode->Data);
					node->Data = minNode->Data;

					return minNode;
				}
				else //한쪽만 존재
				{
					Node* temp = NULL;

					if (node->Left != NULL)
						temp = node->Left;
					else
						temp = node->Right;

					if (parent->Left == node)
						parent->Left = temp;
					else
						parent->Right = temp;
				}
			}//if(node->Left)
		} //if(node->Data)

		return remove;
	}

	Node* SearchMinValue(Node* node)
	{
		if (node == NULL)
			return NULL;

		if (node->Left == NULL)
			return node;
		else
			return SearchMinValue(node->Left);
	}

	Node* Root() { return root; }
	void Root(Node* root) { this->root = root; }

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
		delete *node;
		*node = NULL;
	}

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