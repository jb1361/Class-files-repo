#pragma once

//
// Checking version of Set 
// author: Dr. Holly
//

template <
	template <class, class> class Set,
	class T,
	class TCallback
>
class SetChecking1:
	public Set <T, TCallback>
{
	typedef Set <T, TCallback> SetOfT;
public:

//-------------------------------------------------------------------

void add (T& x)
{
	// assert that s does not contain x
	if (SetOfT::contains(x)) {
		OutputDebugString (L"Operation: add\n");
		OutputDebugString (L"Assertion failed: self contains x\n");
		DebugBreak ();
	}	// end if 

	SetOfT::add (x);
}	// add

//-------------------------------------------------------------------

void remove (T& xFromClient, T& xFromSet)
{
	// assert that s contains xFromClient
	if (!SetOfT::contains(xFromClient)) {
		OutputDebugString (L"Operation: remove\n");
		OutputDebugString (L"Assertion failed: self contains xFromClient\n");
		DebugBreak ();
	}	// end if 

	SetOfT::remove (xFromClient, xFromSet);
}	// remove

//-------------------------------------------------------------------

void removeAny (T& x)
{
	// assert |self| > 0
	if (SetOfT::size () <= 0) {
		OutputDebugString (L"Operation: removeAny\n");
		OutputDebugString (L"Assertion failed: |self| > 0\n");
		DebugBreak ();
	}	// end if 

	SetOfT::removeAny (x);
}	// removeAny
};
