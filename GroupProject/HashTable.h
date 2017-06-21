#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <cmath>
#include "Car.h"
#include "List.h"

template <typename T>
class Hashtable
{
private:
	static const unsigned primeNumbers[];
	List<T>* hashArray;
	unsigned arraySize;
	unsigned filledCount;
	unsigned dataCount;
	unsigned primePos;
	double maxLoadFactor;
public:
	Hashtable();
	Hashtable(unsigned prime);
	void rehash();
	T* find(const std::string &str);
	T* find(const Car &C);
	void insert(T &dat);
	bool remove(const Car &C);
	bool remove(const std::string &str);
	unsigned generateKey(const Car &C) const;
	unsigned generateKey(const std::string &str) const;
	T* operator[](const std::string &str);
	T* operator[](const Car &C);
	void printTable(std::ostream &fout = std::cout);
	bool isEmpty() const;
	unsigned getArraySize() const;
	unsigned getFilledCount() const;
	unsigned getDataCount() const;
	double getLoadFactor() const;
	void setMaxLoadFactor(const double &maxLoad);
	double getMaxLoadFactor() const;
	~Hashtable();

	// EFFICIENCY AND EXTRA CALCULATION FUNCTIONS

	int getCollisions() const;
	double getExpectedCollisions() const;
	double getNonZeroAverageSize() const;
	double getAverageSize() const;
	unsigned getLongestListSize() const;
	std::ostream& printEfficiencyData(std::ostream &fout = std::cout);
};

template <typename T>
const unsigned Hashtable<T>::primeNumbers[] = { 89, 131, 199, 307, 449, 673, 1009 };

template <typename T>
Hashtable<T>::Hashtable() : primePos(0), maxLoadFactor(0.80), dataCount(0), filledCount(0)
{
	hashArray = new List<T>[primeNumbers[primePos]];
	arraySize = primeNumbers[primePos];
}

template <typename T>
Hashtable<T>::Hashtable(unsigned prime) : primePos(prime), maxLoadFactor(0.80), dataCount(0), filledCount(0)
{
	hashArray = new List<T>[primeNumbers[primePos]];
	arraySize = primeNumbers[primePos];
}

template <typename T>
void Hashtable<T>::rehash()
{
	primePos++;
	Hashtable<T> newHash(primePos);

	for (unsigned i = 0; i < arraySize; i++)
	{
		Node<T>* temp = hashArray[i].getHeadnode().getFrontPtr();
		while (temp != nullptr)
		{
			newHash.insert(temp->getData());
			temp = temp->getNext();
		}
	}

	delete[] hashArray;
	*this = newHash;
	newHash.hashArray = nullptr;
}

template <typename T>
unsigned Hashtable<T>::generateKey(const std::string &str) const
{
	unsigned key = 0;
	for (unsigned i = 0; i < str.size(); i++)
		key += ((i + 29) * (str[i]));

	return key % arraySize;
}

template <typename T>
unsigned Hashtable<T>::generateKey(const Car &C) const
{
	unsigned key = 0;
	std::string model = C.getModel();
	for (unsigned i = 0; i < model.size(); i++)
		key += ((i + 29) * (model[i]));
	
	return key % arraySize;
}

template <typename T>
void Hashtable<T>::insert(T &dat)
{
	unsigned key = generateKey(dat);
	hashArray[key].insert(dat);
	dataCount++;
	if (hashArray[key].getCount() == 1)
		filledCount++;
	if (getLoadFactor() > maxLoadFactor)
		rehash();
}

template <typename T>
Hashtable<T>::~Hashtable()
{
	delete[] hashArray;
	hashArray = nullptr;
}

template <typename T>
T* Hashtable<T>::find(const std::string &str)
{
	return hashArray[generateKey(str)].findByModel(str);
}

template <typename T>
T* Hashtable<T>::find(const Car &C)
{
	return hashArray[generateKey(C)].find(C);
}

template <typename T>
T* Hashtable<T>::operator[](const std::string &str)
{
	return find(str);
}

template <typename T>
T* Hashtable<T>::operator[](const Car &C)
{
	return find(C);
}

template <typename T>
bool Hashtable<T>::remove(const Car &C)
{
	unsigned key = generateKey(C);
	if (hashArray[key].remove(C))
	{
		dataCount--;
		if (hashArray[key].getCount() == 0)
			filledCount--;
		return true;
	}
	return false;
}

template <typename T>
bool Hashtable<T>::remove(const std::string &str)
{
	unsigned key = generateKey(str);
	if (hashArray[key].removeByModel(str))
	{
		dataCount--;
		if (hashArray[key].getCount() == 0)
			filledCount--;
		return true;
	}
	return false;
}

template <typename T>
void Hashtable<T>::printTable(std::ostream &fout)
{
	for (unsigned i = 0; i < arraySize; i++)
	{
		hashArray[i].print(fout);
	}
}

template <typename T>
bool Hashtable<T>::isEmpty() const
{
	if (filledCount)
		return false;
	else
		return true;
}

template <typename T>
unsigned Hashtable<T>::getFilledCount() const
{
	return filledCount;
}

template <typename T>
unsigned Hashtable<T>::getArraySize() const
{
	return arraySize;
}

template <typename T>
unsigned Hashtable<T>::getDataCount() const
{
	return dataCount;
}

template <typename T>
double Hashtable<T>::getLoadFactor() const
{
	return static_cast<double>(filledCount) / arraySize;
}

template <typename T>
void Hashtable<T>::setMaxLoadFactor(const double &maxLoad)
{
	maxLoadFactor = maxLoad;
}

template <typename T>
double Hashtable<T>::getMaxLoadFactor() const
{
	return maxLoadFactor;
}


// EFFICIENCY AND EXTRA CALCULATION FUNCTIONS

template <typename T>
double Hashtable<T>::getExpectedCollisions() const
{
	return dataCount - arraySize * (1 - pow(((arraySize - 1) / static_cast<double> (arraySize)), dataCount));
}

template <typename T>
double Hashtable<T>::getNonZeroAverageSize() const
{
	unsigned nodeCt = 0, listCt = 0, currentCount = 0;
	for (unsigned i = 0; i < arraySize; i++)
	{
		currentCount = hashArray[i].getCount();
		if (currentCount > 0)
		{
			nodeCt += currentCount;
			listCt++;
		}
	}
	return static_cast <double> (nodeCt) / listCt;
}

template <typename T>
double Hashtable<T>::getAverageSize() const
{
	unsigned nodeCt = 0, listCt = 0;
	for (unsigned i = 0; i < arraySize; i++)
	{
		nodeCt += hashArray[i].getCount();
		listCt++;
	}
	return static_cast <double> (nodeCt) / listCt;
}

template <typename T>
unsigned Hashtable<T>::getLongestListSize() const
{
	unsigned maxListSize = 0, currentCount = 0;
	for (unsigned i = 0; i < arraySize; i++)
	{
		currentCount = hashArray[i].getCount();
		if (currentCount > maxListSize)
			maxListSize = currentCount;
	}
	return maxListSize;
}

template <typename T>
int Hashtable<T>::getCollisions() const
{
	return dataCount - filledCount;
}

template <typename T>
std::ostream& Hashtable<T>::printEfficiencyData(std::ostream &fout)
{
	fout << "Printing Hash Table efficiency data" << std::endl;
	fout << "Current Load Factor: " << getLoadFactor() << std::endl;
	fout << "Average size of linked list: " << getNonZeroAverageSize() << std::endl;
	fout << "Longest linked list in hash table: " << getLongestListSize() << std::endl;
	return fout;
}

#endif
