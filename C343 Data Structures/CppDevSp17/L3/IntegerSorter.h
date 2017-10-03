#pragma once
#include "wrapper.h"
#include "IntegerSequence.h"
#include "SortingMachine\SortingMachine1.hpp"

//----------------------------------
//
// Create Comparer class
//

class IntegerComparer
{
public:
	static Boolean areOrdered(Integer& lhs, Integer& rhs)
		//! restores lhs, rhs
	{
		return lhs <= rhs;
	}; // areOrdered
};

//----------------------------------
//
// Create a Sorting Machine for EmployeeRecord
//

#ifdef NDEBUG
typedef SortingMachine2<Integer, IntegerComparer> IntegerSorter;
#else
#include "SortingMachine\SortingMachineChecking.hpp"
typedef SortingMachineChecking1<SortingMachine1, IntegerSequence, IntegerComparer> IntegerSorter;
#endif