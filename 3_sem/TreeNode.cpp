//#include <string>
#include <iostream>
#include "TreeNode.h"
#include "List.h"
#include "NodePair.h"
	
	TreeNode::TreeNode(string name)
	{
		Init(name);
	}
	TreeNode::TreeNode()
	{
		cout << "Enter the name of node"; cin >> this->name;
		Init(name);
	}
	TreeNode * TreeNode:: operator =(TreeNode * node)
	{
		Init(node->name);
		NodePair *pair = new NodePair(this, node);
		List *list = new List(pair);
		const TreeNode *myParentNode = NULL;
		TreeNode * myDautherNode = NULL;
		List *newList = NULL;
		NodePair * newPair = NULL;
		do
		{
			myParentNode = list->GetNode()->GetParent();
			myDautherNode = list->GetNode()->GetDauther();
			while (myParentNode != NULL)
			{
				if (myParentNode->next != NULL)
				{

					myDautherNode->AddNode(myParentNode->next->name);
					newPair = new NodePair(myDautherNode->next, myParentNode->next);
					newList = new List(newPair);
					list->AddNext(newList);
				}
				if (myParentNode->nodes != NULL)
				{
					myDautherNode = *myDautherNode << myParentNode->nodes->name;
				}
				myParentNode = myParentNode->nodes;
				myDautherNode = myDautherNode->nodes;
			}
			list = list->GetNext();
		} while ((list->isEnd()) == false);
		return this;
	}
	TreeNode * TreeNode::operator<<(string name)
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
	TreeNode * TreeNode::operator[](string name)
	{
		if (this->nodes != NULL)
		{
			TreeNode * node = (*this->nodes)[name];
			if (node->name == name)
				return node;
		}
		TreeNode *newNode = this;
		while (newNode != NULL)
		{
			if (newNode->name == name)
			{
				return newNode;
			}
			else newNode = newNode->next;
		}
		return NULL;

	}
	void TreeNode::AddNode(string name)
	{

		TreeNode *newNode = new TreeNode(name);
		TreeNode *searchEndNode =this;
		while (searchEndNode->next != NULL)
		{
			searchEndNode = searchEndNode->next;
		}
		searchEndNode->next = newNode;
	}
	TreeNode::~TreeNode()
	{
		if (this->nodes != NULL)(this->nodes)->~TreeNode();
		if (this->next != NULL)(this->next)->~TreeNode();
		cout << "bye from " << this->name << endl;
	}
	void TreeNode::Init(string name)
	{
		this->name = name;
		this->next = NULL;
		this->nodes = NULL;
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
