#pragma once
//#pragma warning( disable : 4716 )

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

	enum construct {
		lowerB = 0,
		upperB = (maxLength - 1)
	};
	typedef StaticArray1<T, lowerB, upperB> ArrayOfT;
	ArrayOfT contents;
	Integer currentLength;
	// correspondence s = IteratedConcatenation(z: 0 <= z < currentLength, <contents(z)>)


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
	contents.transferFrom(source.contents);
	currentLength.transferFrom(source.currentLength);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, int maxLength>
BoundedSequence1<T, maxLength>& BoundedSequence1<T, maxLength>::operator = (BoundedSequence1& rhs)
{
	contents = rhs.contents;
	currentLength = rhs.currentLength;
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::clear(void)
{
	contents.clear();
	currentLength = 0;
}	// clear

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::add(Integer pos, T& x)
{
	currentLength++;
	for (int i = currentLength; i > pos+1; i--)
	{
		contents[i] = contents[i - 1];
	}
	contents[pos] = x;
	T n;
	x = n;
}	// add

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::remove(Integer pos, T& x)
{
	x = contents[pos];
	for (int i = pos; i <= currentLength-1; i++)
	{
		if(i != currentLength-1) contents[i] = contents[i + 1];
	}
	contents[currentLength-1] = 0;
	currentLength--;
}	// remove

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::replaceEntry(Integer pos, T& x)
{
	T n = contents[pos];
	contents[pos] = x;
	x = n;
}	// replaceEntry

//-----------------------------------------------------------------------

template <class T, int maxLength>
T& BoundedSequence1<T, maxLength>::entry(Integer pos)
{
	return contents[pos];
}	// entry

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::append(BoundedSequence1& sToAppend)
{
	for (int i = 0; i <	sToAppend.currentLength; i++)
	{
		contents[currentLength + i] = sToAppend.entry(i);
	}
	currentLength = currentLength + sToAppend.currentLength;
	sToAppend.clear();
}	// append

//-----------------------------------------------------------------------

template <class T, int maxLength>
void BoundedSequence1<T, maxLength>::split(Integer pos, BoundedSequence1& receivingS)
{
	ArrayOfT temp;
	ArrayOfT temp2;
	Integer j = 0;
	Integer n = 0;
	for (int i = 0; i < pos; i++) {
		temp[i] = contents[i];
		j = j + 1;
	}
	for (int i = pos; i  <= currentLength; i ++)
	{
		temp2[n] = contents[i];
		n = n + 1;
	}
	receivingS.clear();
	contents.clear();
	currentLength = 0;
	for (int i = 0; i < j; i++) {
		contents[i] = temp[i];
		currentLength++;
	}
	for (int i = 0; i < n-1; i++) {
		receivingS.add(receivingS.currentLength, temp2[i]);
	}
}	// split

//-----------------------------------------------------------------------

template <class T, int maxLength>
Integer BoundedSequence1<T, maxLength>::length(void)
{
	return currentLength;
}	// length

//-----------------------------------------------------------------------

template <class T, int maxLength>
inline Integer BoundedSequence1<T, maxLength>::remainingCapacity(void)
{
	return (maxLength - currentLength);
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