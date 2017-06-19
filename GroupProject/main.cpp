#include <iostream>
#include "DataManager.h"
#include "BST.h"
#include "HashTable.h"
#include "List.h"
using namespace std;
int main()
{
	BST bstree;
	Hashtable<Car> hst;
	List<Car> list;
	DataManager manager;
	manager.SetBST(&bstree);
	manager.SetList(&list);
	manager.SetHashTable(&hst);
	manager.ReadFile("carinv.txt");
	cout<<"-------"<<endl;
	hst.printTable();
	cout<<"-------"<<endl;
	list.print();
	cout << "-------" << endl;
	bstree.Print();
	system("PAUSE");
}