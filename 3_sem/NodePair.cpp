#include "NodePair.h"
const TreeNode * NodePair::GetParent()
	{
		return parent;
	}
void NodePair::SetParent(TreeNode *parent)
	{
		this->parent = parent;
	}
void NodePair::SetDauther(TreeNode *dauther)

	{
		this->dauther = dauther;
	}
TreeNode * NodePair::GetDauther()
	{
		return dauther;
	}
NodePair::NodePair(TreeNode *nodeToCopy, const TreeNode *nodeThatCopy)
	{
		parent = nodeThatCopy;
		dauther = nodeToCopy;
	}
