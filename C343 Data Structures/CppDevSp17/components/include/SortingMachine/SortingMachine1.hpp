#pragma once
//
// Exchange Sort Realization of SortingMachine using List
// author: Dr. Holly
//

#include "List\List1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, class TCallback>
class SortingMachine1
		//! SortingMachine1 is modeled by (
		//!      contents: FiniteMultiSet(T)
		//!      inserting: boolean
		//!   )
		//! exemplar self

		//! math operation IS_FIRST (
		//!          s: FiniteMultiSet(T),
		//!          x: T
		//!      ): boolean
		//!      definition
		//!          x is in s  and
		//!          for all y: Item where (y is in s)
		//!             (areOrdered (x, y))

		//! TCallback required to have an areOrdered operation:
		//! 
		//! Boolean areOrdered (T& lhs, T& rhs)
		//! restores lhs, rhs
		//!   areOrdered returns true iff the two items compared
		//!      are in order relative to each other.
		//!   lhs stands for left hand side
		//!   rhs stands for right hand side

{
public: // Standard Operations
	SortingMachine1 ();
   		//! replaces self
   		//! ensures: ({},true)
	~SortingMachine1 ();
	void clear (void);
		//! clears self
	void transferFrom (SortingMachine1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	SortingMachine1& operator = (SortingMachine1& rhs);
   		//! updates self
   		//! restores rhs
   		//! ensures: self = rhs

	// SortingMachine1 Specific Operations
	void add (T& x);
   		//! updates self.contents
   		//! clears x
   		//! requires: self.inserting
   		//! ensures: self.contents = #self.contents  union  {#x}  and
   		//!          self.inserting = true
	void changeToExtractionMode (void);
   		//! updates self.inserting
   		//! requires: self.inserting
   		//! ensures: self.inserting = false  and  self.contents = #self.contents
	void removeFirst (T& x);
   		//! updates self.contents
   		//! replaces x
   		//! requires: not self.inserting  and  |self.contents| > 0
   		//! ensures: IS_FIRST (#self.contents, x)  and
   		//!          self.contents = #self.contents \ {x}  and
   		//!          self.inserting = false
	Integer size (void);
   		//! restores self
   		//! ensures: size = |self.contents|
	Boolean isInInsertionMode (void);
   		//! restores self
   		//! ensures: isInInsertionMode = self.inserting

	friend wostream& operator<< <T, TCallback>(wostream& os, SortingMachine1& s);
		//! updates os
		//! restores s

private: // Representation
	typedef List1 <T> ListOfT;

	Boolean insertionMode;
	ListOfT itemKeeper;

private: // Local Operations
	void exchangeSort (ListOfT& s);

private: // Disallowed SortingMachine1 Operations
	SortingMachine1 (const SortingMachine1& s);
	SortingMachine1* operator & (void) {return this;};
	const SortingMachine1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

// convention
// itemKeeper.left = <>
//

//----------------------------------------------------------------
// Local Operations
//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::exchangeSort (ListOfT& s)
{
	for (int k = 0, z = s.rightLength(); k < z; k++) {
		T x;
		s.removeRightFront(x);
		for (int k = 0; k < (z - 1); k++) {
			T y;
			s.removeRightFront(y);
			if (TCallback::areOrdered(x, y)) {
				s.addRightFront(x);
				x.transferFrom(y);
			}
			else {
				s.addRightFront(y);
			} // end if
			s.advance();
		}	// end for
		s.addRightFront(x);
		s.moveToStart();
	} // end for
}	// exchangeSort

//----------------------------------------------------------------
// Exported Operations
//----------------------------------------------------------------

template <class T, class TCallback>
SortingMachine1<T, TCallback>::SortingMachine1 ()
{
	insertionMode = true;
}	// SortingMachine1

//----------------------------------------------------------------

template <class T, class TCallback>
SortingMachine1<T, TCallback>::~SortingMachine1 ()
{
}	// ~SortingMachine1

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::clear(void)
{
	itemKeeper.clear();
	insertionMode = true;
}	// clear

//-----------------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::transferFrom(SortingMachine1& source)
{
	insertionMode.transferFrom(source.insertionMode);
	source.insertionMode = true;
	itemKeeper.transferFrom(source.itemKeeper);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, class TCallback>
SortingMachine1<T, TCallback>& 
SortingMachine1<T, TCallback>::operator = (SortingMachine1& rhs)
{
	insertionMode = rhs.insertionMode;
	itemKeeper = rhs.itemKeeper;
	return *this;
} // operator =

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::add (T& x)
{
	itemKeeper.addRightFront(x);
}	// add

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::changeToExtractionMode (void)
{
	exchangeSort(itemKeeper);
	insertionMode = false;
}	// changeToExtractionMode

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine1<T, TCallback>::removeFirst (T& x)
{
	itemKeeper.removeRightFront(x);
}	// removeFirst

//----------------------------------------------------------------

template <class T, class TCallback>
Integer SortingMachine1<T, TCallback>::size (void)
{
   return itemKeeper.rightLength();
}	// size

//----------------------------------------------------------------

template <class T, class TCallback>
Boolean SortingMachine1<T, TCallback>::isInInsertionMode (void)
{
   return insertionMode;
}	// isInInsertionMode

//-----------------------------------------------------------------------

template <class T, class TCallback>
wostream& operator<<(wostream& os, SortingMachine1<T, TCallback>& sm)
{
#ifdef NDEBUG
	Boolean inInsertionPhase;
	SortingMachine1<T, TCallback> temp;

	inInsertionPhase = sm.isInInsertionMode();
	if (inInsertionPhase) {
		sm.changeToExtractionMode();
	}   // end if
	os << L"({";
	for (int k = 0, z = sm.size(), lastItem = z - 1; k < z; k++) {
		T x;

		sm.removeFirst(x);
		os << x;
		temp.add(x);
		if (k < lastItem) {
			os << L",";
		} // end if
	}	// end for
	os << L"},";
	os << inInsertionPhase << L")";

	sm.transferFrom(temp);
	if (!inInsertionPhase) {
		sm.changeToExtractionMode();
	}   // end if
#else
	os << sm.itemKeeper;
#endif
	return os;
} // operator<<