#ifndef BTreeNode_H
#define BTreeNode_H

#include "TreeNode.h"

namespace DTLib
{

template<typename T>
class BTreeNode : public TreeNode<T>
{
public:
	BTreeNode<T>* left;
	BTreeNode<T>* right;

	BTreeNode()
	{
		left = nullptr;
		right = nullptr;
	}

	static BTreeNode<T>* NewNode()
	{
		BTreeNode<T>* ret = new BTreeNode<T>();

		if (ret != nullptr)
			ret->m_flag = true;

		return ret;
	}
};

}
#endif
