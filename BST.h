#pragma once

#include "BSTNode.h"
#include <fstream>

template <class T>
class BST
{
public:
	
	BST();

	~BST();

	//Accessors

	BSTNode<T> *getRootPtr();

	void setRootPtr(BSTNode<T> *newRootPtr);

/*************************************************************
Function: insertNode
Parameters: reference to object of type T
Returns: bool
Description: calls the private function of the same name
**************************************************************/
	bool insertNode(T &newData);
/*************************************************************
Function: printTree
Parameters: void
Returns: void
Description: calls the private function of the same name
**************************************************************/
	void printTree() const;
/*************************************************************
Function: searchTree
Parameters: reference to object of type T
Returns: pointer to object of type T
Description: calls the private function of the same name
**************************************************************/
	T *searchTree(T &target) const;


private:
/*************************************************************
Function: printTree
Parameters: BSTNode<T> pointer
Returns: void
Description: uses post-order traversal to print each node in the tree
**************************************************************/
	void printTree(BSTNode<T> *pTree) const;
/*************************************************************
Function: searchTree
Parameters: reference to object of type T, BSTNode<T> pointer
Returns: pointer to object of type T
Description: uses recursion to traverse the tree in search of the target.
			 returns nullptr if not found, and returns a pointer to the data
			 that matched the target if found.
**************************************************************/
	T *searchTree(T &target, BSTNode<T> *pTree) const;
/*************************************************************
Function: insertNode
Parameters: reference to an object of type T, BSTNode<T> pointer
Returns: bool
Description: inserts a  new BSTNode containing data of type T into the 
			 BST using recursion
**************************************************************/
	bool insertNode(T &newData, BSTNode<T> *pTree);
/*************************************************************
Function: destroyTree
Parameters: BSTNode<T> pointer
Returns: void
Description: a helper function for the destruction of a BST<T> object.
			 uses post-order traversal to delete the tree from the bottom
			 up.
**************************************************************/
	void destroyTree(BSTNode<T> *pTree);

	BSTNode<T> *mpRoot;
};


//function definitions
template<class T>
BST<T>::BST()
{
	mpRoot = nullptr;	
}

template<class T>
BST<T>::~BST()
{
	destroyTree(mpRoot);
}

template<class T>
BSTNode<T> *BST<T>::getRootPtr() { return mpRoot; }

template<class T>
void BST<T>::setRootPtr(BSTNode<T> *newRootPtr)
{
	mpRoot = newRootPtr;
}

template<class T>
bool BST<T>::insertNode(T & newData)
{
	return insertNode(newData, mpRoot);
}

template<class T>
void BST<T>::printTree() const
{
	printTree(mpRoot); // calls the private function to hide pointer implementation
}

template<class T>
T *BST<T>::searchTree(T &target) const
{
	return searchTree(target, mpRoot); //calls the private function to hide pointer implementation
}

template<class T>
void BST<T>::printTree(BSTNode<T> * pTree) const
{
	if (pTree != nullptr)
	{
		printTree(pTree->getLeftPtr());
		printTree(pTree->getRightPtr());
		std::cout << *pTree->getData(); // post-order traversal
	}
}

template<class T>
T *BST<T>::searchTree(T &target, BSTNode<T>* pTree) const
{
	T *tempPtr = nullptr;
	if (pTree != nullptr)
	{
		if (target < *pTree->getData()) // traverse left
		{
			tempPtr = searchTree(target, pTree->getLeftPtr()); // store result of recursive calls
		}
		else if (target > *pTree->getData()) // traverse right
		{
			tempPtr = searchTree(target, pTree->getRightPtr()); // store result of recursive calls
		}
		else if (target == *pTree->getData())
		{
			tempPtr = pTree->getData(); // set tempPtr to pointer to data in pTree
		}
	}
	return tempPtr; // returns nullptr if not found
}

template<class T>
bool BST<T>::insertNode(T & newData, BSTNode<T> *pTree) 
{
	bool success = false;
	if (pTree == nullptr) // if pTree is nullptr, then it should be inserted there
	{
		mpRoot = new BSTNode<T>(newData); // the only case when pTree is nullptr is when mpRoot is nullptr, so make a new node at mpRoot

		if (pTree != nullptr) // check for successful allocation of memory
		{
			success = true;
		}
	}
	else if (newData < *pTree->getData())
	{
		if (pTree->getLeftPtr() == nullptr)
		{
			pTree->setLeftPtr(new BSTNode<T>(newData));

			if (pTree->getLeftPtr() != nullptr) // check for sucessful allocation of memory
			{
				success = true;
			}
		}
		else
		{
			success = insertNode(newData, pTree->getLeftPtr()); // if there is a node to the left, traverse left
		}
	}
	else if (newData > *pTree->getData()) // newData is larger than pTree
	{
		if (pTree->getRightPtr() == nullptr) // if no node to the right, put the node there
		{
			pTree->setRightPtr(new BSTNode<T>(newData));
			
			if (pTree->getRightPtr() != nullptr) // check for successful allocation of memory
			{
				success = true;
			}
		}
		else
		{
			success = insertNode(newData, pTree->getRightPtr()); // if there is a node to the right, traverse right
		}
	}
	
	return success;
}
 
template<class T>
void BST<T>::destroyTree(BSTNode<T> *pTree)
{
	if (pTree->getLeftPtr() != nullptr)
	{
		destroyTree(pTree->getLeftPtr());
	}
	if (pTree->getRightPtr() != nullptr)
	{
		destroyTree(pTree->getRightPtr());
	}
	delete pTree; // post-order traversal
}
