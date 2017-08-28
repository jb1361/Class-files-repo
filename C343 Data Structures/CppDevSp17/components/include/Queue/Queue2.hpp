#pragma once

/*
	Realization of Queue using List
	Author: Dr. Holly
*/

#include "List\List1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Queue2
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Queue2 ();
		//! replaces self
		//! ensures: self = <>
	~Queue2 ();
	void clear (void);
		//! clears self
	void transferFrom (Queue2& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Queue2& operator = (Queue2& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Queue2 Specific Operations
	void enqueue (T& x);
		//! updates self
		//! clears x
		//! ensures: self = #self * <#x>
	void dequeue (T& x);
		//! updates self
		//! replaces x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and  
		//!          self = #self[1,|#self|)
	void replaceFront (T& x);
		//! updates self, x
		//! requires: self /= <>
		//! ensures: x is prefix of #self and
		//!          self = <#x> * #self[1,|#self|)
	T& front(void);
		//! restores self
		//! requires: self /= <>
		//! ensures: <front> is prefix of self
	Integer length (void);
		//! restores self
		//! ensures: length = |self|

	friend wostream& operator<< <T> (wostream& os, Queue2<T>& q);
		//! updates os
		//! restores q

private:// Representation

	typedef List1 <T> ListOfT;

	ListOfT s;

private: // Disallowed Queue2 Operations
	Queue2(Queue2& actual);
	Queue2* operator &(void) {return this;};
	const Queue2* operator &(void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

// leave Queue's copy constructor unimplemented.
// client cannot call it because it is a private member.
template <class T>
Queue2<T>::Queue2(Queue2& actual)
{
}	// Queue2

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Queue2<T>::Queue2()
{
}	// Queue2

//-----------------------------------------------------------------------

template <class T>
Queue2<T>::~Queue2()
{
}	// ~Queue2

//-----------------------------------------------------------------------

template <class T>
void Queue2<T>::clear(void)
{
	s.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Queue2<T>::transferFrom (Queue2& source)
{
	s.transferFrom(source.s);
}

//-----------------------------------------------------------------------

template <class T>
Queue2<T>& Queue2<T>::operator = (Queue2& rhs)
{
	s = rhs.s;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Queue2<T>::enqueue (T& x)
{
	s.moveToFinish();
	s.addRightFront(x);
}	// enqueue

//-----------------------------------------------------------------------

template <class T>
void Queue2<T>::dequeue (T& x)
{
	s.moveToStart();
	s.removeRightFront(x);
}	// dequeue

//-----------------------------------------------------------------------

template <class T>
void Queue2<T>::replaceFront(T& x)
{
	s.moveToStart();
	s.replaceRightFront(x);
}	// replaceFront

//-----------------------------------------------------------------------

template <class T>
T& Queue2<T>::front(void)
{
	s.moveToStart();
	return s.rightFront();
}  // front

//-----------------------------------------------------------------------

template <class T>
Integer Queue2<T>::length (void)
{
	return s.leftLength() + s.rightLength();
}	// size

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, Queue2<T>& q)
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
}