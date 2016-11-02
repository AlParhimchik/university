#pragma once 
#include <string>
#include <iostream>
using namespace std;
class TreeNode
{
private:
	string name;
	TreeNode *nodes;
	TreeNode *next;
public:
	TreeNode(string name);
	TreeNode();
	void Init(string);
	TreeNode * operator =(TreeNode * node);
	TreeNode * operator<<(string name);
	TreeNode * operator[](string name);
	void AddNode(string name);
	friend void PrintTree(TreeNode *, int);
	~TreeNode();
	
}; 

