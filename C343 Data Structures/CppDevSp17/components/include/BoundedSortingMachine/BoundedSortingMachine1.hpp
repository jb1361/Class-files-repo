#pragma once
//
// Exchange Sort Realization of BoundedSortingMachine using Array
// author: Dr. Holly
//

#include "CeramicArray\CeramicArray1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, class TCallBack>
class BoundedSortingMachine1
		//! is modeled by tuple of
		//!   maxSize: integer
		//!   contents: FiniteMultiSet(T)
		//!   inserting: boolean
		//! exemplar self

		//! math operation IS_FIRST (
		//!          s: FiniteMultiSet(T),
		//!          x: T
		//!      ): boolean
		//!      definition
		//!          x is in s  and
		//!          for all y: Item where (y is in s)
		//!             (areOrdered (x, y))

		//! TCallBack required to have an areOrdered operation:
		//! 
		//! Boolean areOrdered (T& lhs, T& rhs)
		//! restores lhs, rhs
		//!   areOrdered returns true iff the two items compared
		//!      are in order relative to each other.
		//!   lhs stands for left hand side
		//!   rhs stands for right hand side

{
public: // Standard Operations
	BoundedSortingMachine1 ();
   		//! replaces self
   		//! ensures: self.contents = { }  and  self.inserting = true  and  self.maxSize = 0
	~BoundedSortingMachine1 ();
	void clear (void);
		//! clears self
	void transferFrom (BoundedSortingMachine1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	BoundedSortingMachine1& operator = (BoundedSortingMachine1& rhs);
   		//! replaces self
   		//! restores rhs
   		//! ensures: self = rhs

	// BoundedSortingMachine1 Specific Operations
	void setMaxSize (Integer maxSize);
		//! updates self
		//! restores maxSize
		//! requires: 0 < maxSize
		//! ensures: self.maxSize = maxSize
	Integer maxSize (void);
		//! restores self
		//! ensures: maxSize = self.maxSize
	void add (T& x);
   		//! updates self
   		//! clears x
   		//! requires: self.inserting  and  |self.contents| < self.maxSize
   		//! ensures: self.contents = #self.contents  union  {#x}  and
   		//!          self.inserting = true
	void changeToExtractionMode (void);
   		//! updates self
   		//! requires:  self.inserting
   		//! ensures: self.inserting = false  and  self.contents = #self.contents
	void removeFirst (T& x);
   		//! updates self
   		//! replaces x
   		//! requires: not self.inserting  and  self.contents /= {}
   		//! ensures: IS_FIRST (#self.contents, x)  and
   		//!          self.contents = #self.contents / {x}  and
   		//!          self.inserting = false
	Integer size (void);
   		//! restores  self
   		//! ensures: size = |self.contents|
	Boolean isInInsertionMode (void);
   		//! restores  self
   		//! ensures:    isInInsertionMode = self.inserting
	Integer remainingCapacity (void);
	    //! restores self
	    //! ensures: remainingCapacity  = maxSize - |self.contents|

	friend wostream& operator<< <T, TCallBack>(wostream& os, BoundedSortingMachine1& s);
	    //! updates os
	    //! restores s

private: // Representation
	typedef CeramicArray1 <T> ArrayOfT;

	Boolean insertionMode;
	ArrayOfT itemKeeper;
	Integer nextAddLocation;
	Integer maxContentsSize;

private: // Local Operations
	void exchangeSort (ArrayOfT& s, Integer size);

private: // Disallowed BoundedSortingMachine1 Operations
	BoundedSortingMachine1 (const BoundedSortingMachine1& s);
	BoundedSortingMachine1* operator & (void) {return this;};
	const BoundedSortingMachine1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------



//----------------------------------------------------------------
// Local Operations
//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::exchangeSort (ArrayOfT& a, Integer size)
{
	for (int j = 0; j < size; j++) {
		for (int k = 0, z = (size - 1); k < z; k++) {
			if (TCallBack::areOrdered(a[k], a[k+1])) {
				T temp;
				temp.transferFrom(a[k]);
				a[k].transferFrom(a[k+1]);
				a[k+1].transferFrom(temp);
			} // end if
		}	// end for
	} // end for
}	// exchangeSort

//----------------------------------------------------------------
// Exported Operations
//----------------------------------------------------------------

template <class T, class TCallBack>
BoundedSortingMachine1<T, TCallBack>::BoundedSortingMachine1 ()
{
	insertionMode = true;
}	// BoundedSortingMachine1

//----------------------------------------------------------------

template <class T, class TCallBack>
BoundedSortingMachine1<T, TCallBack>::~BoundedSortingMachine1 ()
{
}	// ~BoundedSortingMachine1

//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::clear(void)
{
	itemKeeper.clear();
	insertionMode = true;
	nextAddLocation.clear();
	maxContentsSize.clear();
}	// clear

//-----------------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::transferFrom(BoundedSortingMachine1& source)
{
	insertionMode.transferFrom(source.insertionMode);
	source.insertionMode = true;
	itemKeeper.transferFrom(source.itemKeeper);
	nextAddLocation.transferFrom(source.nextAddLocation);
	maxContentsSize.transferFrom(source.maxContentsSize);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, class TCallBack>
BoundedSortingMachine1<T, TCallBack>& 
BoundedSortingMachine1<T, TCallBack>::operator = (BoundedSortingMachine1& rhs)
{
	insertionMode = rhs.insertionMode;
	itemKeeper = rhs.itemKeeper;
	nextAddLocation = rhs.nextAddLocation;
	maxContentsSize = rhs.maxContentsSize;
	return *this;
} // operator =

//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::setMaxSize(Integer maxSize)
{
	maxContentsSize = maxSize;
	itemKeeper.setBounds(0, (maxSize - 1));
}	// setMaxSize

	//----------------------------------------------------------------

template <class T, class TCallBack>
Integer BoundedSortingMachine1<T, TCallBack>::maxSize(void)
{
	return maxContentsSize;
}	// maxSize

//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::add (T& x)
{
	itemKeeper[nextAddLocation].transferFrom(x);
	nextAddLocation++;
}	// add

//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::changeToExtractionMode (void)
{
	exchangeSort(itemKeeper, nextAddLocation);
	insertionMode = false;
}	// changeToExtractionMode

//----------------------------------------------------------------

template <class T, class TCallBack>
void BoundedSortingMachine1<T, TCallBack>::removeFirst (T& x)
{
	nextAddLocation--;
	x.transferFrom(itemKeeper[nextAddLocation]);
}	// removeFirst

//----------------------------------------------------------------

template <class T, class TCallBack>
Integer BoundedSortingMachine1<T, TCallBack>::size (void)
{
	return nextAddLocation; 
}	// size

//----------------------------------------------------------------

template <class T, class TCallBack>
Boolean BoundedSortingMachine1<T, TCallBack>::isInInsertionMode (void)
{
   return insertionMode;
}	// isInInsertionMode

	//----------------------------------------------------------------

template <class T, class TCallBack>
Integer BoundedSortingMachine1<T, TCallBack>::remainingCapacity(void)
{
	return maxContentsSize - nextAddLocation;
}	// remainingCapacity

//-----------------------------------------------------------------------

template <class T, class TCallBack>
wostream& operator<<(wostream& os, BoundedSortingMachine1<T, TCallBack>& sm)
{
	Boolean inInsertionPhase = sm.isInInsertionMode();
	Integer maxSize = sm.maxSize();
	BoundedSortingMachine1<T, TCallBack> temp;

	temp.setMaxSize(maxSize);
	if (inInsertionPhase) {
		sm.changeToExtractionMode();
	}   // end if
	os << L"(" << maxSize << L",{";
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
	return os;
} // operator<<