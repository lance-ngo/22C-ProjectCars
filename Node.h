#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Node
{
protected:
	T* data;
	Node* nextPtr;
public:
	Node(Node *ptr);
	Node(T &dat, Node *ptr);
	Node* getNext() const;
	T& getData() const;
	void setNext(Node *ptr);
	void setData(T &t);
	void removeData();
	~Node();
};

/*
This is the default constructor for a Node. Initializes data to nullptr
Pre : ptr – pointer to the next Node in the sequence

Post : data - initializes data to nullptr, sets the next pointer to the parameter received
*/
template <typename T>
Node<T>::Node(Node* ptr) : data(nullptr), nextPtr(ptr)
{
}

/*
This is another constructor for a Node. Initializes data to whatever is passed to it
Pre : ptr – pointer to the next Node in the sequence
d - an object of any type
Post : data, nextPtr
*/
template <typename T>
Node<T>::Node(T &dat, Node* ptr) : data(&dat), nextPtr(ptr)
{
}

/*
Returns the address of the next Node in sequence
Pre :
Post :

Return: nextPtr
*/
template <typename T>
Node<T>* Node<T>::getNext() const
{
	return nextPtr;
}

/*
Returns the data held in the Node
Pre :
Post :

Return: *data
*/
template <typename T>
T& Node<T>::getData() const
{

	return *data;
}

/*
Sets the next pointer to an address passed to the function
Pre : ptr - address of next Node
Post : nextPtr
Return:
*/
template <typename T>
void Node<T>::setNext(Node* ptr)
{
	nextPtr = ptr;
}

/*
Sets the data held in the Node to the object passed to the function
Pre : t - input data
Post : data
Return:
*/
template <typename T>
void Node<T>::setData(T &t)
{
	//removeData();
	data = &t;
}

/*
Removes data held in Node
Pre :
Post : data - set to null
Return:
*/
template <typename T>
void Node<T>::removeData()
{
	if (data)
	{
		//delete data;
	}
}

/*
Destroy the Node. Release memory
Pre :
Post :
Return:
*/
template <typename T>
Node<T>::~Node()
{
	//removeData();
	nextPtr = nullptr;
}

#endif
