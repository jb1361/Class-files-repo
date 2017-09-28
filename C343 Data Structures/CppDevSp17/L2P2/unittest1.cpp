#include "stdafx.h"
#include "CppUnitTest.h"
#include "wrapper.h" 
#include "IntegerSequence.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L2P2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// -----------------------------------------------------------------------------------
		// add
		// -----------------------------------------------------------------------------------
		//! updates self
		//! restores pos
		//! clears x
		//! requires: 0 <= pos <= |self|
		//! ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT05AddV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT05AddV1: s1.add(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = ([0,0,0,0,0],0) and j = 0 and k = 15");
			Logger::WriteMessage(L"\toutgoing: s1 = ([15,0,0,0,0],1) and j = 0 and k = 0");

			// Test set up and execute add
			j = 0;
			k = 15;

			// Execute operation: add
			s1.add(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "([15,0,0,0,0],1)", L"s1 = ([15,0,0,0,0],1)");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT05AddV1


		  // -----------------------------------------------------------------------------------
		  // remove
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! restores pos
		  //! replaces x
		  //! requires: 0 <= pos < |self|
		  //! ensures: <x> = #self[pos, pos+1) and
		  //!          self = #self[0, pos) * #self[pos+1, |#self|)
		  // -----------------------------------------------------------------------------------

	
		TEST_METHOD(UT06RemoveV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT06RemoveV1: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = ([77,0,0,0,0],1) and j = 0 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = ([0,0,0,0,0],0) and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Execute operation: remove
			s1.remove(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 77, L"k = 77");

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "([0,0,0,0,0],0)", L"s1 = ([0,0,0,0,0],0)");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT06RemoveV1

		TEST_METHOD(UT06RemoveV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT06RemoveV1: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = ([77,76,75,74,73],5) and j = 0 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = ([76,75,74,73,0],4) and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			j = 2;
			k = 75;
			s1.add(j, k);
			j = 3;
			k = 74;
			s1.add(j, k);
			j = 4;
			k = 73;
			s1.add(j, k);
			j = 0;
			// Execute operation: remove
			s1.remove(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 77, L"k = 77");

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "([76,75,74,73,0],4)");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT06RemoveV2
		TEST_METHOD(UT06RemoveV3)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT06RemoveV1: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = ([77,76,75,74,73],5) and j = 0 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = ([77,76,74,73,0],4) and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			j = 2;
			k = 75;
			s1.add(j, k);
			j = 3;
			k = 74;
			s1.add(j, k);
			j = 4;
			k = 73;
			s1.add(j, k);
			j = 2;
			// Execute operation: remove
			s1.remove(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 75, L"k = 77");

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "([77,76,74,73,0],4)");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 2, L"j = 2");
		} // UT06RemoveV3

		  // -----------------------------------------------------------------------------------
		  // length
		  // -----------------------------------------------------------------------------------
		  //! restores self
		  //! ensures: length = |self|
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT11LengthV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT11LengthV1: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = ([0,0,0,0,0],0)");
			Logger::WriteMessage(L"\toutgoing: s1 = ([0,0,0,0,0],0)");

			// Verify ensures: length = |self|
			Assert::IsTrue(s1.length() == 0, L"|s1| = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "([0,0,0,0,0],0)", L"s1 = ([0,0,0,0,0],0)");
		} // UT11LengthV1

		TEST_METHOD(UT11LengthV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j = 1;
			Logger::WriteMessage(L"UT11LengthV1: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = ([1,0,0,0,0],1)");
			Logger::WriteMessage(L"\toutgoing: s1 = ([1,0,0,0,0],1)");
			s1.add(0, j);
			// Verify ensures: length = |self|
			Assert::IsTrue(s1.length() == 1, L"|s1| = 1");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "([1,0,0,0,0],1)");
		} // UT11LengthV2

		TEST_METHOD(UT06ClearV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;


			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			s1.clear();
			toText(s1, x1);
			Assert::IsTrue(x1 == "([0,0,0,0,0],0)");

		} 
		TEST_METHOD(UT06ReplaceEntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;


			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			
			k = 5;
			s1.replaceEntry(j, k);
			toText(k, x1);
			Assert::IsTrue(k == 76);
			toText(s1, x1);
			Assert::IsTrue(x1 == "([77,5,0,0,0],2)");

		}

		TEST_METHOD(UT11EntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j = 1;
			
			s1.add(0, j);
			// Verify ensures: length = |self|
			Assert::IsTrue(s1.entry(j) == 1);

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "([1,0,0,0,0],1)");
		} 
		TEST_METHOD(UT11AppendV1)
		{
			IntegerSequence s1,s2;
			Text x1;
			Integer j = 1;

			s1.add(0, j);
			j = 2;
			s2.add(0, j);
			j = 3;
			s2.add(1, j);

			s1.append(s2);
			
			toText(s1, x1);
			Assert::IsTrue(x1 == "([1,2,3,0,0],3)");

			toText(s2, x1);
			Assert::IsTrue(x1 == "([0,0,0,0,0],0)");
		}
		TEST_METHOD(UT11AppendV2)
		{
			IntegerSequence s1, s2;
			Text x1;
			Integer j = 1;

			s1.add(0, j);
			j = 2;
			s2.add(0, j);
			j = 3;
			s2.add(1, j);
			j = 4;
			s2.add(2, j);
			j = 5;
			s2.add(3, j);
			s1.append(s2);

			toText(s1, x1);
			Assert::IsTrue(x1 == "([1,2,3,4,5],5)");

			toText(s2, x1);
			Assert::IsTrue(x1 == "([0,0,0,0,0],0)");
		}
		TEST_METHOD(UT11SplitV1)
		{
			IntegerSequence s1, s2;
			Text x1;
			Integer j;

			j = 1;
			s1.add(0, j);
			j = 2;
			s2.add(0, j);
			j = 3;
			s2.add(1, j);
			j = 4;
			s2.add(2, j);

			s2.split(1, s1);

			toText(s1, x1);
			Assert::IsTrue(x1 == "([3,4,0,0,0],2)");

			toText(s2, x1);
			Assert::IsTrue(x1 == "([2,0,0,0,0],1)");
		}
		TEST_METHOD(UT11SplitV2)
		{
			IntegerSequence s1, s2;
			Text x1;
			Integer j;

			j = 1;
			s1.add(0, j);
			j = 2;
			s2.add(0, j);
			j = 3;
			s2.add(1, j);
			j = 4;
			s2.add(2, j);
			j = 5;
			s2.add(3, j);
			j = 5;
			s2.add(4, j);
			s2.split(2, s1);

			toText(s1, x1);
			Assert::IsTrue(x1 == "([4,5,5,0,0],3)");

			toText(s2, x1);
			Assert::IsTrue(x1 == "([2,3,0,0,0],2)");
		}

		TEST_METHOD(UT06RemainingCapacityV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;


			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			
			Assert::IsTrue(s1.remainingCapacity() == 3);

		}
		TEST_METHOD(UT06EqualsV1)
		{
			IntegerSequence s1,s2;
			Text x1;
			Integer j, k;


			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);
			j = 1;
			k = 76;
			s1.add(j, k);
			s2 = s1;
			toText(s2, x1);
			Assert::IsTrue(x1 == "([77,76,0,0,0],2)");

		}
	};
}