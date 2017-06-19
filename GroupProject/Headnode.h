#ifndef HEADNODE_H
#define HEADNODE_H

#include <iostream>
#include "Node.h"

/*
A special type of Node - Headnode.
Will be the first Node of a list, queue, stack, etc.
*/

template <typename T>
class Headnode
{
protected:
	// Node<T>* rearPtr;
	Node<T>* frontPtr;
	unsigned count;
public:
	Headnode();
	Headnode(Node<T>* fPtr);
	Headnode(unsigned c, Node<T>* fPtr); //, Node<T>* rPtr);
	unsigned getCount() const;
	void incrementCount();
	void decrementCount();
	//Node<T>* getRearPtr();
	Node<T>*& getFrontPtr();
	//void setRearPtr(Node<T>* p);
	void setFrontPtr(Node<T>* p);
	void resetCount();
};

template <typename T>
Headnode<T>::Headnode() : count(0), frontPtr(nullptr) //, rearPtr(nullptr)
{
}

template <typename T>
Headnode<T>::Headnode(Node<T>* fPtr) : count(1), frontPtr(fPtr) //, rearPtr(fPtr)
{
}

/*
A constructor to initialize data members of Headnode
Pre : c- number of Nodes in data structure
hptr- address of first Node following the Headnode
rptr- address of last Node in the data structure
Post :
Return:
*/
template <typename T>
Headnode<T>::Headnode(unsigned c, Node<T>* fPtr) : count(c), frontPtr(fPtr)//, rearPtr(rPtr)
{
}

///*
//Return the address of the last Node in data structure
//Pre :
//Post :
//Return: nextptr - address of the last Node in data structure
//*/
//template <typename T>
//Node<T>* Headnode<T>::getRearPtr()
//{
//	return rearPtr;
//}

/*
Return the address of the first Node in data structure
Pre :
Post :
Return: frontPtr - address of the first Node in data structure
*/
template <typename T>
Node<T>*& Headnode<T>::getFrontPtr()
{
	return frontPtr;
}

/*
Return number of Nodes in data structure
Pre :
Post :
Return: count - number of Nodes in data structure
*/
template <typename T>
unsigned Headnode<T>::getCount() const
{
	return count;
}

/*
Increment the number of Nodes
Pre:
Post: count
Return:
*/
template <typename T>
void Headnode<T>::incrementCount()
{
	count++;
}

/*
Decrement the number of Nodes
Pre:
Post: count
Return:
*/
template <typename T>
void Headnode<T>::decrementCount()
{
	count--;
}

///*
//Set the address of the last Node in data structure to the address passed
//Pre: p - input address
//Post: nextptr
//Return:
//*/
//template <typename T>
//void Headnode<T>::setRearPtr(Node<T>* p)
//{
//	rearPtr = p;
//}

/*
Set the address of the first Node in data structure to the address passed
Pre: p - input address
Post: frontPtr
Return:
*/
template <typename T>
void Headnode<T>::setFrontPtr(Node<T>* p)
{
	frontPtr = p;
}

/*
Reset the count (number of Nodes in data structure is 0)
Pre:
Post: count
Return:
*/
template <typename T>
void Headnode<T>::resetCount()
{
	count = 0;
}

#endif