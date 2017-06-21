#ifndef _BST_
#define _BST_

#include "TreeNode.h"
#include "string"
#include <iomanip>
#include "Logger.h"
class BST
{
protected:
	const int indent = 4;
	std::string keyName;
	Logger logger;
	TreeNode* root;
	TreeNode* getLargest(TreeNode* r)
	{
		TreeNode* t = r;
		while (t->GetRight())
		{
			t = t->GetRight();
		}
		return t;
	}
	TreeNode* getSmallest(TreeNode* r)
	{
		TreeNode* t = r;
		while (t->GetLeft())
		{
			t = t->GetLeft();
		}
		return t;
	}
	void clear(TreeNode *x)
	{
		if (x == nullptr)
			return;
		if (x->GetLeft() != nullptr)
			clear(x->GetLeft());
		if (x->GetRight() != nullptr)
			clear(x->GetRight());
		
		delete x;
	}
	void print_range_tree(TreeNode *x,int l, int r, std::ostream &bstout)
	{
		if(x->GetData().getMsrp()>=l && x->GetData().getMsrp()<=r)
			bstout<<((x->GetData()))<<std::endl;
		if(x->GetLeft() != nullptr)
		{
			if(x->GetData().getMsrp()>=l)
				print_range_tree(x->GetLeft(),l,r,bstout);
		}
		if(x->GetRight() != nullptr)
		{
			if(x->GetData().getMsrp()<=r)
				print_range_tree(x->GetRight(),l,r,bstout);
		}
	}
public:
	BST()
	{
		root = nullptr;
	}
	void Insert(Car *x)
	{
		TreeNode *t = Search(x);
		TreeNode* tar = new TreeNode();
		tar->SetData(x);
		tar->SetParent(t);
		if (t == nullptr)
		{
			root = tar;
			return;
		}
		
		if (x->getMsrp() > t->GetData().getMsrp())
			t->SetRight(tar);
		else
			t->SetLeft(tar);
	}
	TreeNode* Search(Car *x)
	{
		int cmpCount = 0;
		TreeNode* t = root;
		while (t != nullptr)
		{
			cmpCount++;
			if (x->getMsrp() > t->GetData().getMsrp())
			{
				if (t->GetRight() != nullptr)
					t = t->GetRight();
				else
				{
					logger.Record(cmpCount);
					return t;
				}
			}
			else if (x->getMsrp() < t->GetData().getMsrp())
			{
				if (t->GetLeft() != nullptr)
					t = t->GetLeft();
				else
				{
					logger.Record(cmpCount);
					return t;
				}
			}
			else
			{
				logger.Record(cmpCount);
				return t;
			}
		}
		logger.Record(cmpCount);
		return nullptr;
	}
	void Remove(Car *x)
	{
		TreeNode* t = Search(x);
		if (t->GetLeft() == nullptr && t->GetRight() == nullptr)
		{
			if (t->GetData().getMsrp() > t->GetParent()->GetData().getMsrp())
				t->GetParent()->SetRight(nullptr);
			else
				t->GetParent()->SetLeft(nullptr);
			return;
		}
		if (t->GetLeft() == nullptr)
		{
			if(t->GetData().getMsrp() > t->GetParent()->GetData().getMsrp())
				t->GetParent()->SetRight(t->GetRight());
			else
				t->GetParent()->SetLeft(t->GetRight());
			return;
		}
		if (t->GetRight() == nullptr)
		{
			if (t->GetData().getMsrp() > t->GetParent()->GetData().getMsrp())
				t->GetParent()->SetRight(t->GetLeft());
			else
				t->GetParent()->SetLeft(t->GetLeft());
			return;
		}
		if (t->GetData().getMsrp() > t->GetParent()->GetData().getMsrp())
		{
			TreeNode* s = getSmallest(t->GetRight());
			s->GetParent()->SetLeft(nullptr);
			t->GetParent()->SetRight(s);
			s->SetParent(t->GetParent());
			if(s!= t->GetLeft())
				s->SetLeft(t->GetLeft());
			if(s!=t->GetRight())
				s->SetRight(t->GetRight());
		}
		else
		{
			TreeNode* s = getLargest(t->GetLeft());
			s->GetParent()->SetRight(nullptr);
			t->GetParent()->SetLeft(s);
			s->SetParent(t->GetParent());
			if (s != t->GetLeft())
				s->SetLeft(t->GetLeft());
			if (s != t->GetRight())
				s->SetRight(t->GetRight());
		}
		delete t;
	}
	void Print_Range(int l, int r , std::ostream &x = std::cout)
	{
		print_range_tree(root,l,r,x);
	}
	void Print(std::ostream &x = std::cout)
	{
		root->printTree(x);
		//print_tree(root,0,-1,x);
	}
	void GetPerformance()
	{
		logger.Print();
	}
	void ClearPerformance()
	{
		logger.Clear();
	}
	~BST()
	{
		clear(root);
	}
};
#endif