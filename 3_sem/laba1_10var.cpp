#include <iostream>
using namespace std;
struct TreeNode
{
	int value;
	TreeNode **nodes;
	TreeNode *next;
};
void AddNode(TreeNode **);
void DelTree(TreeNode *);
void PrintTree(TreeNode *);
int menu();
void FindByValue(TreeNode *);
bool FindByValue(TreeNode *, int);
void ScreenFoundNode(TreeNode *);
int  main()
{
	TreeNode *root = NULL;
	while (true)
	{
		switch (menu())
		{
			system("cls");
			case 1:AddNode(&root); break;
			case 2:FindByValue(root); break;
			case 3:DelTree(root); root = NULL; break;
			case 4:
			{
				if (root == NULL)
				{
					cout << "Create tree" << endl;
					system("pause");
					break;
				}
				cout << "nodes value: "; 
				PrintTree(root); 
				cout << endl;
				system("pause"); break;
			}
			case 5:return 0;
			default:
			{
				cout << "vvedite pravilno";
				system("pause");
			}
		}
	}
	
	return 0;
}


int menu()
{
	system("cls");
	int b;
	cout << "1:add node" << endl;
	cout << "2:find node by value" << endl;
	cout << "3:delete three" << endl;
	cout << "4:Prin three" << endl;
	cout << "5:exit" << endl;
	cin >> b;
	return b;
}
void AddNode(TreeNode **root)
{

	if (*root == NULL)
	{
		*root = new TreeNode();
		int key;
		cout << "Enter the key of node" << endl;
		cin >> key;
		(*root)->value = key;
		(*root)->next = NULL;
		(*root)->nodes = new TreeNode *[2];
		(*root)->nodes[0] = NULL;
		(*root)->nodes[1] = NULL;
		return;
	}
	char choose;
	TreeNode *copyRoot = *root;
	while (true)
	{
		cout << "left(l)/right(r)";
		cin >>choose;
		if (choose == 'l')
		{
			if ((copyRoot)->nodes[0] == NULL) break;
			(copyRoot) = (copyRoot)->nodes[0];
		}
		else 
		if (choose == 'r')
		{
			if ((copyRoot)->nodes[1] == NULL) break;
			(copyRoot) = (copyRoot)->nodes[1];
		}
		else
		{
			cout << "Input only r/l" << endl;
		}
	}
	cout << "Enter the key" << endl;
	int key;
	cin >> key;
	TreeNode *newTree = new TreeNode();
	newTree->value = key;
	newTree->nodes = new TreeNode *[2];
	newTree->nodes[0] = NULL;
	newTree->nodes[1] = NULL;
	if (choose == 'l')
		copyRoot->nodes[0] = newTree;
	if (choose == 'r')
		copyRoot->nodes[1] = newTree;



}
void DelTree(TreeNode *root)
{
	if (root == NULL) return;
	DelTree(root->nodes[0]);
	delete root->nodes[0];
	DelTree(root->nodes[1]);
	delete root->nodes[1];
}
void FindByValue(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "Create a tree" << endl;
		system("pause");
		return;
	}
	cout << "enter the key" << endl;
	int key;
	cin >> key;
	bool result=FindByValue(root, key);
	if (!result) cout << "node not found!" << endl;
	system("pause");
}
bool FindByValue(TreeNode *root, int key)
{
	if (root == NULL) return false;
	if (root->value == key)
	{
		ScreenFoundNode(root);
		return true;
	}
	bool result;
	result = FindByValue(root->nodes[0], key);
	if (result == true) return true;
	result = FindByValue(root->nodes[1], key);
	if (result == true)  return true;
	
	return false;
}
void ScreenFoundNode(TreeNode *node)
{
	cout << "there are node in tree with such key!" << endl;
	if ((node->nodes[0]) != NULL)
		cout << "left daugther" << endl << node->nodes[0]->value << endl;
	else
		cout << "Don't have left daugther"<<endl;
	if ((node->nodes[1]) != NULL)
		cout << "right daugther" << endl << node->nodes[1]->value << endl;
	else
		cout << "Don't have right daugther"<<endl;
	system("pause");
}
void PrintTree(TreeNode * root)
{
	if (root == NULL) return;
	PrintTree(root->nodes[0]);
	PrintTree(root->nodes[1]);
	cout << root->value << " ";
}

