#pragma once

//
// Checking version of BoundedSet 
// author: Dr. Holly
//

template <
	template <class, class, int> class BoundedSet,
	class T,
	class TCallback,
	int maxSize
>
class BoundedSetChecking1:
	public BoundedSet <T, TCallback, maxSize>
{
	typedef BoundedSet <T, TCallback, maxSize> BoundedSetOfT;
public:

//-------------------------------------------------------------------

void add (T& x)
{
	// assert that length < maxSize
	if (BoundedSetOfT::size() + 1 > maxSize) {
		OutputDebugString(L"Operation: add\n");
		OutputDebugString(L"Assertion failed: |s| + 1 <= maxLength\n");
		DebugBreak();
	}	// end if 
	
	// assert that s does not contain x
	if (BoundedSetOfT::contains(x)) {
		OutputDebugString (L"Operation: add\n");
		OutputDebugString (L"Assertion failed: self contains x\n");
		DebugBreak ();
	}	// end if 

	BoundedSetOfT::add (x);
}	// add

//-------------------------------------------------------------------

void remove (T& xFromClient, T& xFromSet)
{
	// assert that s contains xFromClient
	if (!BoundedSetOfT::contains(xFromClient)) {
		OutputDebugString (L"Operation: remove\n");
		OutputDebugString (L"Assertion failed: self contains xFromClient\n");
		DebugBreak ();
	}	// end if 

	BoundedSetOfT::remove (xFromClient, xFromSet);
}	// remove

//-------------------------------------------------------------------

void removeAny (T& x)
{
	// assert |self| > 0
	if (BoundedSetOfT::size () <= 0) {
		OutputDebugString (L"Operation: removeAny\n");
		OutputDebugString (L"Assertion failed: |self| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedSetOfT::removeAny (x);
}	// removeAny
};
