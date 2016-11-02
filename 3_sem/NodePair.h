#pragma once
#include "TreeNode.h"
class NodePair
{
private:
	const TreeNode * parent;
	TreeNode *dauther;
public:
	const TreeNode * GetParent();
	
	void SetParent(TreeNode *parent);
	
	void SetDauther(TreeNode *dauther);
	TreeNode * GetDauther();

	NodePair(TreeNode *nodeToCopy, const TreeNode *nodeThatCopy);
	
};
