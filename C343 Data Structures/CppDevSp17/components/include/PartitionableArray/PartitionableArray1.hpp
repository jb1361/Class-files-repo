#pragma once

#include "CyclePosition\CyclePosition.hpp"
#include "CeramicArray\CeramicArray1.hpp"

//
// PartitionableArray template layered on Ceramic Array and Cycle Position
// author: Dr. Holly
//

//-----------------------------------------------------------------------
// Template Class Specification
//-----------------------------------------------------------------------

template <class T, class TCallback>
class PartitionableArray1
{
public: // Standard Operations
	PartitionableArray1 ();
	~PartitionableArray1 ();
	void clear (void);
		//! clears self
	void transferFrom(PartitionableArray1& source);
	PartitionableArray1& operator = (PartitionableArray1& rhs);

	// PartitionableArray1 Specific Operations
	void setBounds (Integer lower, Integer upper);
	void getBounds (Integer& lower, Integer& upper);
	T& operator [] (Integer index);
	Integer indexWherePHolds (void);
	Boolean pHoldsSomewhere (void);

	friend wostream& operator<< <T, TCallback>(wostream& os, PartitionableArray1& a);
		//! updates os
		//! restores a

private: // Representation
	// build Cycle Position
	typedef CyclePosition1 <Integer> IntegerCyclePosition;

	// build Array of PartitionRecord
	class PartitionRecord {
	public:
		T x;
		IntegerCyclePosition p;
	};
	typedef CeramicArray1 <PartitionRecord> PartitionRecordArray;

	// build Partitionable Array Rep
	Boolean needsUpdating;
	Integer updateIndex;
	IntegerCyclePosition rootPosition;
	PartitionRecordArray array;

private: // Local Operations
	Boolean unitCycle (IntegerCyclePosition& p);
	void addToPartition (IntegerCyclePosition& p, Integer index);
	void removeFromPartition (IntegerCyclePosition& p);
	void updatePartition (T& x, IntegerCyclePosition& p, Integer index);
	void partitionArrayOnT (void);

private: // Disallowed PartitionableArray1 Operations
	PartitionableArray1 (const PartitionableArray1& s);
	PartitionableArray1* operator & (void) {return this;};
	const PartitionableArray1* operator & (void) const {return this;};
};

//-----------------------------------------------------------------------
// Member Function Implementations
//-----------------------------------------------------------------------


//-----------------------------------------------------------------------
// Local Operations
//-----------------------------------------------------------------------

template <class T, class TCallback>
Boolean PartitionableArray1<T, TCallback>::unitCycle (IntegerCyclePosition& p)
{
	IntegerCyclePosition q;

	q = p;
	q.applyTarget();
	return q == p;
} // unitCycle

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::addToPartition (IntegerCyclePosition& p, Integer index)
{
	p.replaceLabel(index);
	rootPosition.transposeAfter(p);
}	// addToPartition

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::removeFromPartition (IntegerCyclePosition& p)
{
	IntegerCyclePosition q;

	q = p;
	q.applyInverseTarget();
	q.transposeAfter(p);
}	// removeFromPartition

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::updatePartition (T& x, IntegerCyclePosition& p, Integer index)
{
	Boolean wasPartitionable;
	Boolean isPartitionable;

	wasPartitionable = !unitCycle(p);
	isPartitionable = TCallback::isPartitionable(x);

	if (wasPartitionable && !isPartitionable) {
		removeFromPartition(p);
	}	// end if
	if (!wasPartitionable && isPartitionable) {
		addToPartition(p, index);
	}	// end if
}	// updatePartition

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::partitionArrayOnT (void)
// post: partitions the array based on values currently stored in the array
{
	T x;

	if (TCallback::isPartitionable(x)) {
		Integer index, lowerBound, upperBound;

		array.getBounds(lowerBound, upperBound);
		for (index = lowerBound; index <= upperBound; index++) {
			addToPartition ((array[index]).p, index);
		}	// end for
	}	// end if
}	// partitionArrayOnT ()

//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

template <class T, class TCallback>
PartitionableArray1<T, TCallback>::PartitionableArray1 ()
{
	partitionArrayOnT();
}	// PartitionableArray1 ()

//-----------------------------------------------------------------------

template <class T, class TCallback>
PartitionableArray1<T, TCallback>::~PartitionableArray1 ()
{
}	// ~PartitionableArray1 ()

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::clear(void)
{
	array.clear();
	rootPosition.clear();
	needsUpdating.clear();
	partitionArrayOnT();
}	// clear

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::transferFrom(PartitionableArray1& source)
{
	needsUpdating.transferFrom(source.needsUpdating);
	updateIndex.transferFrom(source.updateIndex);
	rootPosition.transferFrom(source.rootPosition);
	array.transferFrom(source.array);
} // transferFrom

//-----------------------------------------------------------------------

template <class T, class TCallback>
PartitionableArray1<T, TCallback>& PartitionableArray1<T, TCallback>::operator = (PartitionableArray1& rhs)
{
	Integer lower, upper;

	rhs.array.getBounds(lower, upper);
	array.setBounds(lower, upper);
	rootPosition.clear();
	needsUpdating.clear();
	partitionArrayOnT();

	for (int index = lower; index <= upper; index++) {
		array[index].x = rhs.array[index].x;
		updatePartition((array[index]).x, (array[index]).p, index);
	} // end for
	return *this;
} // operator =

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::setBounds (
         Integer lower,
         Integer upper
      )
{
	array.setBounds(lower, upper);
	rootPosition.clear();
	needsUpdating.clear();
	partitionArrayOnT();
}  // setBounds

//-----------------------------------------------------------------------

template <class T, class TCallback>
void PartitionableArray1<T, TCallback>::getBounds (
			Integer& lower,
			Integer& upper
		)
{
	array.getBounds(lower, upper);
}	// getBounds

//-----------------------------------------------------------------------

template <class T, class TCallback>
T& PartitionableArray1<T, TCallback>::operator [] (
			Integer index
		)
{
	if (needsUpdating && (index != updateIndex)) {
		updatePartition((array[updateIndex]).x, (array[updateIndex]).p, updateIndex);
	}	// end if
	needsUpdating = true;
	updateIndex = index;
	return array[index].x;
}	// operator []

//-----------------------------------------------------------------------

template <class T, class TCallback>
Integer PartitionableArray1<T, TCallback>::indexWherePHolds (void)
{
	IntegerCyclePosition q;
	Integer index;

	if (needsUpdating) {
		updatePartition((array[updateIndex]).x, (array[updateIndex]).p, updateIndex);
		needsUpdating = false;
	}	// end if

	q = rootPosition;
	q.applyTarget();
	index = q.label();
	return index;
}	// indexWherePHolds

//-----------------------------------------------------------------------

template <class T, class TCallback>
Boolean PartitionableArray1<T, TCallback>::pHoldsSomewhere (void)
{
	if (needsUpdating) {
		updatePartition((array[updateIndex]).x, (array[updateIndex]).p, updateIndex);
		needsUpdating = false;
	}	// end if
	return !unitCycle(rootPosition);
}	// pHoldsSomewhere

//-----------------------------------------------------------------------

template <class T, class TCallback>
wostream& operator<<(wostream& os, PartitionableArray1<T, TCallback>& a)
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