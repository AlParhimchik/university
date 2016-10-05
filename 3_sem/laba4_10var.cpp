#include <iostream>
#include <string>
using namespace std;
class TreeNode
{
private:
	string name;
	TreeNode *nodes;
	TreeNode *next;
public:
	TreeNode(string name)
	{
		this->name = name;
		nodes = NULL;
		next = NULL;
	}
	TreeNode()
	{
		cout << "Enter the name of node"; cin >> this->name;
		TreeNode(name);
	}
	static void DelTree(TreeNode *node)
	{

	}
	TreeNode * operator =(TreeNode & node)
	{
		TreeNode *newNode=new TreeNode(node.name);
		newNode->nodes = node.nodes;
		newNode->next = node.next;
		return newNode;

	}
	TreeNode * operator <<(string name)
	{
		TreeNode *newChildNode = new TreeNode(name);
		TreeNode *searchEndNode = this;
		while (searchEndNode->nodes != NULL)
		{
			searchEndNode = searchEndNode->nodes;
		}
		this->nodes = newChildNode;
		return this;

	}
	TreeNode * operator[](string name)
	{
		if (this->nodes != NULL)
		{
			TreeNode * node=(*this->nodes)[name];
			if (node->name == name)
				return node;
		}
		TreeNode *newNode = this;
		while (newNode!= NULL)
		{
			if (newNode->name == name)
			{
				return newNode;
			}
			else newNode = newNode->next;
		}
		return NULL;
		
	}
	void AddNode(string name)
	{

		TreeNode *newNode = new TreeNode(name);
		TreeNode *searchEndNode = this;
		while (searchEndNode->next != NULL)
		{
			searchEndNode = searchEndNode->next;
		}
		searchEndNode->next = newNode;
	}
	friend void PrintTree(TreeNode *, int);
	static void DeleteTree(TreeNode *root)
	{
		//if (root == NULL) return;
		delete root;
	}
	~TreeNode()
	{
		DeleteTree(this->nodes);
	}
	/*friend ostream& operator<<(ostream& os, const TreeNode& node)
	{
		return os << node.name;
	}*/
}
void PrintTree(TreeNode * node, int level)
{
	while (node != NULL)
	{
		PrintTree(node->nodes, level + 1);
		for (int i = 0; i < level + 1; cout << "   ", i++);
		cout << node->name << "  ";
		node = node->next;
		cout << endl;
	}
}
int main()
{
	TreeNode *root = NULL;
	root = new TreeNode("first");
	root->AddNode("1_1");
	root=(*root<<"2_1");
	root->AddNode("1_2");
	TreeNode *node = (*root)["2_1"];
	/*if (newNode != NULL) newNode->AddNode("2_2");*/
//	if (newNode != NULL) newNode->AddChildNode("3_1");
	/*PrintTree(root, 0);*/
	delete root;
	system("pause");
	return 0;
}