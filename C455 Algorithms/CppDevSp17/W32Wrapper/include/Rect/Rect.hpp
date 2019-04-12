#pragma once
#include "Wrapper.h"

class Rect: public RECT
{
	// Inherits the representation from Window's RECT
	// RECT's representation is: int left, top, right, bottom

	// Adds the following operations: constructor, clear, operator =, transferFrom, operator <<
	// Use Rect where ever a Windows program calls for a RECT

private:
	void initializeRep()
		//! ensures: self = (0, 0, 0, 0)
	{
		left = 0;
		top = 0;
		right = 0;
		bottom = 0;	
	} // initializeRep

	void copyRep (Rect& from)
		//! replaces self
		//! restores from
		//! ensures: self = from
	{
		left = from.left;
		top = from.top;
		right = from.right;
		bottom = from.bottom;	
	} // copyRep

public:
	Rect()
		//! replaces self
		//! ensures: self = (0, 0, 0, 0)
	{
		initializeRep();
	} // Rect()

	Rect(int left, int top, int right, int bottom)
		//! replaces self
		//! restores left, top, right, bottom
		//! ensures: self = (left, top, right, bottom)
	{
		self.left = left;
		self.top = top;
		self.right = right;
		self.bottom = bottom;
	} // Rect(int left, int top, int right, int bottom)

	~Rect() {}

	void clear(void)
		//! clears self
	{
		initializeRep();	
	} // clear

	Rect& operator = (Rect& rhs)
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
	{
		copyRep(rhs);	
		return *this;
	} // operator =

	void transferFrom(Rect& source)
		//! replaces self
		//! clears source
		//! ensures: self = source
	{
		copyRep(source);	
		source.initializeRep();
	} // transferFrom

	friend wostream& operator << (wostream &os, Rect& r)
	{
		os << L"(" << r.left << L"," << r.top << L"," << r.right << L"," << r.bottom << L")";
		return os;
	} // operator <<
};