#include "Car.h"
#include <fstream>
#include "BST.h"
#include "HashTable.h"
#include "List.h"
class DataManager
{
private:
	Car* data[100];
	int curInd;
	Hashtable<Car>* hshmap;
	BST* bst;
	List<Car>* lst;
public:
	DataManager()
	{
		curInd = 0;
	}
	void Add(Car* x)
	{
		data[curInd++] = x;
		hshmap->insert(*x);
		bst->Insert(x);
		lst->insertByHp(*x);
	}
	void Remove(Car* tar)
	{
		bst->Remove(tar);
		hshmap->remove(*tar);
		lst->removeByHp(*tar);
	}
	Car* Find(std::string value)
	{
		return hshmap->find(value);
	}
	void SetBST(BST* t)
	{
		bst = t;
	}
	void SetList(List<Car>* t)
	{
		lst = t;
	}
	void SetHashTable(Hashtable<Car>* t)
	{
		hshmap = t;
	}
	void ReadFile(std::string name)
	{
		std::ifstream carsIn(name);
		if (carsIn.fail())
		{
			std::cerr << "could not open cars file";
			exit(1);
		}

		std::string buffer, make, model, body, trans;
		int msrp, hp, cap, stock;
		size_t p1, p2, p3, p4, p5, p6, p7;

		while (getline(carsIn, buffer))
		{
			p1 = buffer.find(',');
			p2 = buffer.find(',', p1 + 1);
			p3 = buffer.find(',', p2 + 1);
			p4 = buffer.find(',', p3 + 1);
			p5 = buffer.find(',', p4 + 1);
			p6 = buffer.find(',', p5 + 1);
			p7 = buffer.find(',', p6 + 1);

			make = buffer.substr(0, p1);
			model = buffer.substr(p1 + 1, p2 - (p1 + 1));
			msrp = stoi(buffer.substr(p2 + 1, p3 - (p2 + 1)));
			hp = stoi(buffer.substr(p3 + 1, p4 - (p3 + 1)));
			body = buffer.substr(p4 + 1, p5 - (p4 + 1));
			cap = stoi(buffer.substr(p5 + 1, p6 - (p5 + 1)));
			trans = buffer.substr(p6 + 1, p7 - (p6 + 1));
			stock = stoi(buffer.substr(p7 + 1));

			Car* tempCar = new Car(make, model, msrp, hp, stock, body, cap, trans);
			Add(tempCar);
		}
	}
	~DataManager()
	{
		for (int i = 0;i < curInd;i++)
		{
			if (data[i] != nullptr)
				delete data[i];
		}
	}
};
