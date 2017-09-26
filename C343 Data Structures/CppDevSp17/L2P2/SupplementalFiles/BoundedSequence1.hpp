#pragma once
#pragma warning( disable : 4716 )

//
// realization of Sequence Template layered on StaticArray
// author: TODO: *** put your name here ***
//

#include "StaticArray\StaticArray1.hpp"

//-----------------------------------------------------------------------
// template Class Specification
//-----------------------------------------------------------------------

template <class T, int maxLength>
class BoundedSequence1
	//! requires 1 <= maxLength

	//! is modeled by string(T)
	//! exemplar self
	//! constraint |self| <= maxLength
{
public: // standard Operations
	BoundedSequence1();
	//! replaces self
	//! ensures: self = <>
	~BoundedSequence1();
	void clear(void);
	//! clears self
	void transferFrom(BoundedSequence1& source);
	//! replaces self
	//! clears source
	//! ensures: self = #source
	BoundedSequence1& operator = (BoundedSequence1& rhs);
	//! replaces self
	//! restores rhs
	//! ensures: self = rhs

	// BoundedSequence1 Specific Operations
	void add(Integer pos, T& x);
	//! updates self
	//! restores pos
	//! clears x
	//! requires: 0 <= pos <= |self|  and  |self| + 1 <= maxLength
	//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
	void remove(Integer pos, T& x);
	//! updates self
	//! restores pos
	//! replaces x
	//! requires: 0 <= pos < |self|
	//! ensures: self = #self[0, pos) * #self[pos+1, |#self|)  and
	//!          <x> = #self[pos, pos+1)
	void replaceEntry(Integer pos, T& x);
	//! updates self, x
	//! restores pos
	//! requires:  0 <= pos < |self|
	//! ensures: <x> = #self[pos, pos+1)  and
	//!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
	T& entry(Integer pos);
	//! restores self, pos
	//! requires:  0 <= pos < |self|
	//! ensures: <entry> = self[pos, pos+1)
	void append(BoundedSequence1& sToAppend);
	//! updates self
	//! clears sToAppend
	//! requires: |self| + |sToAppend| <= maxLength
	//! ensures:    self = #self  *  sToAppend
	void split(Integer pos, BoundedSequence1& receivingS);
	//! updates self
	//! restores pos
	//! replaces receivingS
	//! requires:  0 <= pos <= |self|
	//! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
	Integer length(void);
	//! restores self
	//! ensures: length = |self|
	Integer remainingCapacity(void);
	//! restores self
	//! ensures: remainingCapacity  = maxLength - |self|

	friend wostream& operator<< <T>(wostream& os, BoundedSequence1& s);
	//! updates os
	//! restores s

private: // representation


	// TODO enter in the internal representation and correspondence as described in the lab statement

private: // disallowed BoundedSequence1 Operations
	BoundedSequence1(const BoundedSequence1& s);
	BoundedSequence1* operator & (void) { return (this); };
	const BoundedSequence1* operator & (void) const { return (this); };
};

//-----------------------------------------------------------------------
// member Function Implementations
//-----------------------------------------------------------------------

//-----------------------------------------------------------------------
// exported Operations
//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedSequence1<T, maxLength>::BoundedSequence1()
{
	// Reread the explanation for BoundedQueue's constructor in the instructional materials

	// DONE
	// The constructors for StaticArray and Integer will automatically initialize the data members as follows:
	// contents = [T.init, T.init, ..., T.init]  where T.init stands for the initial value for template parameter T
	// currentLength = 0

	// These are the values that we want, so no more work needs to be done here.
}	// BoundedSequence1

//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedSequence1<T, maxLength>::~BoundedSequence1()
{
	// Reread the explanation for BoundedQueue's destructor in the instructional materials

	// DONE
	// The destructors for StaticArray and Integer will automatically be called for the data members.
	// So no more work needs to be done here.
}	// ~BoundedSequence1

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::transferFrom(BoundedSequence1& source)
{
	// TODO implement transferFrom so it satisfies its ensures clause
	// Reread the explanation for BoundedQueue's transferFrom in the instructional materials
} // transferFrom

