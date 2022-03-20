#include "BTree.h"

typedef BTree<int> Tree;

int main()
{
	Tree tree;
	Tree::Node* root = Tree::CreateNode(12);
	tree.Root(root);

	tree.Insert(&root, Tree::CreateNode(22));
	tree.Insert(&root, Tree::CreateNode(99));
	tree.Insert(&root, Tree::CreateNode(42));
	tree.Insert(&root, Tree::CreateNode(17));
	tree.Insert(&root, Tree::CreateNode(3));
	tree.Insert(&root, Tree::CreateNode(98));
	tree.Insert(&root, Tree::CreateNode(34));
	tree.Insert(&root, Tree::CreateNode(75));
	tree.Insert(&root, Tree::CreateNode(32));
	tree.Insert(&root, Tree::CreateNode(1));

	tree.InOrder(root, 0);

	int depth = 0;
	Tree::Node* node = tree.Search(root, 98, depth);
	cout << endl << endl << "찾음 : " << node->Data << ", " << depth << "번에 찾음" << endl;

	node = tree.Remove(root, NULL, 98);
	cout << "삭제할 노드 : " << node->Data << endl;
	Tree::DestroyNode(&node);
	
	tree.InOrder(root, 0);
	cout << endl << endl;

	return 0;
}