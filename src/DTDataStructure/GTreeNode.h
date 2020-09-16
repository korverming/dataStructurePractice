#ifndef GTreeNode_H
#define GTreeNode_H

#include "TreeNode.h"
#include "LinkList.h"

namespace DTLib
{

template <typename T>
class GTreeNode : public TreeNode<T>
{
public:
	LinkList<GTreeNode<T>*> child;
};

}

#endif
