#pragma once
/*
	Checking Version of Queue
	Author: Dr. Holly
*/

template <
	template <class> class Queue,
	class T
>
class QueueChecking1:
	public Queue <T>
{
	typedef Queue <T> QueueOfT;
public:

//-------------------------------------------------------------------

void dequeue (T& x)
{
	// assert that length > 0
	if (QueueOfT::length() <= 0) {
		OutputDebugString (L"Operation: dequeue\n");
		OutputDebugString (L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	QueueOfT::dequeue (x);
}	// dequeue

//-------------------------------------------------------------------

T& front(void)
{
	// assert that length > 0
	if (QueueOfT::length () <= 0) {
		OutputDebugString (L"Operation: front\n");
		OutputDebugString (L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	return QueueOfT::front();
}	// front

//-------------------------------------------------------------------

void replaceFront(T& x)
{
	// assert that length > 0
	if (QueueOfT::length () <= 0) {
		OutputDebugString (L"Operation: replaceFront\n");
		OutputDebugString (L"Assertion failed: |q| > 0\n");
		DebugBreak ();
	}	// end if 

	QueueOfT::replaceFront(x);
}	// replaceFront
};

