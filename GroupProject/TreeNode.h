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
	void p_printTree(std::ostream &out, bool isRight, std::string indent){
		if (right != nullptr) {
			right->p_printTree(out, true, indent + (isRight ? "           " : " |         "));
		}
		out << indent;
		if (isRight) {
			out<<" /";
		}
		else {
			out<<" \\";
		}
		out<<"-------- ";
		out <<"("<< data->getModel()<<", "<<data->getMsrp()*1.0/1000<<"k)"<<std::endl;
		if (left != nullptr) {
			left->p_printTree(out, false, indent + (isRight ? " |         " : "           "));
		}
	}
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
	void printTree(std::ostream &out) {
		if (right != nullptr) {
			right->p_printTree(out, true, "");
		}
		out << "(" << data->getModel() << ", " << data->getMsrp()*1.0 / 1000 << "k)" << std::endl;
		if (left != nullptr) {
			left->p_printTree(out, false, "");
		}
	}
};
#endif