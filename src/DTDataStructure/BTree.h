#ifndef BTree_H
#define BTree_H

#include "Tree.h"
#include "BTreeNode.h"
#include "Exception.h"
#include "LinuxLinkQueue.h"

namespace DTLib
{

template<typename T>
class BTree : public Tree<T>
{
public:
	bool insert(TreeNode<T>* node) override
	{
		return false;
	}

	bool insert(const T& value, TreeNode<T>* parent) override
	{
		return false;
	}

	SharedPointer<Tree<T>> remove(const T& value) override
	{
		return nullptr;
	}

	SharedPointer<Tree<T>> remove(TreeNode<T>* node) override
	{
		return nullptr;
	}

	BTreeNode<T>* find(const T& value) const override
	{
		return nullptr;
	}

	BTreeNode<T>* find(TreeNode<T>* node) const override
	{
		return nullptr;
	}

	BTreeNode<T>* root() const override
	{
		return dynamic_cast<BTreeNode<T>*>(this->m_root);
	}

	int degree() const override
	{
		return 0;
	}

	int count() const override
	{
		return 0;
	}

	int height() const override
	{
		return 0;
	}

	void clear() override
	{
		this->m_root = nullptr;
	}

	~BTree()
	{
		clear();
	}
};

}

#endif
