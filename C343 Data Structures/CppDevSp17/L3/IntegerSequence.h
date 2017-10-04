#pragma once
// File: IntegerSequence.h
// Date: 2/17
#include "wrapper.h"
//#include "EmployeeRecord.h"
#include "Sequence\Sequence1.hpp"


#ifdef NDEBUG
typedef Sequence1<Integer,Integer> IntegerSequence;
#else
#include "Sequence\SequenceChecking.hpp"
typedef SequenceChecking1<Sequence1, Integer> IntegerSequence;
#endif