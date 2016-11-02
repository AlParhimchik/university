#include "List.h"
#include "NodePair.h"
	NodePair * List::GetNode()
	{
		return currentNode;

	}
	List::List(NodePair * root)
	{
		next = NULL;
		currentNode = root;
	}
	bool List::isEnd()
	{
		if (next == NULL) return true;
		return false;
	}
	void List::AddNext(List *list)
	{
		List *listSearch = this;
		while (listSearch->next != NULL) { listSearch = listSearch->next; }
		listSearch->next = list;
	}
	List * List::GetNext()
	{
		return next;
	}
