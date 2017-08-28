#pragma once

//
// StaticArray template
// author: Dr. Holly
//

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
class StaticArray1
		//! StaticArray1 is modeled by function from integer to T
		//! constraint: for all i: integer
		//!    ((i < lowerBound) or (i > upperBound) 
		//!    implies (self(i) = T.init))
		//! exemplar self
{
public: // Standard Operations
	StaticArray1 ();
		//! replaces self
		//! ensures: for all i: integer
		//!          ((i >= lowerBound) and (i <= upperBound))
		//!			 implies (self(i) = T.init))
	~StaticArray1 ();
	void clear (void);
		//! clears self
	void transferFrom (StaticArray1& source);
		//! replaces self
		//! clears source
		//! ensures: self = #source
	StaticArray1& operator = (StaticArray1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// StaticArray1 Specific Operations
	void getBounds (Integer& lower, Integer& upper);
		//! restores self
		//! replaces lower, upper
		//! ensures: lower = lowerBound  and  upper = upperBound
	T& operator [] (Integer index);
		//! restores self, index
		//! requires: index >= lowerBound  and  index <= upperBound
		//! ensures: operator [] = self(index)

	friend wostream& operator<< <T, lowerBound, upperBound>(wostream& os, StaticArray1<T, lowerBound, upperBound>& a);
		//! updates os
		//! restores a

private: // Representation
	T* items;   // array of T's to be allocated

private: // Local Operations
	T* createNewRep(int lb, int ub);
	void reclaimRep(T* rep);

private: // Disallowed StaticArray1 Operations
	StaticArray1 (const StaticArray1& s);
	StaticArray1* operator & (void) {return this;};
	const StaticArray1* operator & (void) const {return this;};
};
//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
T* StaticArray1<T, lowerBound, upperBound>::createNewRep(int lb, int ub)
{
	return new T[ub - lb + 1];
} // createNewRep

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
void StaticArray1<T, lowerBound, upperBound>::reclaimRep(T* rep)
{
	delete [] rep;
} // reclaimRep

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
StaticArray1<T, lowerBound, upperBound>::StaticArray1 ()
{
	items = createNewRep(lowerBound, upperBound);
}  // StaticArray1 ()

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
StaticArray1<T, lowerBound, upperBound>::~StaticArray1 ()
{
	reclaimRep(items);
}  // ~StaticArray1 ()

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
void StaticArray1<T, lowerBound, upperBound>::clear(void)
{
	reclaimRep(items);
	items = createNewRep(lowerBound, upperBound);
}  // clear

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
void StaticArray1<T, lowerBound, upperBound>::transferFrom(StaticArray1& source)
{
	reclaimRep(items);
	items = source.items;
	source.items = createNewRep(lowerBound, upperBound);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
StaticArray1<T, lowerBound, upperBound>& StaticArray1<T, lowerBound, upperBound>::operator = (StaticArray1& rhs)
{
	Integer index, size;

	size = upperBound - lowerBound + 1;
	for (index = 0; index < size; index++) {
		items[index] = rhs.items[index];
	} // end for
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
void StaticArray1<T, lowerBound, upperBound>::getBounds (Integer& lower, Integer& upper)
{
	lower = lowerBound;
	upper = upperBound;
}  // getBounds

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
T& StaticArray1<T, lowerBound, upperBound>::operator [] (Integer index)
{
	return items[index - lowerBound];
}  // operator []

//-----------------------------------------------------------------------

template <class T, int lowerBound, int upperBound>
wostream& operator<<(wostream& os, StaticArray1<T, lowerBound, upperBound>& a)
{
	Integer lb, ub;

	a.getBounds (lb, ub);
	os << L"[";
	for (int k = lb; k <= ub; k++) {
		os << a[k];
		if (k < ub) {
			os << L",";
		} // endif
	}	// end for
	os << L"]";

	return os;
} // operator<<
