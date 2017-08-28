#pragma once

//
// CeramicArray Checking Version
// author: Dr. Holly
//

template <
	template <class> class CeramicArray,
	class T
>
class CeramicArrayChecking1:
	public CeramicArray <T>
{
	typedef CeramicArray <T> ArrayOfT;
public:

//-----------------------------------------------------------------------

T& operator [] (Integer index)
{
	Integer lowerBound;
	Integer upperBound;

	ArrayOfT::getBounds (lowerBound, upperBound);
	// assert that index is in bounds
	if ((index < lowerBound) || (upperBound < index)) {
		OutputDebugString (L"Operation: operator []\n");
		OutputDebugString (L"Assertion failed: (lowerBound <= index) && (index <= upperBound)\n");
		DebugBreak ();
	}	// end if 
	
	return ArrayOfT::operator [] (index);
}	// operator []

//-----------------------------------------------------------------------

void setBounds (Integer lower, Integer upper)
{
	if (lower > upper) {
		OutputDebugString (L"Operation: operator []\n");
		OutputDebugString (L"Assertion failed: (lower <= upper)\n");
		DebugBreak ();
	}	// end if 
	
	ArrayOfT::setBounds (lower, upper);
}	// setBounds

};

