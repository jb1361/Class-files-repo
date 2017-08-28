#pragma once
/*
	Checking Version of BoundedStack
	Author: Dr. Holly
*/

template <
	template <class, int> class BoundedStack,
	class T,
	int maxLength
>
class BoundedStackChecking1:
	public BoundedStack <T, maxLength>
{
	typedef BoundedStack <T, maxLength> BoundedStackOfT;
public:

	//-------------------------------------------------------------------

	void push (T& x)
	{
		// assert that length < maxLength
		if (BoundedStackOfT::length() + 1 > maxLength) {
			OutputDebugString(L"Operation: push\n");
			OutputDebugString(L"Assertion failed: |s| + 1 <= maxLength\n");
			DebugBreak();
		}	// end if 

		BoundedStackOfT::push(x);
	}	// push

//-------------------------------------------------------------------

void pop (T& x)
{
	// assert that length > 0
	if (BoundedStackOfT::length() <= 0) {
		OutputDebugString(L"Operation: pop\n");
		OutputDebugString(L"Assertion failed: |s| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedStackOfT::pop (x);
}	// pop

//-------------------------------------------------------------------

T& top(void)
{
	// assert that length > 0
	if (BoundedStackOfT::length () <= 0) {
		OutputDebugString(L"Operation: top\n");
		OutputDebugString(L"Assertion failed: |s| > 0\n");
		DebugBreak ();
	}	// end if 

	return BoundedStackOfT::top();
}	// top

//-------------------------------------------------------------------

void replaceTop(T& x)
{
	// assert that length > 0
	if (BoundedStackOfT::length () <= 0) {
		OutputDebugString(L"Operation: replaceTop\n");
		OutputDebugString(L"Assertion failed: |s| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedStackOfT::replaceTop(x);
}	// replaceTop
};

