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
	LinuxLinkQueue<BTreeNode<T>*> m_queue;

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

	int count(BTreeNode<T>* node) const
	{
		/*int ret = 0;

		if (node != nullptr)
			ret = count(node->left) + count(node->right) + 1;

		return ret;*/

		return (node != nullptr) ? (count(node->left) + count(node->right) + 1) : 0;
	}

	int height(BTreeNode<T>* node) const
	{
		int ret = 0;

		if (node != nullptr)
		{
			int lh = height(node->left);
			int rh = height(node->right);

			ret = ((lh > rh) ? lh : rh) + 1;
		}

		return ret;
	}

	int degree(BTreeNode<T>* node) const
	{
		int ret = 0;

		if (node != nullptr)
		{
			BTreeNode<T>* child[] = { node->left, node->right };

			ret = (!!node->left + !!node->right);

			for (int i = 0; (i < 2) && (ret < 2); i++)
			{
				int d = degree(child[i]);

				if (ret < d)
					ret = d;
			}
		}

		return ret;
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

			m_queue.clear();
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

			m_queue.clear();
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
		return degree(root());
	}

	int count() const override
	{
		return count(root());
	}

	int height() const override
	{
		return height(root());
	}

	void clear() override
	{
		free(root());

		m_queue.clear();

		this->m_root = nullptr;
	}

	bool begin() override
	{
		bool ret = (root() != nullptr);

		if (ret)
		{
			m_queue.clear();
			m_queue.add(root());
		}

		return ret;
	}

	bool end() override
	{
		return (m_queue.length() == 0);
	}

	bool next() override
	{
		bool ret = (m_queue.length() > 0);

		if (ret)
		{
			BTreeNode<T>* node = m_queue.front();

			m_queue.remove();

			if (node->left != nullptr)
				m_queue.add(node->left);

			if (node->right != nullptr)
				m_queue.add(node->right);
		}

		return ret;
	}

	T current() override
	{
		if (!end())
			return m_queue.front()->value;
		else
			THROW_EXCEPTION
			(
				InvalidOperationException,
				"No value at current position ..."
			);
	}

	~BTree()
	{
		clear();
	}
};

}

#endif
