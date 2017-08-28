#pragma once

//
// PartitionableArray Checking Version
// author: Dr. Holly
//

template <
	template <class, class> class PartitionableArray,
	class T,
	class TCallback
>
class PartitionableArrayChecking1:
	public PartitionableArray <T, TCallback>
{
	typedef PartitionableArray <T, TCallback> PartitionableArrayOfT;
public:
T& operator [] (Integer index)
{
	Integer lowerBound;
	Integer upperBound;

	PartitionableArrayOfT::getBounds (lowerBound, upperBound);
	// assert that index is in bounds
	if ((index < lowerBound) || (upperBound < index)) {
		OutputDebugString (L"Operation: operator []\n");
		OutputDebugString (L"Assertion failed: (lowerBound <= index) && (index <= upperBound)\n");
		DebugBreak ();
	}	// end if 
	return PartitionableArrayOfT::operator [] (index);
}	// operator []

//-------------------------------------------------------------------

Integer indexWherePHolds (void)
{
	if (!PartitionableArrayOfT::pHoldsSomewhere ()) {
		OutputDebugString (L"Operation: indexWherePHolds\n");
		OutputDebugString (L"Assertion failed: pHoldsSomewhere\n");
		DebugBreak ();
	}	// end if 
	return PartitionableArrayOfT::indexWherePHolds ();
}	// indexWherePHolds
};

