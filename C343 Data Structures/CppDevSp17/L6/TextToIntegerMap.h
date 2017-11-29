#pragma once
#include "Wrapper.h"
#include "Map\Map3.hpp"

class TextComparer
{
public:
	inline static Boolean areEqual(Text& lhs, Text& rhs)
	{
		return lhs == rhs;
	}
	inline static Boolean areOrdered(Text& lhs, Text& rhs)
	{
		return lhs <= rhs;
	}
	inline static Integer hashCode(Text& x)
		//! requires: |x| > 0
		//! ensures: hashCode = ASCII value for x[0]
	{
		return (x[0]);
	}
};

typedef Map3<Text, Integer, TextComparer> TextToIntegerMap;

