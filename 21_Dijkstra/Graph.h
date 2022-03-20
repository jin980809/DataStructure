#pragma once

#include <iostream>
using namespace std;

#include "PQueue.h"

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

	void Dijkstra(Node* startNode, Graph<T>* graph)
	{
		int* weights = new int[Count];
		Node** shorts = new Node*[Count];
		Node** connected = new Node*[Count];
		Node** parents = new Node*[Count];


		Edge* currentEdge = NULL;
		Node* currentNode = Head;
		for (int index = 0; currentNode != NULL; index++)
		{
			Node* newNode = CreateNode(currentNode->Data);
			graph->AddNode(newNode);

			weights[index] = INT_MAX;
			shorts[index] = newNode;
			connected[index] = NULL;
			parents[index] = NULL;

			currentNode = currentNode->Next;
		}


		PQueue<Node *> queue(10);
		PQueue<Node *>::Node startQNode = PQueue<Node *>::Node(0, startNode);

		queue.Insert(startQNode);
		weights[startNode->Index] = 0;
		while (queue.Empty() == false)
		{
			PQueue<Node *>::Node poped = queue.RemoveMin();
			currentNode = poped.Data;


			connected[currentNode->Index] = currentNode;
			
			currentEdge = currentNode->Edge;
			while (currentEdge != NULL)
			{
				Node* targetNode = currentEdge->Target;

				bool b = true;
				b &= connected[targetNode->Index] == NULL;
				b &= weights[currentNode->Index] + currentEdge->Weight < weights[targetNode->Index];

				if (b == true)
				{
					PQueue<Node *>::Node newNode = PQueue<Node *>::Node(currentEdge->Weight, targetNode);
					queue.Insert(newNode);

					parents[targetNode->Index] = currentEdge->Start;
					weights[targetNode->Index] = weights[currentNode->Index] + currentEdge->Weight;
				}//if(b)

				currentEdge = currentEdge->Next;
			}//while(currentEdge)
		}

		for (int i = 0; i < Count; i++)
		{
			if (parents[i] == NULL)
				continue;

			int start = parents[i]->Index;
			int target = i;

			graph->AddEdge(shorts[start], Graph<T>::CreateEdge(shorts[start], shorts[target], weights[i]));

			cout << shorts[start]->Data << ", " << shorts[target]->Data << ", " << weights[i] << endl;
		}
		cout << endl;


		delete[] connected;
		delete[] parents;
		delete[] shorts;
		delete[] weights;
	}


public:
	static Edge* CreateEdge(Node* start, Node* target, int weight)
	{
		Edge* edge = new Edge();
		edge->Start = start;
		edge->Target = target;
		edge->Weight = weight;
		
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
		int Weight = 0;
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
};