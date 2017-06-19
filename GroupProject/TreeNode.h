#ifndef _TREE_NODE_
#define _TREE_NODE_
#include "Car.h"
class TreeNode
{
private:
	Car *data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
public:
	void SetData(Car *x)
	{
		data = x;
	}
	void SetLeft(TreeNode* l)
	{
		left = l;
	}
	void SetRight(TreeNode* r)
	{
		right = r;
	}
	void SetParent(TreeNode* p)
	{
		parent = p;
	}
	TreeNode* GetLeft()
	{
		return left;
	}
	TreeNode* GetRight()
	{
		return right;
	}
	TreeNode* GetParent()
	{
		return parent;
	}
	Car GetData()
	{
		return *data;
	}
};
#endif