#pragma once

//
// Realization of Set layered on ChainPosition
// author: Dr. Holly
//

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, class TCallback>
class Set1
		//! Set is modeled by FiniteSet of T
		//! exemplar self
{
public: // Standard Operations
	Set1 ();
		//! replaces self
		//! ensures: self = { }
	~Set1 ();
	void clear (void);
		//! clears self
	void transferFrom (Set1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Set1& operator = (Set1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Set1 Specific Operations
	void add (T& x);
		//! updates self
		//! clears x
		//! requires: x is not in self
		//! ensures: self = #self union {#x}
	void remove (T& xFromClient, T& xFromSet);
		//! updates self
		//! restores xFromClient
		//! replaces xFromSet
		//! requires: xFromClient is in self
		//! ensures: self = #self \ {xFromSet}  and  xFromSet = xFromClient
	void removeAny (T& x);
		//! updates self
		//! replaces x
		//! requires: |self| > 0
		//! ensures: self = #self \ {x}
	Boolean contains (T& x);
		//! restores self, x
		//! ensures: contains = (x is in self)
	Integer size (void);
		//! restores self
		//! ensures: size = |self|

	friend wostream& operator<< <T, TCallback>(wostream& os, Set1& s);
		//! updates os
		//! restores s

private: // Representation
	typedef ChainPosition1 <T> ChainPositionOfT;

	ChainPositionOfT chain;
	Integer sizeOfSet;

private: // Local Operations
	void createNewRep(void);

private: // Disallowed Set1 Operations
	Set1 (const Set1& s);
	Set1* operator & (void) {return this;};
	const Set1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::createNewRep(void)
{
	ChainPositionOfT smartPosition;
	T x;

	smartPosition.labelNew (x);
	chain.transferFrom(smartPosition);
}   // createNewRep

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------


// convention: chain == smartPosition

template <class T, class TCallback>
Set1<T, TCallback>::Set1 ()
{
	createNewRep();
}	// Set1

//-----------------------------------------------------------------------

template <class T, class TCallback>
Set1<T, TCallback>::~Set1 ()
{
}	// ~Set1

//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::clear(void)
{
	chain.clear();
	sizeOfSet = 0;
	createNewRep();
}	// clear

//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::transferFrom(Set1& source)
{
	chain.transferFrom(source.chain);
	sizeOfSet.transferFrom(source.sizeOfSet);

	source.createNewRep();
} // transferFrom

//-----------------------------------------------------------------------

template <class T, class TCallback>
Set1<T, TCallback>& Set1<T, TCallback>::operator = (Set1& rhs)
{
	ChainPositionOfT newPos, oldPos, current;
	T x;

	chain.labelNew (x);
	current = chain;

	oldPos = rhs.chain;
	oldPos.applyTarget ();
	while (!oldPos.isZero ()) {
		x = oldPos.label();
		newPos.labelNew (x);
		current.swapWithTarget (newPos);
		current.applyTarget ();
		oldPos.applyTarget ();
	} // end while
	sizeOfSet = rhs.sizeOfSet;

	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::add (T& x)
{
	ChainPositionOfT newPosition;
	ChainPositionOfT firstPosition;

	chain.swapWithTarget (firstPosition);

	newPosition.labelNew (x);
	newPosition.swapWithTarget (firstPosition);
	chain.swapWithTarget (newPosition);

	sizeOfSet++;
}	// add

//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::remove (T& xFromClient, T& xFromSet)
{
	ChainPositionOfT trailingPosition;
	ChainPositionOfT currentPosition;

	trailingPosition = chain;
	currentPosition = trailingPosition;
	currentPosition.applyTarget ();

	while (!TCallback::areEqual (xFromClient, currentPosition.label())) {
		trailingPosition = currentPosition;
		currentPosition.applyTarget ();
	}  // end while
	currentPosition.replaceLabel (xFromSet);

	currentPosition.applyTarget ();
	trailingPosition.swapWithTarget (currentPosition);

	sizeOfSet--;
}	// remove

//-----------------------------------------------------------------------

template <class T, class TCallback>
void Set1<T, TCallback>::removeAny (T& x)
{
	ChainPositionOfT position;

	position = chain;
	position.applyTarget ();

	position.replaceLabel(x);
	position.applyTarget ();
	chain.swapWithTarget (position);

	sizeOfSet--;
}	// removeAny

//-----------------------------------------------------------------------

template <class T, class TCallback>
Boolean Set1<T, TCallback>::contains (T& x)
{
	ChainPositionOfT position;

	position = chain;
	position.applyTarget ();

	while (!position.isZero () && !TCallback::areEqual (x, position.label())) {
		position.applyTarget ();
	}	// end while

	return !position.isZero ();
}	// contains

//-----------------------------------------------------------------------

template <class T, class TCallback>
Integer Set1<T, TCallback>::size (void)
{
	return sizeOfSet;
}	// size

//-----------------------------------------------------------------------

template <class T, class TCallback>
wostream& operator<<(wostream& os, Set1<T, TCallback>& s)
{
	Set1<T, TCallback> temp;

	os << L"{";
	for (int k = 0, z = s.size(), lastItem = z - 1; k < z; k++) {
		T x;

		s.removeAny(x);
		os << x;
		temp.add(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L"}";

	s.transferFrom(temp);
	return os;
} // operator<<