#include <iostream>
#include <string>
#include "TreeNode.h"
#include "List.h"
#include "NodePair.h"
using namespace std;
int main()
{
	TreeNode *root = NULL;
	root = new TreeNode("1_1");
	root->AddNode("1_1");
	root=*root<<"2_1";
	root->AddNode("1_2");
	TreeNode *node = (*root)["2_1"];
	if (node != NULL) node->AddNode("2_2");
	if (node != NULL) node=*node << "3_1";
	PrintTree(root, 0);
	cout << "-----------" << endl;
	TreeNode *copy=new TreeNode("hi");
	copy=copy->operator=(root);
	PrintTree(copy, 0);
	delete root;
	delete copy;
//	system("pause");
	return 0;
}
