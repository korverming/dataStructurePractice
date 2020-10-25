#ifndef BTree_H
#define BTree_H

#include "Tree.h"
#include "BTreeNode.h"
#include "Exception.h"
#include "LinuxLinkQueue.h"

namespace DTLib
{

enum BTNodePos
{
	ANY,
	LEFT,
	RIGHT
};

template<typename T>
class BTree : public Tree<T>
{
protected:
	virtual BTreeNode<T>* find(BTreeNode<T>* node, const T& value) const
	{
		BTreeNode<T>* ret = nullptr;

		if (node != nullptr)
		{
			if (node->value == value)
				ret = node;
			else
			{
				if (ret == nullptr)
					ret = find(node->left, value);

				if (ret == nullptr)
					ret = find(node->right, value);
			}
		}

		return ret;
	}

	virtual BTreeNode<T>* find(BTreeNode<T>* node, BTreeNode<T>* obj) const
	{
		BTreeNode<T>* ret = nullptr;

		if (node == obj)
			ret = node;
		else
		{
			if (node != nullptr)
			{
				if (ret == nullptr)
					ret = find(node->left, obj);

				if (ret == nullptr)
					ret = find(node->right, obj);
			}
		}

		return ret;
	}

	virtual bool insert(BTreeNode<T>* n, BTreeNode<T>* np, BTNodePos pos)
	{
		bool ret = true;

		if (pos == ANY)
		{
			if (np->left == nullptr)
				np->left = n;
			else if (np->right == nullptr)
				np->right = n;
			else
				ret = false;
		}
		else if (pos == LEFT)
		{
			if (np->left == nullptr)
				np->left = n;
			else
				ret = false;
		}
		else if (pos == RIGHT)
		{
			if (np->right == nullptr)
				np->right = n;
			else
				ret = false;
		}
		else
			ret = false;

		return ret;
	}

	virtual void remove(BTreeNode<T>* node, BTree<T>*& ret)
	{
		ret = new BTree<T>();

		if (ret == nullptr)
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to create new tree ..."
			);
		else
		{
			if (root() == node)
				this->m_root = nullptr;
			else
			{
				BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);

				if (parent->left == node)
					parent->left = nullptr;
				else if (parent->right == node)
					parent->right = nullptr;

				node->parent = nullptr;
			}

			ret->m_root = node;
		}
	}

	virtual void free(BTreeNode<T>* node)
	{
		if (node != nullptr)
		{
			free(node->left);
			free(node->right);

			if (node->flag())
				delete node;
		}
	}

public:
	bool insert(TreeNode<T>* node) override
	{
		return insert(node, ANY);
	}

	virtual bool insert(TreeNode<T>* node, BTNodePos pos)
	{
		bool ret = true;

		if (node != nullptr)
		{
			if (this->m_root == nullptr)
			{
				node->parent = nullptr;
				this->m_root = node;
			}
			else
			{
				BTreeNode<T>* np = find(node->parent);

				if (np != nullptr)
					ret = insert(dynamic_cast<BTreeNode<T>*>(node), np, pos);
				else
					THROW_EXCEPTION
					(
						InvalidParameterException,
						"Invalid parent tree node ..."
					);
			}
		}
		else
			THROW_EXCEPTION
			(
				InvalidParameterException,
				"Parameter node can't be null"
			);

		return ret;
	}

	bool insert(const T& value, TreeNode<T>* parent) override
	{
		return insert(value, parent, ANY);
	}

	virtual bool insert(const T& value, TreeNode<T>* parent, BTNodePos pos)
	{
		bool ret = true;
		BTreeNode<T>* node = BTreeNode<T>::NewNode();

		if (node == nullptr)
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to create new node ..."
			);
		else
		{
			node->value = value;
			node->parent = parent;

			ret = insert(node, pos);

			if (!ret)
				delete node;
		}

		return ret;
	}

	SharedPointer<Tree<T>> remove(const T& value) override
	{
		BTree<T>* ret = nullptr;
		BTreeNode<T>* node = find(value);

		if (node == nullptr)
			THROW_EXCEPTION
			(
				InvalidParameterException,
				"Can not find the tree node via value ..."
			);
		else
		{
			remove(node, ret);
		}

		return ret;
	}

	SharedPointer<Tree<T>> remove(TreeNode<T>* node) override
	{
		BTree<T>* ret = nullptr;

		node = find(node);

		if (node == nullptr)
			THROW_EXCEPTION
			(
				InvalidParameterException,
				"Parameter node is invalid ..."
			);
		else
		{
			remove(dynamic_cast<BTreeNode<T>*>(node), ret);
		}

		return ret;
	}

	BTreeNode<T>* find(const T& value) const override
	{
		return find(root(), value);
	}

	BTreeNode<T>* find(TreeNode<T>* node) const override
	{
		return find(root(), dynamic_cast<BTreeNode<T>*>(node));
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
		free(root());

		this->m_root = nullptr;
	}

	~BTree()
	{
		clear();
	}
};

}

#endif
