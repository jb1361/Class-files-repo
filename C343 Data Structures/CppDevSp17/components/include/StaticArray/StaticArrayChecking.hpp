#pragma once

//
// StaticArray Checking Version
// author: Dr. Holly
//

template <
		template <class, int, int> class StaticArray,
		class T,
		int lowerBound,
		int upperBound
	>
class StaticArrayChecking1:
	public StaticArray <T, lowerBound, upperBound>
{
	typedef StaticArray <T, lowerBound, upperBound> StaticArrayOfT;
public:
T& operator [] (Integer index)
{
	// assert that index is in bounds
	if ((index < lowerBound) || (upperBound < index)) {
		OutputDebugString (L"Operation: operator []\n");
		OutputDebugString (L"Assertion failed: (lowerBound <= index) && (index <= upperBound)\n");
		DebugBreak ();
	}	// end if 

	return StaticArrayOfT::operator [] (index);
}	// operator []

};


