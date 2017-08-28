#pragma once

/*
	Checking Version of BoundedTwoWayList
	Author: Dr. Holly
*/

template <
	template <class, int> class BoundedTwoWayList,
	class T,
	int maxLength
>
class BoundedTwoWayListChecking1:
	public BoundedTwoWayList <T, maxLength>
{
	typedef BoundedTwoWayList <T, maxLength> BoundedTwoWayListOfT;
public:

//-------------------------------------------------------------------
	
void advance (void)
{
	// assert that right size > 0
	if (BoundedTwoWayListOfT::rightLength () <= 0) {
		OutputDebugString(L"Operation: advance\n");
		OutputDebugString(L"Assertion failed: |s.right| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedTwoWayListOfT::advance ();
}	// advance

//-------------------------------------------------------------------

void retreat (void)
{
	// assert that right size > 0
	if (BoundedTwoWayListOfT::leftLength() <= 0) {
		OutputDebugString(L"Operation: retreat\n");
		OutputDebugString(L"Assertion failed: |s.left| > 0\n");
		DebugBreak();
	}	// end if 

	BoundedTwoWayListOfT::retreat();
}	// retreat

//-------------------------------------------------------------------

void addRightFront(T& x)
{
	// assert that |self.left| + |self.right| + 1 <= maxLength
	if ((BoundedTwoWayListOfT::leftLength() + BoundedTwoWayListOfT::rightLength() + 1) > maxLength) {
		OutputDebugString(L"Operation: addRightFront\n");
		OutputDebugString(L"Assertion failed: |self.left| + |self.right| + 1 <= maxLength\n");
		DebugBreak();
	}	// end if 

	BoundedTwoWayListOfT::addRightFront(x);
}	// addRightFront

//-------------------------------------------------------------------

void removeRightFront (T& x)
{
	// assert that right size > 0
	if (BoundedTwoWayListOfT::rightLength () <= 0) {
		OutputDebugString(L"Operation: removeRightFront\n");
		OutputDebugString(L"Assertion failed: |s.right| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedTwoWayListOfT::removeRightFront (x);
}	// removeRightFront

//-------------------------------------------------------------------

T& rightFront (void)
{
	// assert that right size > 0
	if (BoundedTwoWayListOfT::rightLength () <= 0) {
		OutputDebugString(L"Operation: rightFront\n");
		OutputDebugString(L"Assertion failed: |s.right| > 0\n");
		DebugBreak ();
	}	// end if 

	return BoundedTwoWayListOfT::rightFront();
}	// rightFront

void replaceRightFront (T& x)
{
	// assert that right size > 0
	if (BoundedTwoWayListOfT::rightLength () <= 0) {
		OutputDebugString(L"Operation: replaceRightFront\n");
		OutputDebugString(L"Assertion failed: |s.right| > 0\n");
		DebugBreak ();
	}	// end if 

	BoundedTwoWayListOfT::replaceRightFront (x);
}

void swapRights(BoundedTwoWayList1& otherS)
{
	// assert that |self.left| + |otherS.right| <= maxLength  and
    //             |otherS.left| + |self.right| <= maxLength
	if ((BoundedTwoWayListOfT::leftLength() + otherS.rightLength()) > maxLength) {
		OutputDebugString(L"Operation: swapRights\n");
		OutputDebugString(L"Assertion failed: |self.left| + |otherS.right| <= maxLength\n");
		DebugBreak();
	}	// end if 
	if ((otherS.leftLength() + BoundedTwoWayListOfT::rightLength()) > maxLength) {
		OutputDebugString(L"Operation: swapRights\n");
		OutputDebugString(L"Assertion failed: |otherS.left| + |self.right| <= maxLength\n");
		DebugBreak();
	}	// end if 

	BoundedTwoWayListOfT::swapRights(otherS);
}

};



