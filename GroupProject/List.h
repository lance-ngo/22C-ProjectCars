#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Node.h"
#include "Headnode.h"

template <typename T>
class List
{
protected:
	Headnode<T> H;
	unsigned callCount;
	unsigned operationCount;
public:
	List();
	Headnode<T>& getHeadnode();
	unsigned getCount() const;
	void printCount(std::ostream &fout) const;
	void emptyList();
	T* find(const T &dat);
	void findByHp(const int& hp, std::ostream& fout = std::cout);
	T* findByModel(const std::string& str);
	bool isEmpty() const;
	void insert(T &dat);
	void insertByHp(T &t);
	bool removeByHp(const T &dat);
	bool remove(std::string dat);
	bool saveToFile(std::string x);
	std::ostream& print(std::ostream &fout = std::cout);
	void printEfficiency(std::ostream& fout = std::cout) const;
	//friend std::ostream& operator<<(std::ostream& fout, const List<T>& L);
	~List();
};

// PARTIALLY INCOMPLETE
template <typename T>
List<T>::List() : H(), callCount(0), operationCount(0)
{
}

/*
Return Headnode
Pre:
Post:
Return: H - Headnode of list
*/
template <typename T>
Headnode<T>& List<T>::getHeadnode()
{
	return H;
}

/*
Return number of Nodes in linked list
Pre:
Post:
Return: count - number of Nodes in linked list
*/
template <typename T>
unsigned List<T>::getCount() const
{
	return H.getCount();
}

/*
Print the number of Nodes in the list to a specified stream
Pre: fout - specified stream
Post:
Return:
*/
template <typename T>
void List<T>::printCount(std::ostream &fout) const
{
	fout << "The list has " << getCount() << " objects" << std::endl << std::endl;
}

/*
Clear contents of list. Release memory
Pre:
Post:
Return:
*/
template <typename T>
void List<T>::emptyList()
{
	Node<T>* temp = H.getFrontPtr();
	while (temp != nullptr)
	{
		H.setFrontPtr(temp->getNext());
		delete temp;
		temp = H.getFrontPtr();
	}
	H.resetCount();
}

/*
Find a specified object in the list
Pre: t - object to be searched for
Post:
Return: true/false depending on if the operation is successful
*/
template <typename T>
T* List<T>::find(const T &dat)
{
	Node<T>* temp1 = H.getFrontPtr();
	while (temp1 != nullptr)
	{
		if (dat == temp1->getData())
			return &(temp1->getData());
		temp1 = temp1->getNext();
	}
	return nullptr;
}

template <typename T>
T* List<T>::findByModel(const std::string& str)
{
	Node<T>* temp1 = H.getFrontPtr();
	while (temp1 != nullptr && temp1->getData().getModel() <= str)
	{
		if (temp1->getData().getModel() == str)
		{
			return &temp1->getData();
		}
		temp1 = temp1->getNext();
	}
	return nullptr;
}

/*
Print all objects held in the Nodes in a list
Pre: fout - stream to print to
Post:
Return:
*/
template <typename T>
std::ostream& List<T>::print(std::ostream& fout)
{
	Node<T>* temp = H.getFrontPtr();
	while (temp != nullptr)
	{
		fout << temp->getData() << std::endl;
		temp = temp->getNext();
	}
	return fout;
}

template <typename T>
bool List<T>::saveToFile(std::string x)
{
	std::ofstream fout(x);
	if (!fout)
		return 0;
	Node<T>* temp = H.getFrontPtr();
	while (temp != nullptr)
	{
		fout << temp->getData().toCsv() << std::endl;
		temp = temp->getNext();
	}
	return 1;
}

//template <typename T>
//std::ostream& operator<<(std::ostream& fout, const List<T>& L)
//{
//	L.print(fout);
//	return fout;
//}

/*
Check if list is empty
Pre:
Post:
Return: true/false depending on if the operation is successful
*/
template <typename T>
bool List<T>::isEmpty() const
{
	if (H.getCount == 0)
		return true;
	else
		return false;
}

/*
Clear contents of list. Release memory
Pre:
Post:
Return:
*/
template <typename T>
List<T>::~List()
{
	emptyList();
}

