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
		this->Init();
	}
	TreeNode()
	{
		cout << "Enter the name of node"; cin >> this->name;
	}
	TreeNode(const TreeNode &node)
	{
		this->name = node.name;
		this->next = node.next;
		this->nodes = node.nodes;
	}
	static void DelTree(TreeNode *node)
	{

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
	void AddChildNode(string name)
	{
		TreeNode *newChildNode = new TreeNode(name);
		TreeNode *searchEndNode = this;
		while (searchEndNode->nodes != NULL)
		{
			searchEndNode = searchEndNode->nodes;
		}
		this->nodes = newChildNode;
	}
	void Init()
	{
		nodes = NULL;
		next = NULL;
	}
	friend void PrintTree(TreeNode *, int);
	TreeNode * GetNode(int position)
	{
		position--;
		TreeNode * node = this;
		for (int i = 0; i < position && node != NULL; i++, node = node->nodes);
		return node;
	}
	static void DeleteTree(TreeNode *root)
	{
		//if (root == NULL) return;
		delete root;
	}
	~TreeNode()
	{
		DeleteTree(this->nodes);
	}

};
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
	root->AddChildNode("2_1");
	root->AddNode("1_2");
	TreeNode *newNode = root->GetNode(2);
	if (newNode != NULL) newNode->AddNode("2_2");
	if (newNode != NULL) newNode->AddChildNode("3_1");
	PrintTree(root, 0);
	delete root;
	system("pause");
	return 0;
}