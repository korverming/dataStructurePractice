#ifndef BTree_H
#define BTree_H

#include "Tree.h"
#include "BTreeNode.h"
#include "Exception.h"
#include "LinuxLinkQueue.h"
#include "DynamicArray.h"

namespace DTLib
{

enum BTTraversal
{
	PreOrder,
	InOrder,
	PostOrder,
	LevelOrder
};

template <typename T>
BTreeNode<T>* delOdd1(BTreeNode<T>* node)
{
	BTreeNode<T>* ret = nullptr;

	if (node != nullptr)
	{
		if
		(
			(node->left != nullptr) && (node->right == nullptr) ||
			(node->left == nullptr) && (node->right != nullptr)
		)
		{
			BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
			BTreeNode<T>* node_child = (node->left != nullptr) ? node->left : node->right;

			if (parent != nullptr)
			{
				BTreeNode<T>*& parent_child =
					(parent->left == node) ? parent->left : parent->right;
				parent_child = node_child;
				node_child->parent = parent;
			}
			else
				node_child->parent = nullptr;

			if (node->flag())
				delete node;

			ret = delOdd1(node_child);
		}
		else
		{
			delOdd1(node->left);
			delOdd1(node->right);

			ret = node;
		}
	}

	return ret;
}

template <typename T>
void delOdd2(BTreeNode<T>*& node)
{
	if (node != nullptr)
	{
		if
		(
			(node->left != nullptr) && (node->right == nullptr) ||
			(node->left == nullptr) && (node->right != nullptr)
		)
		{
			BTreeNode<T>* node_child =
				(node->left != nullptr) ? node->left : node->right;

			if (node->flag())
				delete node;

			node = node_child;

			delOdd2(node);
		}
		else
		{
			delOdd2(node->left);
			delOdd2(node->right);
		}
	}
}

template<typename T>
void inOrderThread(BTreeNode<T>* node, BTreeNode<T>*& pre)
{
	if (node != nullptr)
	{
		inOrderThread(node->left, pre);

		node->left = pre;

		if (pre != nullptr)
		{
			pre->right = node;
		}

		pre = node;

		inOrderThread(node->right, pre);
	}
}

template <typename T>
BTreeNode<T>* inOrderThread1(BTreeNode<T>* node)
{
	BTreeNode<T>* pre = nullptr;

	inOrderThread(node, pre);

	while ((node != nullptr) && (node->left != nullptr))
		node = node->left;

	return node;
}

template <typename T>
void inOrderThread2
(
	BTreeNode<T>* node,
	BTreeNode<T>*& head,
	BTreeNode<T>*& tail
)
{
	if (node != nullptr)
	{
		BTreeNode<T>* h = nullptr;
		BTreeNode<T>* t = nullptr;

		inOrderThread2(node->left, h, t);

		node->left = t;

		if (t != nullptr)
			t->right = node;

		head = (h != nullptr) ? h : node;

		h = nullptr;
		t = nullptr;

		inOrderThread2(node->right, h, t);

		node->right = h;

		if (h != nullptr)
			h->left = node;

		tail = (t != nullptr) ? t : node;
	}
}

template <typename T>
BTreeNode<T>* inOrderThread2(BTreeNode<T>* node)
{
	BTreeNode<T>* head = nullptr;
	BTreeNode<T>* tail = nullptr;

	inOrderThread2(node, head, tail);

	return head;
}

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

	void preOrderTraversal(BTreeNode<T>* node, LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		if (node != nullptr)
		{
			queue.add(node);
			preOrderTraversal(node->left, queue);
			preOrderTraversal(node->right, queue);
		}
	}

	void inOrderTraversal(BTreeNode<T>* node, LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		if (node != nullptr)
		{
			inOrderTraversal(node->left, queue);
			queue.add(node);
			inOrderTraversal(node->right, queue);
		}
	}

	void postOrderTraversal(BTreeNode<T>* node, LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		if (node != nullptr)
		{
			postOrderTraversal(node->left, queue);
			postOrderTraversal(node->right, queue);
			queue.add(node);
		}
	}

	void levelOrderTraversal(BTreeNode<T>* node, LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		if (node != nullptr)
		{
			LinuxLinkQueue<BTreeNode<T>*> tmp;

			tmp.add(node);

			while (tmp.length() > 0)
			{
				BTreeNode<T>* n = tmp.front();

				if (n->left != nullptr)
					tmp.add(n->left);

				if (n->right != nullptr)
					tmp.add(n->right);

				tmp.remove();
				queue.add(n);
			}
		}
	}