/*
Remove a Node holding the specified value from the list if it exists.
Pre: t - value to be removed
fout - stream to print appropriate message to
Post:
Return: true/false depending on if the operation is successful
*/
template<typename T>
bool List<T>::removeByHp(const T &dat)
{
	callCount++;
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = 0;

	if (H.getFrontPtr() == nullptr)
	{
		operationCount++;
		return false;
	}

	if (dat == temp1->getData())
	{
		H.setFrontPtr(temp1->getNext());
		H.decrementCount();
		delete temp1;
		operationCount++;
		return true;
	}

	while (temp1 != nullptr && temp1->getData().getHp() <= dat.getHp())
	{
		operationCount++;
		if (temp1->getData().getHp() == dat.getHp())
		{
			operationCount++;
			H.decrementCount();
			temp2->setNext(temp1->getNext());
			delete temp1;
			return true;
		}
		temp2 = temp1;
		temp1 = temp1->getNext();
	}

	operationCount++;
	return false;
}

template<typename T>
bool List<T>::remove(std::string dat)
{
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = 0;

	if (H.getFrontPtr() == nullptr)
	{
		return false;
	}

	if (dat == temp1->getData().getModel())
	{
		H.setFrontPtr(temp1->getNext());
		H.decrementCount();
		delete temp1;
		return true;
	}

	while (temp1 != nullptr && temp1->getData().getModel() <= dat)
	{
		if (temp1->getData().getModel() == dat)
		{
			H.decrementCount();
			temp2->setNext(temp1->getNext());
			delete temp1;
			return true;
		}
		temp2 = temp1;
		temp1 = temp1->getNext();
	}

	return false;
}

/*
Inserts a specified value to a specified position in the list
Pre: p - position to insert object in
t - data to be inserted
Post:
Return:
*/
template<typename T>
void List<T>::insert(T& dat)
{
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = nullptr;

	if (temp1 == nullptr)
	{
		H.setFrontPtr(new Node<T>((dat), temp1));
		H.incrementCount();
		//insertCount++;
		return;
	}

	if (dat.getHp() <= temp1->getData().getHp())
	{
		//comparisonCount++;
		H.setFrontPtr(new Node<T>((dat), temp1));
		H.incrementCount();
		//insertCount++;
		return;
	}

	while (temp1->getData().getHp() < dat.getHp())
	{
		//comparisonCount++;
		temp2 = temp1;
		temp1 = temp1->getNext();
		if (temp1 == nullptr)
		{
			temp2->setNext(new Node<T>(dat, nullptr));
			H.incrementCount();
			//H.setRearPtr(temp2->getNext());
			//insertCount++;
			return;
		}
	}

	//comparisonCount++;
	temp2->setNext(new Node<T>((dat), temp1));
	H.incrementCount();

	//if (temp1 == nullptr)
	//H.setRearPtr(temp2->getNext());

	//insertCount++;
}

/*
Inserts a specified value to a specified position in the list
Pre: p - position to insert object in
t - data to be inserted
Post:
Return:
*/
template<typename T>
void List<T>::insertByHp(T &t)
{
	callCount++;
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = nullptr;

	if (temp1 == nullptr)
	{
		H.setFrontPtr(new Node<T>(t, temp1));
		H.incrementCount();
		//H.setRearPtr(H.getFrontPtr());
		//callCount++;
		operationCount++;
		return;
	}

	if (t.getHp() <= temp1->getData().getHp())
	{	
		H.setFrontPtr(new Node<T>(t, temp1));
		H.incrementCount();
		//callCount++;
		operationCount++;
		return;
	}

	while (t.getHp() > temp1->getData().getHp())
	{
		temp2 = temp1;
		temp1 = temp1->getNext();
		operationCount++;
		if (temp1 == nullptr)
		{
			temp2->setNext(new Node<T>(t, nullptr));
			H.incrementCount();
			//callCount++;
			operationCount++;
			return;
		}
	}

	operationCount++;
	temp2->setNext(new Node<T>(t, temp1));
	H.incrementCount();

}

template <typename T>
void List<T>::findByHp(const int& hp, std::ostream& fout)
{
	callCount++;
	Node<T>* temp1 = H.getFrontPtr();
	fout << "Printing cars more than " << hp << " horsepower" << std::endl;
	while (temp1 != nullptr)
	{
		operationCount++;
		if (temp1->getData().getHp() >= hp)
		{
			operationCount++;
			while (temp1 != nullptr)
			{
				fout << temp1->getData() << std::endl;
				temp1 = temp1->getNext();
			}
			return;
		}
		temp1 = temp1->getNext();
	}
	operationCount++;
}

template <typename T>
void List<T>::printEfficiency(std::ostream& fout) const
{
	fout << "Printing efficiency for linked list: " << operationCount * 1.0/ callCount << endl;
}

#endif
