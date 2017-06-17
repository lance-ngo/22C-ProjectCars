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
	unsigned insertCount;
	unsigned comparisonCount;
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
	bool remove(const T &dat);
	bool removeByModel(const std::string &str);
	std::ostream& print(std::ostream &fout = cout);
	//friend std::ostream& operator<<(std::ostream& fout, const List<T>& L);
	~List();
};

// PARTIALLY INCOMPLETE
template <typename T>
List<T>::List() : H()
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
	fout << "The list has " << getCount() << " objects" << endl << endl;
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
		fout << temp->getData() << endl;
		temp = temp->getNext();
	}
	return fout;
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
bool List<T>::remove(const T &dat)
{
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = 0;

	if (H.getFrontPtr() == nullptr)
	{
		//fout << "List is empty" << endl << endl;
		return false;
	}

	if (dat == temp1->getData())
	{
		H.setFrontPtr(temp1->getNext());
		//if (temp1->getNext() == nullptr)
			//H.setRearPtr(nullptr);
		H.decrementCount();
		delete temp1;
		return true;
	}

	while (temp1 != nullptr)
	{
		if (temp1->getData() == dat)
		{
			H.decrementCount();
			temp2->setNext(temp1->getNext());
			//if (temp1->getNext() == nullptr)
				//H.setRearPtr(temp2);
			delete temp1;
			return true;
		}
		temp2 = temp1;
		temp1 = temp1->getNext();
	}

	//fout << "Value not found" << endl << endl;
	return false;
}

template<typename T>
bool List<T>::removeByModel(const std::string &str)
{
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = 0;

	if (H.getFrontPtr() == nullptr)
	{
		//fout << "List is empty" << endl << endl;
		return false;
	}

	if (str == temp1->getData().getModel())
	{
		H.setFrontPtr(temp1->getNext());
		//if (temp1->getNext() == nullptr)
			//H.setRearPtr(nullptr);
		H.decrementCount();
		delete temp1;
		return true;
	}

	while (temp1 != nullptr)
	{
		if (temp1->getData().getModel() == str)
		{
			H.decrementCount();
			temp2->setNext(temp1->getNext());
			//if (temp1->getNext() == nullptr)
				//H.setRearPtr(temp2);
			delete temp1;
			return true;
		}
		temp2 = temp1;
		temp1 = temp1->getNext();
	}
	//fout << "Value not found" << endl << endl;
	return false;
}

///*
//Remove a Node holding the specified value from the list if it exists.
//Pre: t - value to be removed
//fout - stream to print appropriate message to
//Post:
//Return: true/false depending on if the operation is successful
//*/
//template<typename T>
//bool List<T>::removeByHp(const T &dat)
//{
//	Node<T>* temp1 = H.getFrontPtr();
//	Node<T>* temp2 = 0;
//
//	if (H.getFrontPtr() == nullptr)
//	{
//		//fout << "List is empty" << endl << endl;
//		return false;
//	}
//
//	if (dat == temp1->getData())
//	{
//		H.setFrontPtr(temp1->getNext());
//		//if (temp1->getNext() == nullptr)
//			//H.setRearPtr(nullptr);
//		H.decrementCount();
//		delete temp1;
//		return true;
//	}
//
//	while (temp1 != nullptr)
//	{
//		if (temp1->getData() == dat)
//		{
//			H.decrementCount();
//			temp2->setNext(temp1->getNext());
//			//if (temp1->getNext() == nullptr)
//				//H.setRearPtr(temp2);
//			delete temp1;
//			return true;
//		}
//		temp2 = temp1;
//		temp1 = temp1->getNext();
//	}
//
//	//fout << "Value not found" << endl << endl;
//	return false;
//}

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
		//H.setRearPtr(H.getFrontPtr());
		insertCount++;
		return;
	}

	if (dat <= temp1->getData())
	{
		comparisonCount++;
		H.setFrontPtr(new Node<T>((dat), temp1));
		H.incrementCount();
		insertCount++;
		return;
	}

	while (temp1->getData() < dat)
	{
		comparisonCount++;
		temp2 = temp1;
		temp1 = temp1->getNext();
		if (temp1 == nullptr)
		{
			temp2->setNext(new Node<T>(dat, nullptr));
			H.incrementCount();
			//H.setRearPtr(temp2->getNext());
			insertCount++;
			return;
		}
	}

	comparisonCount++;
	temp2->setNext(new Node<T>((dat), temp1));
	H.incrementCount();

	//if (temp1 == nullptr)
		//H.setRearPtr(temp2->getNext());

	insertCount++;
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
	Node<T>* temp1 = H.getFrontPtr();
	Node<T>* temp2 = nullptr;

	if (temp1 == nullptr)
	{
		H.setFrontPtr(new Node<T>(t, temp1));
		H.incrementCount();
		//H.setRearPtr(H.getFrontPtr());
		insertCount++;
		return;
	}

	if (t.getHp() <= temp1->getData().getHp())
	{
		comparisonCount++;
		H.setFrontPtr(new Node<T>(t, temp1));
		H.incrementCount();
		insertCount++;
		return;
	}

	while (t.getHp() > temp1->getData().getHp())
	{
		comparisonCount++;
		temp2 = temp1;
		temp1 = temp1->getNext();
		if (temp1 == nullptr)
		{
			temp2->setNext(new Node<T>(t, nullptr));
			H.incrementCount();
			//H.setRearPtr(temp2->getNext());
			insertCount++;
			return;
		}
	}

	comparisonCount++;
	temp2->setNext(new Node<T>(t, temp1));
	H.incrementCount();

	//if (temp1 == nullptr)
		//H.setRearPtr(temp2->getNext());

	insertCount++;
}

template <typename T>
void List<T>::findByHp(const int& hp, std::ostream& fout)
{
	Node<T>* temp1 = H.getFrontPtr();
	fout << "Printing cars more than " << hp << " horsepower" << endl;
	while (temp1 != nullptr)
	{
		if (temp1->getData().getHp() >= hp)
		{
			while (temp1 != nullptr)
			{
				fout << temp1->getData() << endl;
				temp1 = temp1->getNext();
			}
			return;
		}
		temp1 = temp1->getNext();
	}
}

#endif
