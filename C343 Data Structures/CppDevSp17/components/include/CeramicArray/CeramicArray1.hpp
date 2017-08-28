#pragma once

//
// ceramicArray template
// author: Dr. Holly
//

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T>
class CeramicArray1
		//! is modeled by tuple of
		//!   contents: function from integer to T
		//!   lowerBound: integer
		//!   upperBound: integer
		//! constraint: for all i: integer
		//!    ((i < self.lowerBound) or (i > self.upperBound) 
		//!    implies (self.contents(i) = T.init))
		//! exemplar self
{
public: // Standard Operations
	CeramicArray1 ();
		//! replaces self
		//! ensures: self.lowerBound = 0  and  self.upperBound = 0  and
		//!          self.contents(0) = T.init
	~CeramicArray1 ();
	void clear (void);
		//! clears self
	void transferFrom (CeramicArray1& source);
		//! replaces self
		//! clears source
		//! ensures self = #source  and  
		//!       source.lowerBound = 0  and  source.upperBound = 0  and
		//!       source.contents(0) is initialized
	CeramicArray1& operator = (CeramicArray1& rhs);
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs

	// CeramicArray1 Specific Operations
	void setBounds (Integer lower, Integer upper);
		//! updates self
		//! restores lower, upper
		//! requires: lower <= upper
		//! ensures: self.lowerBound = lower  and  self.upperBound = upper  and
		//!          for all i: integer
		//!                ((i < self.lowerBound) or (i > self.upperBound) 
		//!                implies (self.contents(i) = T.init))
	void getBounds (Integer& lower, Integer& upper);
		//! restores self
		//! replaces lower, upper
		//! ensures: lower = self.lowerBound  and  upper = self.upperBound
	T& operator [] (Integer index);
		//! restores self, index
		//! requires: index >= self.lowerBound  and  index <= self.upperBound
		//! ensures: operator [] = self.contents(index)

	friend wostream& operator<< <T>(wostream& os, CeramicArray1& a);
		//! updates os
		//! restores a

private: // Representation
	Integer lowerBound;
	Integer upperBound;
	T* items;

private: // Local Operations
	T* createNewRep(int lb, int ub);
	void reclaimRep(T* rep);

private: // Disallowed CeramicArray1 Operations
	CeramicArray1 (const CeramicArray1& s);
	CeramicArray1* operator & (void) {return this;};
	const CeramicArray1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------


template <class T>
T* CeramicArray1<T>::createNewRep(int lb, int ub)
{
	return new T[ub - lb + 1];
}

//-----------------------------------------------------------------------

template <class T>
void CeramicArray1<T>::reclaimRep(T* rep)
{
	delete [] rep;
}

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T>
CeramicArray1<T>::CeramicArray1 ()
{
	items = createNewRep(lowerBound, upperBound);
}  // CeramicArray1 ()

//-----------------------------------------------------------------------

template <class T>
CeramicArray1<T>::~CeramicArray1 ()
{
	reclaimRep(items);
}  // ~CeramicArray1 ()

//-----------------------------------------------------------------------

template <class T>
void CeramicArray1<T>::clear(void)
{
	reclaimRep(items);
	lowerBound.clear();
	upperBound.clear();
	items = createNewRep(lowerBound, upperBound);
}  // clear

//-----------------------------------------------------------------------

template <class T>
void CeramicArray1<T>::transferFrom(CeramicArray1& source)
{
	reclaimRep(items);
	items = source.items;
	lowerBound.transferFrom(source.lowerBound);
	upperBound.transferFrom(source.upperBound);
	source.items = createNewRep(source.lowerBound, source.upperBound);
} // transferFrom

//-----------------------------------------------------------------------

template <class T>
CeramicArray1<T>& CeramicArray1<T>::operator = (CeramicArray1& rhs)
{
	reclaimRep(items);
	items = createNewRep(rhs.lowerBound, rhs.upperBound);
	lowerBound = rhs.lowerBound;
	upperBound = rhs.upperBound;

	for (int index = 0, size = rhs.upperBound - rhs.lowerBound + 1; index < size; index++) {
		items[index] = rhs.items[index];
	} // end for
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T>
void CeramicArray1<T>::setBounds (Integer lower, Integer upper)
{
	self.lowerBound = lower;
	self.upperBound = upper;
	reclaimRep(items);
	items = createNewRep(lower, upper);
}  // setBounds

//-----------------------------------------------------------------------

template <class T>
void CeramicArray1<T>::getBounds (Integer& lower, Integer& upper)
{
	lower = self.lowerBound;
	upper = self.upperBound;
}  // getBounds

//-----------------------------------------------------------------------

template <class T>
T& CeramicArray1<T>::operator [] (Integer index)
{
	return items[index - lowerBound];
}  // operator []

//-----------------------------------------------------------------------

template <class T>
wostream& operator<<(wostream& os, CeramicArray1<T>& a)
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