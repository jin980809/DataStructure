#include "Graph.h"

typedef Graph<char> G;

int main()
{
	G graph;

	G::Node* A = G::CreateNode('A');
	G::Node* B = G::CreateNode('B');
	G::Node* C = G::CreateNode('C');
	G::Node* D = G::CreateNode('D');
	G::Node* E = G::CreateNode('E');
	G::Node* F = G::CreateNode('F');
	G::Node* G = G::CreateNode('G');
	G::Node* H = G::CreateNode('H');

	G::Node* a = G::CreateNode('A');
	G::Node* b = G::CreateNode('B');
	G::Node* c = G::CreateNode('C');
	G::Node* d = G::CreateNode('D');
	G::Node* e = G::CreateNode('E');
	G::Node* f = G::CreateNode('F');
	G::Node* g = G::CreateNode('G');
	G::Node* h = G::CreateNode('H');
	G::Node* i = G::CreateNode('I');

	graph.AddNode(a);
	graph.AddNode(b);
	graph.AddNode(c);
	graph.AddNode(d);
	graph.AddNode(e);
	graph.AddNode(f);
	graph.AddNode(g);
	graph.AddNode(h);
	graph.AddNode(i);

	graph.AddEdge(b, G::CreateEdge(b, a, 35));
	graph.AddEdge(b, G::CreateEdge(b, c, 126));
	graph.AddEdge(b, G::CreateEdge(b, f, 150));

	graph.AddEdge(a, G::CreateEdge(a, e, 247));

	graph.AddEdge(c, G::CreateEdge(c, d, 117));
	graph.AddEdge(c, G::CreateEdge(c, g, 220));
	graph.AddEdge(c, G::CreateEdge(c, f, 162));

	graph.AddEdge(e, G::CreateEdge(e, h, 98));

	graph.AddEdge(f, G::CreateEdge(f, e, 82));
	graph.AddEdge(f, G::CreateEdge(f, h, 120));
	graph.AddEdge(f, G::CreateEdge(f, g, 154));

	graph.AddEdge(g, G::CreateEdge(g, i, 106));
	

	Graph<char> dijkstra;
	cout << "다익스트라 알고리즘" << endl;
	graph.Dijkstra(b, &dijkstra);
	dijkstra.Print();
	cout << endl << endl;

	return 0;
}