#pragma once

//
// Realization of Sequence Template layered on ChainPosition
// author: Dr. Holly
//

#include "ChainPosition\ChainPosition.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class Sequence1
		//! is modeled by string of T
		//! exemplar self
{
public: // Standard Operations
	Sequence1 ();
		//! replaces self
		//! ensures: self = <>
	~Sequence1 ();
	void clear (void);
		//! clears self
	void transferFrom (Sequence1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	Sequence1& operator = (Sequence1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// Sequence1 Specific Operations
	void add (Integer pos, T& x);
		//! updates self
		//! restores pos
		//! clears x
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
	void remove (Integer pos, T& x);
		//! updates self
		//! restores pos
		//! replaces x
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1) and
		//!          self = #self[0, pos) * #self[pos+1, |#self|)
	void replaceEntry (Integer pos, T& x);
		//! updates self, x
		//! restores pos
		//! requires: 0 <= pos < |self|
		//! ensures: <x> = #self[pos, pos+1)  and
		//!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
	T& entry (Integer pos);
		//! restores self, pos
		//! requires: 0 <= pos < |self|
		//! ensures: <entry> = self[pos, pos+1)
	void append (Sequence1& sToAppend);
		//! updates self
		//! clears sToAppend
		//! ensures: self = #self * sToAppend
	void split (Integer pos, Sequence1& receivingS);
		//! updates self
		//! restores pos
		//! replaces receivingS
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
	Integer length (void);
		//! restores self
		//! ensures: length = |self|

	friend wostream& operator<< <T>(wostream& os, Sequence1& s);
		//! updates os
		//! restores q

private: // Representation

	typedef ChainPosition1 <T> ChainPositionOfT;

	ChainPositionOfT preFront;
	Integer lengthOfSeq;

private: // Local Operations
	void moveToPosition (ChainPositionOfT& chainPos, Integer pos);

private: // Disallowed Sequence1 Operations
	Sequence1 (const Sequence1& s);
	Sequence1* operator & (void) {return this;};
	const Sequence1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::moveToPosition (ChainPositionOfT& chainPos, Integer pos)
{
	chainPos = preFront;
	for (int k = 0; k < pos; k++) {
		chainPos.applyTarget ();
	}	// end for
}	// moveToPosition

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
Sequence1<T>::Sequence1 ()
{
	T temp;

	preFront.labelNew (temp);
}	// Sequence1

//-----------------------------------------------------------------------

template <class T>
Sequence1<T>::~Sequence1 ()
{
}	// ~Sequence1

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::clear(void)
{
	T temp;

	preFront.labelNew(temp);
	lengthOfSeq = 0;
}	// clear

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::transferFrom(Sequence1& source)
{
	preFront.transferFrom(source.preFront);
	lengthOfSeq.transferFrom(source.lengthOfSeq);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
Sequence1<T>& Sequence1<T>::operator = (Sequence1& rhs)
{
	ChainPositionOfT newPos, oldPos, current;
	T x;

	preFront.labelNew (x);
	current = preFront;

	oldPos = rhs.preFront;
	oldPos.applyTarget ();
	while (!oldPos.isZero ()) {
		x = oldPos.label();
		newPos.labelNew (x);
		current.swapWithTarget (newPos);
		current.applyTarget ();
		oldPos.applyTarget ();
	} // end while
	lengthOfSeq = rhs.lengthOfSeq;

	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::add (Integer pos, T& x)
{
	ChainPositionOfT addPos;
	ChainPositionOfT newPos, temp;

	moveToPosition (addPos, pos);
	newPos.labelNew (x);
	temp = newPos;
	addPos.swapWithTarget (temp);
	newPos.swapWithTarget (temp);
	lengthOfSeq++;
}	// add

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::remove (Integer pos, T& x)
{
	ChainPositionOfT removePos, temp;

	moveToPosition (removePos, pos);

	temp = removePos;
	temp.applyTarget ();
	temp.replaceLabel (x);
	temp.applyTarget ();
	removePos.swapWithTarget (temp);
	lengthOfSeq--;
}	// remove

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::replaceEntry (Integer pos, T& x)
{
	ChainPositionOfT swapPos;

	moveToPosition (swapPos, pos + 1);

	swapPos.replaceLabel (x);
}	// replaceEntry

//-----------------------------------------------------------------------

template <class T>
T& Sequence1<T>::entry (Integer pos)
{
	ChainPositionOfT accessPos;

	moveToPosition (accessPos, pos + 1);
	return accessPos.label();
}	// entry

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::append (Sequence1& sToAppend)
{
	ChainPositionOfT endPos, temp;

	moveToPosition (endPos, lengthOfSeq);

	sToAppend.preFront.swapWithTarget (temp);
	endPos.swapWithTarget (temp);
	lengthOfSeq += sToAppend.lengthOfSeq;
	sToAppend.lengthOfSeq = 0;
}	// append

//-----------------------------------------------------------------------

template <class T>
void Sequence1<T>::split (Integer pos, Sequence1& receivingS)
{
	ChainPositionOfT splitPos, temp;

	moveToPosition (splitPos, pos);
	splitPos.swapWithTarget (temp);
	receivingS.preFront.swapWithTarget (temp);
	receivingS.lengthOfSeq = lengthOfSeq - pos;
	lengthOfSeq = pos;
}	// split

//-----------------------------------------------------------------------

template <class T>
Integer Sequence1<T>::length (void)
{
	return lengthOfSeq;
}	// length

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, Sequence1<T>& s)
{
	os << L"<";
	for (int p = 0, z = s.length(), lastItem = z - 1; p < z; p++) {
		T x;

		os << s.entry(p);
		if (p < lastItem) {
			os << L",";
		} // end if
	} // end for
	os << L">";
	return os;
} // operator<<