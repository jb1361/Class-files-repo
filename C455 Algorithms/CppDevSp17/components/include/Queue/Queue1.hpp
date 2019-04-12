#pragma once

/*
	Realization of Queue using ChainPosition
	Author: Dr. Holly
*/

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Queue1
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Queue1 ();
		//! replaces self
		//! ensures: self = <>
	~Queue1 ();
	void clear (void);
		//! clears self
	void transferFrom (Queue1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Queue1& operator = (Queue1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Queue1 Specific Operations
	void enqueue (T& x);
		//! updates self
		//! clears x
		//! ensures: self = #self * <#x>
	void dequeue (T& x);
		//! updates self
		//! replaces x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and  
		//!          self = #self[1, |#self|)
	void replaceFront (T& x);
		//! updates self, x
		//! requires: self /= <>
		//! ensures: x is prefix of #self and
		//!          self = <#x> * #self[1, |#self|)
	T& front(void);
		//! restores self
		//! requires: self /= <>
		//! ensures: <front> is prefix of self
	Integer length (void);
		//! restores self
		//! ensures: length = |self|

	friend wostream& operator << <T>(wostream& os, Queue1& q);
		//! updates os
		//! restores q

private: // Representation
	
	typedef ChainPosition1 <T> ChainPositionOfT;

	ChainPositionOfT preFront;
	ChainPositionOfT rear;
	Integer lengthOfQueue;

private: // Local Operations
	void createNewRep(void);

private: // Disallowed Queue1 Operations
	Queue1(const Queue1& s);
	Queue1* operator &(void) {return this;};
	const Queue1* operator &(void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::createNewRep(void)
{
	T temp;

	preFront.labelNew(temp);
	rear = preFront;
}   // createNewRep

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Queue1<T>::Queue1 ()
{
	createNewRep();
}	// queue1

//-----------------------------------------------------------------------

template <class T>
Queue1<T>::~Queue1 ()
{
}	// ~Queue1

//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::clear(void)
{
	T temp;

	preFront.labelNew(temp);
	rear = preFront;
	lengthOfQueue = 0;
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::transferFrom (Queue1& source)
{
	preFront.transferFrom(source.preFront);
	rear.transferFrom(source.rear);
	lengthOfQueue.transferFrom(source.lengthOfQueue);

	source.createNewRep();
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Queue1<T>& Queue1<T>::operator = (Queue1& rhs)
{
	T x;
	ChainPositionOfT newPos, existingPos;

	preFront.labelNew(x);
	rear = preFront;

	existingPos = rhs.preFront;
	existingPos.applyTarget();
	while (!existingPos.isZero()) {
		x = existingPos.label();
		newPos.labelNew(x);
		rear.swapWithTarget(newPos);
		rear.applyTarget();
		existingPos.applyTarget();
	} // end while
	lengthOfQueue = rhs.lengthOfQueue;

	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::enqueue (T& x)
{
	ChainPositionOfT newPos;

	newPos.labelNew(x);
	rear.swapWithTarget(newPos);
	rear.applyTarget();
	lengthOfQueue++;
}	// enqueue

//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::dequeue( T& x)
{
	preFront.applyTarget();
	preFront.replaceLabel(x);
	lengthOfQueue--;
}	// dequeue

//-----------------------------------------------------------------------

template <class T>
void Queue1<T>::replaceFront (T& x)
{
	ChainPositionOfT pos;
	pos = preFront;
	pos.applyTarget();
	pos.replaceLabel(x);
}	// replaceFront

//-----------------------------------------------------------------------

template <class T>
T& Queue1<T>::front(void)
{
	ChainPositionOfT pos;
	pos = preFront;
	pos.applyTarget();
	return pos.label();
}  // front
   
//-----------------------------------------------------------------------

template <class T>
Integer Queue1<T>::length (void)
{
	return lengthOfQueue;
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream& operator<< (wostream& os, Queue1<T>& q)
{
	os << L"<";
	for (int k = 0, z = q.length(), lastItem = z - 1; k < z; k++) {
		T x;

		q.dequeue(x);
		os << x;
		q.enqueue(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";
	return os;
} // operator<<



