#pragma once

#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Graph
{
public:
	struct Edge;
	struct Node;

public:
	void AddNode(Node* node)
	{
		Node* nodeList = Head;
		if (nodeList != NULL)
		{
			while (nodeList->Next != NULL)
				nodeList = nodeList->Next;

			nodeList->Next = node;
		}
		else
		{
			Head = node;
		}

		node->Index = Count++;
	}

	void AddEdge(Node* node, Edge* edge)
	{
		if (node->Edge != NULL)
		{
			Edge* edgeList = node->Edge;

			while (edgeList->Next != NULL)
				edgeList = edgeList->Next;

			edgeList->Next = edge;
		}
		else
		{
			node->Edge = edge;
		}
	}

	void Print()
	{
		Node* node = NULL;
		Edge* edge = NULL;

		if ((node = Head) == NULL)
			return;

		while (node != NULL)
		{
			cout << node->Data << " : ";

			if ((edge = node->Edge) == NULL)
			{
				node = node->Next;
				cout << endl;

				continue;
			}

			while (edge != NULL)
			{
				cout << edge->Target->Data;
				edge = edge->Next;
			}

			cout << endl;

			node = node->Next;
		}

		cout << endl;
	}

	void Sort(Node* node)
	{
		while (node != NULL && node->Visited == false)
		{
			DFS(node);

			node = node->Next;
		}
	}

	void DFS(Node* node)
	{
		node->Visited = true;
		Edge* edge = node->Edge;

		while (edge != NULL)
		{
			if (edge->Target != NULL && edge->Target->Visited == false)
				DFS(edge->Target);

			edge = edge->Next;
		}

		//cout << node->Data;
		L.push_front(node);
	}

	void PrintResult()
	{
		while (L.empty() == false)
		{
			cout << L.front()->Data;
			L.pop_front();
		}
	}


public:
	static Edge* CreateEdge(Node* start, Node* target)
	{
		Edge* edge = new Edge();
		edge->Start = start;
		edge->Target = target;
		
		return edge;
	}

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;

		return node;
	}

public:
	struct Edge
	{
		Node* Start = NULL;
		Node* Target = NULL;
		Edge* Next = NULL;
	};

	struct Node
	{
		T Data;
		int Index = -1;

		Node* Next = NULL;
		Edge* Edge = NULL;

		bool Visited = false;
	};

private:
	Node* Head = NULL;
	int Count = 0;

	list<Node *> L;
};