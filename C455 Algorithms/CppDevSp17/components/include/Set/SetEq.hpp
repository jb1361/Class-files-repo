#pragma once
/*
Equality Testing Capability for Set
Author: Dr. Holly
*/

template <class T, class SetBase>
class SetEquality1 :
	public SetBase
{
public:
	Boolean operator == (SetEquality1& rhs);
};


//------------------------------------------------------------------
// Exported Operations
//------------------------------------------------------------------


template <class T, class SetBase>
Boolean SetEquality1<T, SetBase>::operator == (SetEquality1& rhs)
{
	Boolean equal;

	if (SetBase::size() == rhs.size()) {
		SetBase tempSet;
		equal = true;
		for (int i = 0, z = rhs.size(); i < z; i++) {
			T x;
			rhs.removeAny(x);
			equal = equal && SetBase::contains(x);
			tempSet.add(x);
		} // end for
		tempSet.transferFrom(rhs);
	} // end if
	return equal;
}	// operator ==

