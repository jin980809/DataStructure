#pragma once

#include <iostream>
#include <list>
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

	void Prim(Node* startNode, Graph<T>* graph)
	{
		Node* currentNode = NULL;
		Edge* currentEdge = NULL;

		int* weigths = new int[Count];
		Node** mstNodes = new Node*[Count];
		Node** friends = new Node*[Count];
		Node** parents = new Node*[Count];


		int index = 0;
		currentNode = Head;
		while (currentNode != NULL)
		{
			Graph<T>::Node* newNode = CreateNode(currentNode->Data);
			graph->AddNode(newNode);

			weigths[index] = INT_MAX;
			mstNodes[index] = newNode;
			friends[index] = NULL;
			parents[index] = NULL;
			currentNode = currentNode->Next;

			index++;
		}


		PQueue<Node *> queue(10);
		PQueue<Node *>::Node startQueueNode = PQueue<Node *>::Node(0, startNode);

		queue.Insert(startQueueNode);
		weigths[startNode->Index] = 0;

		while (queue.Empty() == false)
		{
			PQueue<Node *>::Node poped = queue.RemoveMin();

			currentNode = poped.Data;
			friends[currentNode->Index] = currentNode;

			currentEdge = currentNode->Edge;
			while (currentEdge != NULL)
			{
				Node* targetNode = currentEdge->Target;

				if (friends[targetNode->Index] == NULL && currentEdge->Weight < weigths[targetNode->Index])
				{
					PQueue<Node *>::Node newNode = PQueue<Node *>::Node(currentEdge->Weight, targetNode);
					queue.Insert(newNode);

					parents[targetNode->Index] = currentEdge->Start;
					weigths[targetNode->Index] = currentEdge->Weight;
				}

				currentEdge = currentEdge->Next;
			}//while(currentEdge)
		}//while(queue)

		//cout << endl;
		//for (int i = 0; i < Count; i++)
		//	cout << i << "," << weigths[i] << " / ";


		for (int i = 0; i < Count; i++)
		{
			int start, target;

			if (parents[i] == NULL)
				continue;

			start = parents[i]->Index;
			target = i;

			graph->AddEdge(mstNodes[start], Graph<T>::CreateEdge(mstNodes[start], mstNodes[target], weigths[i]));
			graph->AddEdge(mstNodes[target], Graph<T>::CreateEdge(mstNodes[target], mstNodes[start], weigths[i]));

			cout << mstNodes[start]->Data << " -> " << mstNodes[target]->Data << ", " << weigths[i] << endl;
		}

		cout << endl;

		delete[] weigths;
		delete[] mstNodes;
		delete[] friends;
		delete[] parents;
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