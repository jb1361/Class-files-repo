#pragma once
//
// Exchange Sort Realization of SortingMachine using List
// author: Dr. Holly
//

#include "Queue\Queue1.hpp"

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, class TCallback>
class SortingMachine2
		//! SortingMachine2 is modeled by (
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
	SortingMachine2 ();
   		//! replaces self
   		//! ensures: ({},true)
	~SortingMachine2 ();
	void clear (void);
		//! clears self
	void transferFrom (SortingMachine2& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	SortingMachine2& operator = (SortingMachine2& rhs);
   		//! updates self
   		//! restores rhs
   		//! ensures: self = rhs

	// SortingMachine2 Specific Operations
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
	friend wostream& operator<< <T, TCallback>(wostream& os, SortingMachine2& s);
		//! updates os
		//! restores s

private: // Representation
	typedef Queue1 <T> QueueOfT;

	Boolean insertionMode;
	QueueOfT itemKeeper;

private: // Local Operations
	void split(QueueOfT& q, QueueOfT& q1, QueueOfT& q2);
	void merge(QueueOfT& q, QueueOfT& q1, QueueOfT& q2);
	void mergeSort(QueueOfT& q);
private: // Disallowed SortingMachine2 Operations
	SortingMachine2 (const SortingMachine2& s);
	SortingMachine2* operator & (void) {return this;};
	const SortingMachine2* operator & (void) const {return this;};
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
void SortingMachine2<T, TCallback>::split(QueueOfT& q, QueueOfT& q1, QueueOfT& q2)
//! clears q
//! replaces q1, q2
//! requires: |q| > 1
//! ensures: perms(#q, q1 * q2) and 
//!          floor(|#q|/2) <= |q1| <= ceiling(|#q|/2) and
//!          floor(|#q|/2) <= |q2| <= ceiling(|#q|/2)
{
	Integer x;
	Integer len = q.length();
	for (Integer i = 0; i < floor(len/2) ; i++)
	{
		q.dequeue(x);
		q1.enqueue(x);
	}
	len = q.length();
	for (Integer i = 0; i < len; i++)
	{
		q.dequeue(x);
		q2.enqueue(x);
	}
} // split

  //----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::merge(QueueOfT& q, QueueOfT& q1, QueueOfT& q2)
//! replaces q
//! clears q1, q2
//! ensures: sorted(q) and perms(q, #q1 * #q2)
{
	Integer x;
	while (q1.length() != 0 && q2.length() != 0) {
		Integer lhs = q1.front();
		Integer rhs = q2.front();

		if (TCallback::areOrdered(lhs,rhs) == true) {
			q1.dequeue(x);
			q.enqueue(x);
		}
		else {
			q2.dequeue(x);
			q.enqueue(x);	
		}
	}
	while (q1.length() != 0) {
		q1.dequeue(x);
		q.enqueue(x);
	}
	while (q2.length() != 0) {
		q2.dequeue(x);
		q.enqueue(x);
	}
} // merge

  //----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::mergeSort(QueueOfT& q)
//! updates q
//! ensures: sorted(q) and perms(q, #q)
//! decreasing: |q|  
{
	QueueOfT q1;
	QueueOfT q2;
	if (q.length() >  1) {
		split(q, q1, q2);
		mergeSort(q1);
		mergeSort(q2);
		merge(q, q1, q2);	
	}

} // mergeSort

//----------------------------------------------------------------
// Exported Operations
//----------------------------------------------------------------

template <class T, class TCallback>
SortingMachine2<T, TCallback>::SortingMachine2 ()
{
	insertionMode = true;
}	// SortingMachine2

//----------------------------------------------------------------

template <class T, class TCallback>
SortingMachine2<T, TCallback>::~SortingMachine2 ()
{
}	// ~SortingMachine2

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::clear(void)
{
	itemKeeper.clear();
	insertionMode = true;
}	// clear

//-----------------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::transferFrom(SortingMachine2& source)
{
	insertionMode.transferFrom(source.insertionMode);
	source.insertionMode = true;
	itemKeeper.transferFrom(source.itemKeeper);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, class TCallback>
SortingMachine2<T, TCallback>& 
SortingMachine2<T, TCallback>::operator = (SortingMachine2& rhs)
{
	insertionMode = rhs.insertionMode;
	itemKeeper = rhs.itemKeeper;
	return *this;
} // operator =

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::add (T& x)
{
	itemKeeper.enqueue(x);
}	// add

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::changeToExtractionMode (void)
{
	mergeSort(itemKeeper);
	insertionMode = false;
}	// changeToExtractionMode

//----------------------------------------------------------------

template <class T, class TCallback>
void SortingMachine2<T, TCallback>::removeFirst (T& x)
{
	itemKeeper.dequeue(x);
}	// removeFirst

//----------------------------------------------------------------

template <class T, class TCallback>
Integer SortingMachine2<T, TCallback>::size (void)
{
	return itemKeeper.length();
}	// size

//----------------------------------------------------------------

template <class T, class TCallback>
Boolean SortingMachine2<T, TCallback>::isInInsertionMode (void)
{
   return insertionMode;
}	// isInInsertionMode

//-----------------------------------------------------------------------

template <class T, class TCallback>
wostream& operator<<(wostream& os, SortingMachine2<T, TCallback>& sm)
{
#ifdef NDEBUG
	Boolean inInsertionPhase;
	SortingMachine2<T, TCallback> temp;

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