#pragma once
/*
	Checking Version of BoundedPreemtableQueue
	Author: Dr. Holly
*/

template <
	template <class, int> class PreemtableQueue,
	class T,
	int maxLength
>
class BoundedPreemptableQueueChecking1:
	public PreemtableQueue <T, maxLength>
{
	typedef PreemtableQueue <T, maxLength> BoundedPreemtableQueue;
public:

//-------------------------------------------------------------------

	void enqueue (T& x)
	{
		// assert that length < maxLength
		if (BoundedPreemtableQueue::length() + 1 > maxLength) {
			OutputDebugString(L"Operation: enqueue\n");
			OutputDebugString(L"Assertion failed: |q| + 1 <= maxLength\n");
			DebugBreak();
		}	// end if 

		BoundedPreemtableQueue::enqueue(x);
	}	// enqueue

//-------------------------------------------------------------------

void dequeue (T& x)
{
	// assert that length > 0
	if (BoundedPreemtableQueue::length() <= 0) {
		OutputDebugString(L"Operation: dequeue\n");
		OutputDebugString(L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedPreemtableQueue::dequeue (x);
}	// dequeue

//-------------------------------------------------------------------

void inject (T& x)
{
	// assert that length < maxLength
	if (BoundedPreemtableQueue::length() + 1 > maxLength) {
		OutputDebugString(L"Operation: inject\n");
		OutputDebugString(L"Assertion failed: |q| + 1 <= maxLength\n");
		DebugBreak();
	}	// end if 

	BoundedPreemtableQueue::inject(x);
}	// inject

//-------------------------------------------------------------------

T& front(void)
{
	// assert that length > 0
	if (BoundedPreemtableQueue::length () <= 0) {
		OutputDebugString(L"Operation: front\n");
		OutputDebugString(L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	return BoundedPreemtableQueue::front();
}	// front

//-------------------------------------------------------------------

void replaceFront(T& x)
{
	// assert that length > 0
	if (BoundedPreemtableQueue::length () <= 0) {
		OutputDebugString(L"Operation: replaceFront\n");
		OutputDebugString(L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedPreemtableQueue::replaceFront(x);
}	// replaceFront
};

