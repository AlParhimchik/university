#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class TreeNode;
class NodePair
{
private:
	const TreeNode * parent;
	TreeNode *dauther;
public:
	NodePair()
	{
		
		parent = NULL;
		dauther = NULL;
	}
	const TreeNode * GetParent()
	{
		return parent;
	}
	void SetParent(TreeNode *parent)
	{
		this->parent = parent;
	}
	void SetDauther(TreeNode *dauther)

	{
		this->dauther = dauther;
	}
	 TreeNode * GetDauther()
	{
		return dauther;
	}
	NodePair(TreeNode *nodeToCopy, const TreeNode *nodeThatCopy)
	{
		parent = nodeThatCopy;
		dauther = nodeToCopy;
	}
};
class List
{
private:
	NodePair *currentNode;
	List * next;
public:

	NodePair *GetNode()
	{
		return currentNode;

	}
	List(NodePair * root)
	{
		next = NULL;
		currentNode = root;
	}
	bool isEnd()
	{
		if (next == NULL) return true;
		return false;
	}
	void AddNext(List *list)
	{
		List *listSearch = this;
		while (listSearch->next != NULL) { listSearch = listSearch->next; }
		listSearch->next = list;
	}
	List * GetNext()
	{
		return next;
	}
};
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
	}
	TreeNode(const TreeNode *node)
	{
		string nodee = node->name;
		this->TreeNode::TreeNode(nodee);
		NodePair *pair = new NodePair(this,node);
		List *list=new List(pair);
		const TreeNode *myParentNode=NULL;
		TreeNode * myDautherNode=this;
		List *newList = NULL;
		NodePair * newPair = NULL;
		//TreeNode * nextNode = NULL;
		do
		{
			myParentNode = list->GetNode()->GetParent();
			myDautherNode = list->GetNode()->GetDauther();
			while (myParentNode != NULL)
			{
				//myDautherNode = new TreeNode(myParentNode->name);
				if (myParentNode->next != NULL)
				{
					
					myDautherNode->AddNode(myParentNode->next->name);
					newPair = new NodePair(myDautherNode->next, myParentNode->next);
					newList = new List(newPair);
					list->AddNext(newList);
				}
				if (myParentNode->nodes != NULL)
				{
					myDautherNode->AddChildNode(myParentNode->nodes->name);
				}
				myParentNode = myParentNode->nodes;
				myDautherNode = myDautherNode->nodes;
			}
			list = list->GetNext();
		} while ((list->isEnd()) == false);
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
		searchEndNode->nodes = newChildNode;
	}
	friend void PrintTree(TreeNode *, int);
	TreeNode * GetNode(int position)
	{
		position--;
		TreeNode * node = this;
		for (int i = 0; i < position && node != NULL; i++, node = node->nodes);
		return node;
	}
	//	static void DeleteTree(TreeNode *root)
	//	{
	//		//if (root == NULL) return;
	//		TreeNode * bla=NULL;
	//		while(root->next!=NULL)
	//		{
	//			bla=root->next;
	//			root->next=bla->next;
	//			delete bla;
	//			
	//			
	//		}
	//		delete root;
	//	}
	~TreeNode()
	{
		if (this->nodes != NULL)(this->nodes)->~TreeNode();
		if (this->next!=NULL)(this->next)->~TreeNode();
		/*while (this->next != NULL)
		{
			TreeNode *newNode = this->next;
			this->next = newNode->next;
			newNode->~TreeNode();
		}*/
		
		cout << "dasvidyli" << this->name << endl;
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
	TreeNode root("1_1");
	root.AddNode("1_2");
	root.AddChildNode("2_1");
	root.AddChildNode("3_1");
	TreeNode *newNode = root.GetNode(2);
	if (newNode != NULL)
		newNode->AddNode("2_2");
	PrintTree(&root, 0);
	root.AddChildNode("4_1");
	TreeNode copyNode(&root);
	copyNode.AddNode("1_3");
	TreeNode * node = copyNode.GetNode(3);
	node->AddChildNode("5_1");
	node->AddNode("3_2");
	node = NULL;
	PrintTree(&copyNode, 0);
	return 0;
}