#pragma once
#include "Wrapper.h"
#include "Sequence\Sequence1.hpp"
#include "Sequence\SequenceChecking.hpp"
#include "AirportRecord.h"

#ifdef NDEBUG

typedef Sequence1<AirportRecord> AirportSequence;

#else

typedef SequenceChecking1<Sequence1, AirportRecord> AirportSequence;

#endif // NDEBUG
