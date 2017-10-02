#pragma once
// File: EmployeeSequence.h
// Date: 2/17
#include "wrapper.h"
//#include "EmployeeRecord.h"
#include "Sequence\Sequence1.hpp"

//----------------------------------
//
// Create a Sequence for EmployeeRecord
//

#ifdef NDEBUG
typedef Sequence1<IntegerSequence> IntegerSequence;
#else
#include "Sequence\SequenceChecking.hpp"
typedef SequenceChecking1<Sequence1, IntegerSequence> IntegerSequence;
#endif