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
	static void DeleteTree(TreeNode *root)
	{
		delete root;
	}
	~TreeNode()
	{
		DeleteTree(this->nodes);
	}
	friend	void operator<<(ostream &,const TreeNode *);
	friend	void operator>>(istream &,TreeNode *);
};
void operator<<(ostream & os,const TreeNode * node)
{
	while (node != NULL)
	{
		os<<node->nodes;
		os << node->name << "  ";
		node = node->next;
		os <<" ";
	}
	cout<<endl;
	
}
void operator>>(istream & is,TreeNode * node)
{
	
}
int main()
{
	TreeNode *root = NULL;
	root = new TreeNode("first");
	root->AddNode("1_1");
	root=(*root<<"2_1");
	root->AddNode("1_2");
	TreeNode *node = (*root)["2_1"];
	cout<<root;
	delete root;
	return 0;
}
