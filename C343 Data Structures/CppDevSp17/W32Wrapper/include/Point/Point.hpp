#pragma once
#include "Wrapper.h"

class Point: public POINT
{
	// Inherits the representation from Window's POINT
	// POINT's representation is: int x, y

	// Adds the following operations: constructor, clear, operator =, transferFrom, operator <<
	// Use Point whereever a Windows program calls for a POINT

private:
	void initializeRep()
		//! replaces self
		//! ensures: self = (0, 0)
	{
		x = 0;
		y = 0;
	} // initializeRep

	void copyRep (Point& from)
		//! restores from
		//! ensures: self = from
	{
		x = from.x;
		y = from.y;
	} // copyRep

public:
	Point()
		//! replaces self
		//! ensures: self = (0, 0)
	{
		initializeRep();
	} // Point()

	Point(int x, int y)
		//! replaces self
		//! ensures: self = (x, y)
	{
		self.x = x;
		self.y = y;
	} // Point(int x, int y)

	~Point() {}

	void clear(void)
		//! clears self
	{
		initializeRep();	
	} // clear

	Point& operator = (Point& rhs)
		//! replaces self
		//! restores rhs
		//! ensures: self = rhs
	{
		copyRep(rhs);	
		return *this;
	} // operator =

	void transferFrom(Point& source)
		//! replaces self
		//! clears source
		//! ensures: self = source
	{
		copyRep(source);	
		source.initializeRep();
	} // transferFrom

	friend wostream& operator << (wostream &os, Point& r)
	{
		os << L"(" << r.x << L"," << r.y << L")";
		return os;
	} // operator <<
};