//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedSequence1<T, maxLength>& BoundedSequence1<T, maxLength>::operator = (BoundedSequence1& rhs)
{

	// TODO #1 implement operator = so it satisfies its ensures clause
	// Reread the explanation for BoundedQueue's operator = in the instructional materials

	// TODO #2 - after ALL member functions that have non-void return type have been implemented
	// delete the line at the top of this file that reads: #pragma warning( disable : 4716 )
	// Note: there are 4 member functions that are non-void return type: 
	//       operator =, entry, length, and remainingCapacity

} // operator =

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::clear(void)
{

	// TODO implement clear so it satisfies its ensures clause
	// Reread the explanation for BoundedQueue's clear in the instructional materials

}	// clear

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::add(Integer pos, T& x)
{

	// TODO implement add so it satisfies its ensures clause

	// Reread the explanation for BoundedQueue's enqueue in the instructional materials
	// BoundedQueue's enqueue works similarly to BoundedSequence's add

}	// add

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::remove(Integer pos, T& x)
{

	// TODO implement remove so it satisfies its ensures clause
	//      be sure to assume remove's requires clause is true

	// Reread the explanation for BoundedQueue's dequeue in the instructional materials
	// BoundedQueue's dequeue works similarly to BoundedSequence's remove

}	// remove

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::replaceEntry(Integer pos, T& x)
{

	// TODO implement replaceEntry so it satisfies its ensures clause
	//      be sure to assume replaceEntry's requires clause is true

	// Reread the explanation for BoundedQueue's replaceFront in the instructional materials
	// BoundedQueue's replaceFront works similarly to BoundedSequence's replaceEntry

}	// replaceEntry

//-----------------------------------------------------------------------

template <class T, int maxLength>
T& BoundedSequence1<T, maxLength>::entry(Integer pos)
{

	// TODO #1 implement entry so it satisfies its ensures clause
	//      be sure to assume entry's requires clause is true

	// Reread the explanation for BoundedQueue's front in the instructional materials
	// BoundedQueue's front works similarly to BoundedQueue's BoundedSequence's entry

	// TODO #2 - after ALL member functions that have non-void return type have been implemented
	// delete the line at the top of this file that reads: #pragma warning( disable : 4716 )
	// Note: there are 4 member functions that are non-void return type: 
	//       operator =, entry, length, and remainingCapacity

}	// entry

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::append(BoundedSequence1& sToAppend)
{

	// TODO implement append so it satisfies its ensures clause

}	// append

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::split(Integer pos, BoundedSequence1& receivingS)
{

	// TODO implement split so it satisfies its ensures clause
	//      be sure to assume split's requires clause is true

}	// split

//-----------------------------------------------------------------------

template <class T, int maxLength>
Integer BoundedSequence1<T, maxLength>::length(void)
{
	// TODO #1 implement length so it satisfies its ensures clause

	// Reread the explanation for BoundedQueue's length in the instructional materials
	// BoundedQueue's length works similarly to BoundedQueue's BoundedSequence's length

	// TODO #2 - after ALL member functions that have non-void return type have been implemented
	// delete the line at the top of this file that reads: #pragma warning( disable : 4716 )
	// Note: there are 4 member functions that are non-void return type: 
	//       operator =, entry, length, and remainingCapacity

}	// length

//-----------------------------------------------------------------------

template <class T, int maxLength>
inline Integer BoundedSequence1<T, maxLength>::remainingCapacity(void)
{
	// TODO #1 implement length so it satisfies its ensures clause

	// Reread the explanation for BoundedQueue's length in the instructional materials
	// BoundedQueue's length works similarly to BoundedQueue's BoundedSequence's length

	// TODO #2 - after ALL member functions that have non-void return type have been implemented
	// delete the line at the top of this file that reads: #pragma warning( disable : 4716 )
	// Note: there are 4 member functions that are non-void return type: 
	//       operator =, entry, length, and remainingCapacity

}	// remainingCapacity

//-----------------------------------------------------------------------

template <class T, int maxLength>
wostream & operator<<(wostream &os, BoundedSequence1<T, maxLength>& s)
{
#ifdef NDEBUG
	os << "<";
	for (int p = 0, z = s.length(), lastItem = z - 1; p < z; p++) {
		T x;

		os << s.entry(p);
		if (p < lastItem) {
			os << ",";
		} // end if
	} // end for
	os << ">";
#else
	// In Debug Configuration display representation as follows: (contents, currentLength)
	// contents - is a StaticArray1, so it's math model will be displayed
	// currentLength - is an Integer
	os << "(" << s.contents << "," << s.currentLength << ")";
#endif
	return (os);
} // operator<<