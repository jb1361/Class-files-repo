#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "IntegerSequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L5Sol
{
	TEST_CLASS(UnitTest1)
	{
	public:

#ifdef NDEBUG

		// -----------------------------------------------------------------------------------
		// Sequence1()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Sequence1();");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Verify ensures: self = <>
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT01ConstructorV1

		  // -----------------------------------------------------------------------------------
		  // clear
		  // -----------------------------------------------------------------------------------
		  //! clears self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT02ClearV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Execute operation: clear
			s1.clear();

			// Verify parameter mode clears: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT02ClearV1

		TEST_METHOD(UT02ClearV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT02ClearV2: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <33>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Test set up
			k = 33;
			s1.add(0, k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT02ClearV2



		  // -----------------------------------------------------------------------------------
		  // transferFrom
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! clears source
		  //! ensures: self = #source
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT03TransferFromV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT03TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");

			// Verify clears parameter mode: clears source
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");
		} // UT03TransferFromV1

		TEST_METHOD(UT03TransferFromV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT03TransferFromV2: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing: s1 = <44> and s2 = <>");

			// Test set up
			k = 44;
			s2.add(0, k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Assert::IsTrue(x1 == "<44>", L"s1 = <44>");

			// Verify clears parameter mode: clears source
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");
		} // UT03TransferFromV2

		  // -----------------------------------------------------------------------------------
		  // operator =
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! restores rhs
		  //! ensures: self = rhs
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT04AssignmentV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT04AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: operator =
			s1 = s2;

			// Verify ensures: self = rhs
			toText(s1, x1);
			toText(s2, x2);
			Assert::IsTrue(x1 == x2, L"s1 = s2");

			// Verify restores parameter mode: restores rhs
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT04AssignmentV1

		TEST_METHOD(UT04AssignmentV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04AssignmentV2: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <27>");
			Logger::WriteMessage(L"\toutgoing: s1 = <27> and s2 = <27>");

			// Test set up
			k = 27;
			s2.add(0, k);

			// Execute operation: operator =
			s1 = s2;

			// Verify ensures: self = rhs
			toText(s1, x1);
			toText(s2, x2);
			Assert::IsTrue(x1 == x2, L"s1 = s2");

			// Verify restores parameter mode: restores rhs
			toText(s1, x1);
			Assert::IsTrue(x1 == "<27>", L"s1 = <27>");
		} // UT04AssignmentV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <> and j = 0 and k = 15");
			Logger::WriteMessage(L"\toutgoing: s1 = <15> and j = 0 and k = 0");

			// Test set up and execute add
			j = 0;
			k = 15;

			// Execute operation: add
			s1.add(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<15>", L"s1 = <15>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT05AddV1

		TEST_METHOD(UT05AddV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT05AddV2: s1.add(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <15> and j = 0 and k = 25");
			Logger::WriteMessage(L"\toutgoing: s1 = <25,15> and j = 0 and k = 0");

			// Test set up
			j = 0;
			k = 15;
			s1.add(j, k);

			// Execute operation: add
			k = 25;
			s1.add(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<25,15>", L"s1 = <25,15>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");

			// Verify clears parameter mode: clears x
			Assert::IsTrue(k == 0, L"k = 0");
		} // UT05AddV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and j = 0 and k = 77");

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
			Assert::IsTrue(x1 == "<>", L"s1 = <>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT06RemoveV1

		TEST_METHOD(UT06RemoveV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT06RemoveV2: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77> and j = 4 and k = 99");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: remove
			j = 4;
			s1.remove(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 99, L"k = 99");

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77>", L"s1 = <11,33,55,77>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 4, L"j = 4");
		} // UT06RemoveV2

		  // -----------------------------------------------------------------------------------
		  // replaceEntry
		  // -----------------------------------------------------------------------------------
		  //! updates self, x
		  //! restores pos
		  //! requires: 0 <= pos < |self|
		  //! ensures: <x> = #self[pos, pos+1)  and
		  //!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT07ReplaceEntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT07ReplaceEntryV1: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0 and k = 8");
			Logger::WriteMessage(L"\toutgoing: s1 = <8> and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Execute operation: replaceEntry
			k = 8;
			s1.replaceEntry(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 77, L"k = 77");

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<8>", L"s1 = <8>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT07ReplaceEntryV1

		TEST_METHOD(UT07ReplaceEntryV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT07ReplaceEntryV2: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4 and k = 8");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77,8> and j = 4 and k = 99");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: replaceEntry
			j = 4;
			k = 8;
			s1.replaceEntry(j, k);

			// Verify ensures: <x> = #self[pos, pos+1)
			Assert::IsTrue(k == 99, L"k = 99");

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,8>", L"s1 = <11,33,55,77,8>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 4, L"j = 4");
		} // UT07ReplaceEntryV2

		  // -----------------------------------------------------------------------------------
		  // entry
		  // -----------------------------------------------------------------------------------
		  //! restores self, pos
		  //! requires: 0 <= pos < |self|
		  //! ensures: <entry> = self[pos, pos+1)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT08EntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT08EntryV1: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <77> and j = 0");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Verify ensures: <entry> = self[pos, pos+1)
			Assert::IsTrue(s1.entry(j) == 77, L"<entry> = self[pos, pos+1)");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<77>", L"s1 = <77>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT08EntryV1

		TEST_METHOD(UT08EntryV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT08EntryV2: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77,99> and j = 4");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);


			// Verify ensures: <entry> = self[pos, pos+1)
			j = 4;
			Assert::IsTrue(s1.entry(j) == 99, L"<entry> = self[pos, pos+1)");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,99>", L"s1 = <11,33,55,77,99>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 4, L"j = 4");
		} // UT08EntryV2

		  // -----------------------------------------------------------------------------------
		  // append
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! clears sToAppend
		  //! ensures: self = #self * sToAppend
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT09AppendV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT09AppendV1: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: append
			s1.append(s2);

			// Verify ensures: self = #self * sToAppend
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");

			// Verify clears parameter mode: clears sToAppend
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");
		} // UT09AppendV1

		TEST_METHOD(UT09AppendV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT09AppendV2: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing: s1 = <44> and s2 = <>");

			// Test set up
			k = 44;
			s2.add(0, k);

			// Execute operation: append
			s1.append(s2);

			// Verify ensures: self = #self * sToAppend
			toText(s1, x1);
			Assert::IsTrue(x1 == "<44>", L"s1 = <44>");

			// Verify clears parameter mode: clears sToAppend
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");
		} // UT09AppendV2

		  // -----------------------------------------------------------------------------------
		  // split
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! restores pos
		  //! replaces receivingS
		  //! requires: 0 <= pos <= |self|
		  //! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT10SplitV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer j;

			Logger::WriteMessage(L"UT10SplitV1: s1.split(j, s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <> and j = 0");

			// Execute operation: split
			s1.split(j, s2);

			// Verify ensures: self = #self[0, pos)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");

			// Verify ensures: receivingS = #self[pos, |self|)
			toText(s2, x2);
			Assert::IsTrue(x2 == "<>", L"s2 = <>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT10SplitV1

		TEST_METHOD(UT10SplitV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer j, k;

			Logger::WriteMessage(L"UT10SplitV2: s1.split(j, s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and s2 = <> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <11,33,55,77,99> and j = 0");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: split
			s1.split(j, s2);

			// Verify ensures: self = #self[0, pos)
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");

			// Verify ensures: receivingS = #self[pos, |self|)
			toText(s2, x2);
			Assert::IsTrue(x2 == "<11,33,55,77,99>", L"s2 = <11,33,55,77,99>");

			// Verify restores parameter mode: restores pos
			Assert::IsTrue(j == 0, L"j = 0");
		} // UT10SplitV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Verify ensures: length = |self|
			Assert::IsTrue(s1.length() == 0, L"|s1| = 0");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>", L"s1 = <>");
		} // UT11LengthV1

		TEST_METHOD(UT11LengthV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11LengthV2: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <95>");
			Logger::WriteMessage(L"\toutgoing: s1 = <95>");

			// Test set up
			k = 95;
			s1.add(0, k);

			// Verify ensures: length = |self|
			Assert::IsTrue(s1.length() == 1, L"|s1| = 1");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<95>", L"s1 = <95>");
		} // UT11LengthV2

#else

		// -----------------------------------------------------------------------------------
		// Sequence1()
		// -----------------------------------------------------------------------------------
		//! replaces self
		//! ensures: self = <>
		// -----------------------------------------------------------------------------------

		TEST_METHOD(UT01ConstructorV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Sequence1();");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");
			// Verify ensures: self = <>
			toText(s1, x1);			
			Logger::WriteMessage(x1);
		} // UT01ConstructorV1


		  // -----------------------------------------------------------------------------------
		  // clear
		  // -----------------------------------------------------------------------------------
		  //! clears self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT02ClearV1)
		{
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Execute operation: clear
			s1.clear();

			// Verify parameter mode clears: clears self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT02ClearV1

		TEST_METHOD(UT02ClearV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT02ClearV2: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <33>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Test set up
			k = 33;
			s1.add(0, k);

			// Execute operation: clear
			s1.clear();

			// Verify clears parameter mode: clears self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT02ClearV2

		  // -----------------------------------------------------------------------------------
		  // transferFrom
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! clears source
		  //! ensures: self = #source
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT03TransferFromV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT03TransferFromV1: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify clears parameter mode: clears source
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT03TransferFromV1

		TEST_METHOD(UT03TransferFromV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT03TransferFromV2: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing: s1 = <44> and s2 = <>");

			// Test set up
			k = 44;
			s2.add(0, k);

			// Execute operation: transferFrom
			s1.transferFrom(s2);

			// Verify ensures: self = #source
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify clears parameter mode: clears source
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT03TransferFromV2

		  // -----------------------------------------------------------------------------------
		  // operator =
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! restores rhs
		  //! ensures: self = rhs
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT04AssignmentV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT04AssignmentV1: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: operator =
			s1 = s2;

			// Verify ensures: self = rhs
			toText(s1, x1);
			toText(s2, x2);
			Logger::WriteMessage(x1);
			Logger::WriteMessage(x2);

		} // UT04AssignmentV1

		TEST_METHOD(UT04AssignmentV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT04AssignmentV2: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <27>");
			Logger::WriteMessage(L"\toutgoing: s1 = <27> and s2 = <27>");

			// Test set up
			k = 27;
			s2.add(0, k);

			// Execute operation: operator =
			s1 = s2;

			// Verify ensures: self = rhs
			toText(s1, x1);
			toText(s2, x2);
			Logger::WriteMessage(x1);
			Logger::WriteMessage(x2);
		} // UT04AssignmentV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <> and j = 0 and k = 15");
			Logger::WriteMessage(L"\toutgoing: s1 = <15> and j = 0 and k = 0");

			// Test set up and execute add
			j = 0;
			k = 15;
			Logger::WriteMessage("?");
			// Execute operation: add
			s1.add(j, k);
			Logger::WriteMessage("after ADD");
			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT05AddV1

		TEST_METHOD(UT05AddV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT05AddV2: s1.add(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <15> and j = 0 and k = 25");
			Logger::WriteMessage(L"\toutgoing: s1 = <25,15> and j = 0 and k = 0");

			// Test set up
			j = 0;
			k = 15;
			s1.add(j, k);

			// Execute operation: add
			k = 25;
			s1.add(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT05AddV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Execute operation: remove
			s1.remove(j, k);

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT06RemoveV1

		TEST_METHOD(UT06RemoveV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT06RemoveV2: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4 and k = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77> and j = 4 and k = 99");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: remove
			j = 4;
			s1.remove(j, k);

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT06RemoveV2

		  // -----------------------------------------------------------------------------------
		  // replaceEntry
		  // -----------------------------------------------------------------------------------
		  //! updates self, x
		  //! restores pos
		  //! requires: 0 <= pos < |self|
		  //! ensures: <x> = #self[pos, pos+1)  and
		  //!          self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT07ReplaceEntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT07ReplaceEntryV1: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0 and k = 8");
			Logger::WriteMessage(L"\toutgoing: s1 = <8> and j = 0 and k = 77");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Execute operation: replaceEntry
			k = 8;
			s1.replaceEntry(j, k);

			// Verify ensures: self = #self[0, pos) * <#x> * #self[pos+1, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT07ReplaceEntryV1

		TEST_METHOD(UT07ReplaceEntryV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT07ReplaceEntryV2: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4 and k = 8");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77,8> and j = 4 and k = 99");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: replaceEntry
			j = 4;
			k = 8;
			s1.replaceEntry(j, k);

			// Verify ensures: self = #self[0, pos) * #self[pos+1, |#self|)
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT07ReplaceEntryV2

		  // -----------------------------------------------------------------------------------
		  // entry
		  // -----------------------------------------------------------------------------------
		  //! restores self, pos
		  //! requires: 0 <= pos < |self|
		  //! ensures: <entry> = self[pos, pos+1)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT08EntryV1)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT08EntryV1: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <77> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <77> and j = 0");

			// Test set up
			j = 0;
			k = 77;
			s1.add(j, k);

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT08EntryV1

		TEST_METHOD(UT08EntryV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer j, k;

			Logger::WriteMessage(L"UT08EntryV2: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and j = 4");
			Logger::WriteMessage(L"\toutgoing: s1 = <11,33,55,77,99> and j = 4");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT08EntryV2

		  // -----------------------------------------------------------------------------------
		  // append
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! clears sToAppend
		  //! ensures: self = #self * sToAppend
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT09AppendV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;

			Logger::WriteMessage(L"UT09AppendV1: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <>");

			// Execute operation: append
			s1.append(s2);

			// Verify ensures: self = #self * sToAppend
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify clears parameter mode: clears sToAppend
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT09AppendV1

		TEST_METHOD(UT09AppendV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer k;

			Logger::WriteMessage(L"UT09AppendV2: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing: s1 = <44> and s2 = <>");

			// Test set up
			k = 44;
			s2.add(0, k);

			// Execute operation: append
			s1.append(s2);

			// Verify ensures: self = #self * sToAppend
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify clears parameter mode: clears sToAppend
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT09AppendV2

		  // -----------------------------------------------------------------------------------
		  // split
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! restores pos
		  //! replaces receivingS
		  //! requires: 0 <= pos <= |self|
		  //! ensures: self = #self[0, pos) and receivingS = #self[pos, |self|)
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT10SplitV1)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer j;

			Logger::WriteMessage(L"UT10SplitV1: s1.split(j, s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <> and j = 0");

			// Execute operation: split
			s1.split(j, s2);

			// Verify ensures: self = #self[0, pos)
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify ensures: receivingS = #self[pos, |self|)
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT10SplitV1

		TEST_METHOD(UT10SplitV2)
		{
			IntegerSequence s1, s2;
			Text x1, x2;
			Integer j, k;

			Logger::WriteMessage(L"UT10SplitV2: s1.split(j, s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <11,33,55,77,99> and s2 = <> and j = 0");
			Logger::WriteMessage(L"\toutgoing: s1 = <> and s2 = <11,33,55,77,99> and j = 0");

			// Test set up
			j = 0;
			k = 99;
			s1.add(j, k);
			k = 77;
			s1.add(j, k);
			k = 55;
			s1.add(j, k);
			k = 33;
			s1.add(j, k);
			k = 11;
			s1.add(j, k);

			// Execute operation: split
			s1.split(j, s2);

			// Verify ensures: self = #self[0, pos)
			toText(s1, x1);
			Logger::WriteMessage(x1);

			// Verify ensures: receivingS = #self[pos, |self|)
			toText(s2, x2);
			Logger::WriteMessage(x2);
		} // UT10SplitV2

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
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT11LengthV1

		TEST_METHOD(UT11LengthV2)
		{
			IntegerSequence s1;
			Text x1;
			Integer k;

			Logger::WriteMessage(L"UT11LengthV2: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <95>");
			Logger::WriteMessage(L"\toutgoing: s1 = <95>");

			// Test set up
			k = 95;
			s1.add(0, k);

			// Verify restores parameter mode: restores self
			toText(s1, x1);
			Logger::WriteMessage(x1);
		} // UT11LengthV2

#endif
	};
}