	BTreeNode<T>* clone(BTreeNode<T>* node) const
	{
		BTreeNode<T>* ret = nullptr;
		if (node != nullptr)
		{
			ret = BTreeNode<T>::NewNode();

			if (ret != nullptr)
			{
				ret->value = node->value;

				ret->left = clone(node->left);
				ret->right = clone(node->right);

				if (ret->left != nullptr)
					ret->left->parent = ret;

				if (ret->right != nullptr)
					ret->right->parent = ret;
			}
			else
			{
				THROW_EXCEPTION
				(
					NoEnoughMemoryException,
					"No memory to creat new node ..."
				);
			}
		}

		return ret;
	}

	bool equal(BTreeNode<T>* lh, BTreeNode<T>* rh) const
	{
		if (lh == rh)
			return true;
		else if ((lh != nullptr) && (rh != nullptr))
		{
			return (lh->value == rh->value) &&
				equal(lh->left, rh->left) &&
				equal(lh->right, rh->right);
		}
		else
			return false;
	}

	BTreeNode<T>* add(BTreeNode<T>* lh, BTreeNode<T>* rh) const
	{
		BTreeNode<T>* ret = nullptr;

		if ((lh == nullptr) && (rh != nullptr))
			ret = clone(rh);
		else if ((lh != nullptr) && (rh == nullptr))
			ret = clone(lh);
		else if ((lh != nullptr) && (rh != nullptr))
		{
			ret = BTreeNode<T>::NewNode();

			if (ret != nullptr)
			{
				ret->value = lh->value + rh->value;
				ret->left = add(lh->left, rh->left);
				ret->right = add(lh->right, rh->right);

				if (ret->left != nullptr)
					ret->left->parent = ret;

				if (ret->right != nullptr)
					ret->right->parent = ret;
			}
			else
				THROW_EXCEPTION
				(
					NoEnoughMemoryException,
					"No memory to create new node ..."
				);
		}

		return ret;
	}

	void traversal(BTTraversal order, LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		switch (order)
		{
		case PreOrder:
			preOrderTraversal(root(), queue);
			break;

		case InOrder:
			inOrderTraversal(root(), queue);
			break;

		case PostOrder:
			postOrderTraversal(root(), queue);
			break;

		case LevelOrder:
			levelOrderTraversal(root(), queue);
			break;

		default:
			THROW_EXCEPTION
			(
				InvalidParameterException,
				"Parameter order is invalid ..."
			);
			break;
		}
	}

	BTreeNode<T>* connect(LinuxLinkQueue<BTreeNode<T>*>& queue)
	{
		BTreeNode<T>* ret = nullptr;

		if (queue.length() > 0)
		{
			ret = queue.front();

			BTreeNode<T>* slider = queue.front();

			queue.remove();

			slider->left = nullptr;

			while (queue.length() > 0)
			{
				slider->right = queue.front();
				queue.front()->left = slider;
				slider = queue.front();
				queue.remove();
			}

			slider->right = nullptr;
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

	SharedPointer<Array<T>> traversal(BTTraversal order)
	{
		DynamicArray<T>* ret = nullptr;
		LinuxLinkQueue<BTreeNode<T>*> queue;

		traversal(order, queue);

		ret = new DynamicArray<T>(queue.length());

		if (ret != nullptr)
		{
			for (int i = 0; i < ret->length(); i++, queue.remove())
				ret->set(i, queue.front()->value);
		}
		else
		{
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to create return array ..."
			);
		}
		return ret;
	}

	BTreeNode<T>* thread(BTTraversal order)
	{
		BTreeNode<T>* ret = nullptr;
		LinuxLinkQueue<BTreeNode<T>*> queue;

		traversal(order, queue);

		ret = connect(queue);

		this->m_root = nullptr;

		m_queue.clear();

		return ret;
	}

	SharedPointer<BTree<T>> clone() const
	{
		BTree<T>* ret = new BTree<T>();

		if (ret != nullptr)
		{
			ret->m_root = clone(root());
		}
		else
		{
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to create new tree ..."
			);
		}

		return ret;
	}

	bool operator==(const BTree<T>& btree)
	{
		return equal(root(), btree.root());
	}

	bool operator!=(const BTree<T>& btree)
	{
		return !(*this == btree);
	}

	SharedPointer<BTree<T>> add(const BTree<T>& btree) const
	{
		BTree<T>* ret = new BTree<T>();

		if (ret != nullptr)
			ret->m_root = add(root(), btree.root());
		else
			THROW_EXCEPTION
			(
				NoEnoughMemoryException,
				"No memory to create new tree ..."
			);

		return ret;
	}

	~BTree()
	{
		clear();
	}
};

}

#endif
