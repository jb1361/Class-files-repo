#pragma once
#include "Wrapper.h"
#include "Queue\Queue1.hpp"

/*
TODO #2:
	Change this file by doing the following:
	1) Changes at the top of this file: add a #include for Sequence1
	2) Changes below in this file: add a #include for SequenceChecking1 in the appropriate place 
	3) Changes below in this file: add typedef lines that create an instance called IntegerSequence, 
	   create this instance from from Sequence1 and SequenceChecking1, add these in the appropriate places
	4) Rebuild the project - it should rebuild without compiler errors, if you have compiler errors
	   then it is because something was incorrectly done in this file 
	5) After you successfuly rebuild the project, navigate to the bottom of driver.cpp file and find TODO #3
*/

#ifdef NDEBUG
//
// if NDEBUG is defined, then we are in Release Configuration
//

typedef Queue1<Integer> IntegerQueue;

#else
//
// else NDEBUG is not defined, then we are in Debug Configuration
//

#include "Queue\QueueChecking.hpp"

typedef QueueChecking1<Queue1, Integer> IntegerQueue;

#endif // NDEBUG


/*
	TODO #12:
		1) Eliminate from this file all lines that reference Queue
		2) Then rebuild in both Debug and Release configurations - there should be no compiler errors
		3) Eliminate from this file all "TODO" comments
		4) Rebuild and Run your program
*/