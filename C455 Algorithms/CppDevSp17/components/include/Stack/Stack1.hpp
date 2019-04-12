#pragma once

/*
	Realization of Stack using ChainPosition
	Author: Dr. Holly
*/

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Stack1
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Stack1 ();
		//! replaces self
		//! ensures: self = <>
	~Stack1 ();
	void clear (void);
		//! clears self
	void transferFrom (Stack1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Stack1& operator = (Stack1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Stack1 Specific Operations
	void push (T& x);
		//! updates self
		//! clears x
		//! ensures: self = <#x> + self
	void pop (T& x);
		//! updates self
		//! replaces x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and
		//!          self = #self[1, |#self|)
	void replaceTop (T& x);
		//! updates self, x
		//! requires: self /= <>
		//! ensures: <x> is prefix of #self  and
		//!          self = <#x> * #self[1, |#self|)
	T& top (void);
		//! restores self
		//! requires: self /= <>
		//! ensures: <top> is prefix of self
	Integer length (void);
		//! restores self
		//! ensures: length = |self|
	
	friend wostream& operator<< <T>(wostream& os, Stack1& s);
		//! updates os
		//! restores s

private: // Representation
	typedef ChainPosition1 <T> ChainPositionOfT;
	
	ChainPositionOfT topOfStack;
	Integer lengthOfStack;

private: // Disallowed Stack1 Operations
	Stack1 (const Stack1& s);
	Stack1* operator & (void) {return this;};
	const Stack1* operator & (void) const {return this;};
};
//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Stack1<T>::Stack1 ()
{
}	// Stack1

//-----------------------------------------------------------------------

template <class T>
Stack1<T>::~Stack1 ()
{
}	// ~Stack1

//-----------------------------------------------------------------------

template <class T>
void Stack1<T>::clear(void)
{
	topOfStack.clear();
	lengthOfStack = 0;
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Stack1<T>::transferFrom(Stack1& source)
{
	topOfStack.transferFrom(source.topOfStack);
	lengthOfStack.transferFrom(source.lengthOfStack);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Stack1<T>& Stack1<T>::operator = (Stack1& rhs)
{
	ChainPositionOfT newPos, oldPos, current;
	T x;

	oldPos = rhs.topOfStack;
	if (!oldPos.isZero()){
		// if rhs is not empty, set up first position in lhs
		x = oldPos.label();
		oldPos.applyTarget();
		current.labelNew(x);
		topOfStack = current;
	} else {
		// rhs is empty, clear out lhs
		topOfStack.clear ();
	} // end if

	while (!oldPos.isZero ()) {
		x = oldPos.label();
		newPos.labelNew (x);
		current.swapWithTarget (newPos);
		current.applyTarget();
		oldPos.applyTarget ();
	} // end while
	lengthOfStack = rhs.lengthOfStack;

	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Stack1<T>::push (T& x)
{
	ChainPositionOfT newPos;

	newPos.labelNew (x);
	newPos.swapWithTarget (topOfStack);
	topOfStack.transferFrom(newPos);
	lengthOfStack++;
}	// push

//-----------------------------------------------------------------------

template <class T>
void Stack1<T>::pop (T& x)
{
	ChainPositionOfT oldPos;

	oldPos = topOfStack;
	topOfStack.applyTarget();
	oldPos.replaceLabel(x);
	lengthOfStack--;
}	// pop

//-----------------------------------------------------------------------

template <class T>
void Stack1<T>::replaceTop (T& x)
{
	topOfStack.replaceLabel(x);
}	// replaceTop

//-----------------------------------------------------------------------

template <class T>
T& Stack1<T>::top ()
{
   return topOfStack.label();
}  // top

//-----------------------------------------------------------------------

template <class T>
Integer Stack1<T>::length (void)
{
	return lengthOfStack;
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, Stack1<T>& s)
{
	Stack1<T> temp;

	os << L"<";
	for (int k = 0, z = s.length(), lastItem = z - 1; k < z; k++) {
		T x;

		os << s.top();
		s.pop(x);
		temp.push(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";

	for (int k = 0, z = temp.length(); k < z; k++) {
		T x;

		temp.pop(x);
		s.push(x);
	} // end for
	return os;
} // operator<<

