#ifndef HASHTABLE_H
#define HASHTABLE_H

// The only slighly significant work left to do is efficiency calculations i.e recording number of insertions, comparisons, etc.

#include <iostream>
#include <cstdlib>
#include <string>
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
	unsigned operationCount;
public:
	Hashtable();
	void rehash();
	T* find(const string &str) const;
	T* find(const Car &C) const;
	void insert(T &dat);
	bool remove(const Car &C);
	bool remove(const string &str);
	unsigned generateKey(const Car &C) const;
	unsigned generateKey(const string &str) const;
	T* operator[](const string &str);
	T* operator[](const Car &C);
	void printTable(std::ostream &fout = std::cout) const;
	bool isEmpty() const;
	unsigned getArraySize() const;
	unsigned getFilledCount() const;
	unsigned getDataCount() const;
	double getLoadFactor() const;
	void setMaxLoadFactor(const double &maxLoad);
	double getMaxLoadFactor() const;
	~Hashtable();
};

template <typename T>
const unsigned Hashtable<T>::primeNumbers[] = { 89, 131, 199, 307, 449 };


// PARTIALLY INCOMPLETE
template <typename T>
Hashtable<T>::Hashtable() : primePos(0), maxLoadFactor(0.80), operationCount(0), dataCount(0), filledCount(0)
{
	hashArray = new List<T>[primeNumbers[primePos]];
	arraySize = primeNumbers[primePos];
}

// INCOMPLETE
template <typename T>
void Hashtable<T>::rehash()
{
	primePos++;
	List<T>* newArray = new List<T>[primeNumbers[primePos]];
	arraySize = primeNumbers[primePos];

	delete[] hashArray;
	hashArray = newArray;
}

template <typename T>
unsigned Hashtable<T>::generateKey(const string &str) const
{
	unsigned key = 0;
	for (size_t i = 0; i < str.size(); i++)
		key += ((i + 29) * (str[i]));
	return key % arraySize;
}

template <typename T>
unsigned Hashtable<T>::generateKey(const Car &C) const
{
	unsigned key = 0;
	string model = C.getModel();
	// for (size_t i = 0; i < model.size(); i++)
	for (size_t i = 0; i < model.size(); i++)
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
T* Hashtable<T>::find(const string &str) const
{
	return hashArray[generateKey(str)].findByModel(str);
}

template <typename T>
T* Hashtable<T>::find(const Car &C) const
{
	return hashArray[generateKey(C)].find(C);
}

template <typename T>
T* Hashtable<T>::operator[](const string &str)
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
bool Hashtable<T>::remove(const string &str)
{
	unsigned key = generateKey(dat);
	if (hashArray[key].removeByModel(str))
	{
		dataCount--;
		if (hashArray[key].getCount() == 0)
			filledCount--;
		return true;
	}
	else
		return false;
}

template <typename T>
void Hashtable<T>::printTable(std::ostream &fout) const
{
	fout << "Printing out contents of hash table" << endl;
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

#endif

