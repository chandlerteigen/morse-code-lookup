#pragma once


template<class T>
class BSTNode
{

public:

	BSTNode();

	BSTNode(T &newData);

	~BSTNode();


	// Accessors
	T *getData();
	BSTNode *getRightPtr();
	BSTNode *getLeftPtr();

	void setLeftPtr(BSTNode *newLeftPtr);
	void setRightPtr(BSTNode *newRightPtr);

private:
	
	T *mData;
	BSTNode *mpRight;
	BSTNode * mpLeft;
};

template<class T>
BSTNode<T>::BSTNode()
{
	this->mData = nullptr;
	this->mpRight = this->mpLeft = nullptr;
}

template<class T>
BSTNode<T>::BSTNode(T &newData) // type T must have a copy assignment operator overloaded
{
	mData = new T; 
	*mData = newData;
	mpRight = nullptr;
	mpLeft = nullptr;
}

template<class T>
BSTNode<T>::~BSTNode()
{
	delete mData;
}

template<class T>
T* BSTNode<T>::getData() { return mData; }

template<class T>
BSTNode<T> *BSTNode<T>::getRightPtr() { return mpRight; }

template<class T>
BSTNode<T> *BSTNode<T>::getLeftPtr() { return mpLeft; }

template<class T>
void BSTNode<T>::setLeftPtr(BSTNode<T> *newLeftPtr)
{
	mpLeft = newLeftPtr;
}

template<class T>
void BSTNode<T>::setRightPtr(BSTNode<T> *newRightPtr)
{
	mpRight = newRightPtr;
}

