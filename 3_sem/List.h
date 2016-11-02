#pragma once 
#include "NodePair.h"
class List
{
private:
	NodePair *currentNode;
	List * next;
public:

	NodePair *GetNode();
	
	List(NodePair * root);
	
	bool isEnd();
	
	void AddNext(List *list);
	
	List * GetNext();
	
};
