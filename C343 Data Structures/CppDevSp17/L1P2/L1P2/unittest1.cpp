#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "IntegerSequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L1P2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(UT01ConstructorV1) {
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Sequence1();");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Verify ensures: self = <>
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>");
		}
		TEST_METHOD(UT02ClearV1) {
			IntegerSequence s1;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			// Execute operation: clear
			s1.clear();

			// Verify parameter mode clears: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>");
		}
		TEST_METHOD(UT02ClearV2) {
			IntegerSequence s1;
			Text x1;
			
			Logger::WriteMessage(L"UT02ClearV1: s1.clear();");
			Logger::WriteMessage(L"\tincoming: s1 = <33>");
			Logger::WriteMessage(L"\toutgoing: s1 = <>");

			Integer i = 33;
			s1.add(0, i);
			// Execute operation: clear
			s1.clear();

			// Verify parameter mode clears: clears self
			toText(s1, x1);
			Assert::IsTrue(x1 == "<>");
		}
		TEST_METHOD(UT03TransferFromV2) {
			Logger::WriteMessage(L"UT03TransferFromV2: s1.transferFrom(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <44>");
			Logger::WriteMessage(L"\toutgoing : s1 = <44> and s2 = <>");
			Text x1;
			IntegerSequence s1;
			IntegerSequence s2;
			Integer i = 44;
			s2.add(0, i);	
			s1.transferFrom(s2);
			toText(s1, x1);
			Assert::IsTrue(x1 == "<44>");
			toText(s2, x1);
			Assert::IsTrue(x1 == "<>");
		}
		TEST_METHOD(UT04AssignmentV2) {
			Logger::WriteMessage(L"UT04AssignmentV2: s1 = s2;");
			Logger::WriteMessage(L"\tincoming: s1 = <> and s2 = <27>");
			Logger::WriteMessage(L"\toutgoing : s1 = <27> and s2 = <27>");
			Text x1;
			IntegerSequence s1;
			IntegerSequence s2;
			Integer i = 27;
			s2.add(0, i);

			s1 = s2;

			toText(s1, x1);
			Assert::IsTrue(x1 == "<27>");
			toText(s2, x1);
			Assert::IsTrue(x1 == "<27>");
		}
		TEST_METHOD(UT05AddV2) {
			Logger::WriteMessage(L"UT05AddV2: s1.add(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <15> and j = 0 and k = 25");
			Logger::WriteMessage(L"\toutgoing : s1 = <25, 15> and j = 0 and k = 0");

			IntegerSequence s1;
			int j = 0;
			Integer k = 25;
			Integer l = 15;

			s1.add(0, l);
			s1.add(j, k);

			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<25,15>");
			Assert::IsTrue(j == 0);
			Assert::IsTrue(k == 0);
		}
		TEST_METHOD(UT06RemoveV2) {
			Logger::WriteMessage(L"UT06RemoveV2: s1.remove(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11, 33, 55, 77, 99> and j = 4 and k = 0");
			Logger::WriteMessage(L"\toutgoing : s1 = <11, 33, 55, 77> and j = 4 and k = 99");
	
			IntegerSequence s1;
			int j = 4;
			Integer k;
			Integer l;
			l = 99;
			s1.add(0, l);
			l = 77;
			s1.add(0, l);
			l = 55;
			s1.add(0, l);
			l = 33;
			s1.add(0, l);
			l = 11;
			s1.add(0, l);

			s1.remove(j, k);
			
			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77>");
			Assert::IsTrue(j == 4);
			Assert::IsTrue(k == 99);
		}
		TEST_METHOD(UT07ReplaceEntryV3) {
			Logger::WriteMessage(L"UT07ReplaceEntryV3: s1.replaceEntry(j, k);");
			Logger::WriteMessage(L"\tincoming: s1 = <11, 33, 55, 77, 99> and j = 2 and k = 8");
			Logger::WriteMessage(L"\toutgoing : s1 = <11, 33, 8, 77, 99> and j = 2 and k = 55");
	
			IntegerSequence s1;
			int j = 2;
			Integer k = 8;
			Integer l;
			l = 99;
			s1.add(0, l);
			l = 77;
			s1.add(0, l);
			l = 55;
			s1.add(0, l);
			l = 33;
			s1.add(0, l);
			l = 11;
			s1.add(0, l);

			s1.replaceEntry(j, k);

			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,8,77,99>");
			Assert::IsTrue(j == 2);
			Assert::IsTrue(k == 55);
		}
		TEST_METHOD(UT08EntryV3) {
			Logger::WriteMessage(L"UT08EntryV3: s1.entry(j);");
			Logger::WriteMessage(L"\tincoming: s1 = <11, 33, 55, 77, 99> and j = 2");
			Logger::WriteMessage(L"\toutgoing : s1 = <11, 33, 55, 77, 99> and j = 2");
		
			IntegerSequence s1;
			int j = 2;
	
			Integer l;
			l = 99;
			s1.add(0, l);
			l = 77;
			s1.add(0, l);
			l = 55;
			s1.add(0, l);
			l = 33;
			s1.add(0, l);
			l = 11;
			s1.add(0, l);

			s1.entry(j);

			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,99>");
			Assert::IsTrue(j == 2);
			
		}
		TEST_METHOD(UT09AppendV4) {
			Logger::WriteMessage(L"UT09AppendV4: s1.append(s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <10> and s2 = <22>");
			Logger::WriteMessage(L"\toutgoing : s1 = <10, 22> and s2 = <>");
		
			IntegerSequence s1;
			IntegerSequence s2;
		

			Integer l;
			l = 10;
			s1.add(0, l);
			l = 22;
			s2.add(0,l);
			
			s1.append(s2);

			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<10,22>");
			toText(s2, x1);
			Assert::IsTrue(x1 == "<>");
		}
		TEST_METHOD(UT10SplitV3) {
			Logger::WriteMessage(L"UT10SplitV3: s1.split(j, s2);");
			Logger::WriteMessage(L"\tincoming: s1 = <11, 33, 55, 77, 99> and s2 = <> and j = 2");
			Logger::WriteMessage(L"\toutgoing : s1 = <11, 33> and s2 = <55, 77, 99> and j = 2");
		
			IntegerSequence s1;
			IntegerSequence s2;
			int j = 2;
			Integer l;
			l = 99;
			s1.add(0, l);
			l = 77;
			s1.add(0, l);
			l = 55;
			s1.add(0, l);
			l = 33;
			s1.add(0, l);
			l = 11;
			s1.add(0, l);


			s1.split(j, s2);

			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33>");
			toText(s2, x1);
			Assert::IsTrue(x1 == "<55,77,99>");
			Assert::IsTrue(j == 2);
		}
		TEST_METHOD(UT11LengthV3) {
			Logger::WriteMessage(L"UT11LengthV3: s1.length();");
			Logger::WriteMessage(L"\tincoming: s1 = <11, 33, 55, 77, 99>");
			Logger::WriteMessage(L"\toutgoing : s1 = <11, 33, 55, 77, 99>");
			IntegerSequence s1;

			Integer l;
			l = 99;
			s1.add(0, l);
			l = 77;
			s1.add(0, l);
			l = 55;
			s1.add(0, l);
			l = 33;
			s1.add(0, l);
			l = 11;
			s1.add(0, l);

			s1.length();
			Text x1;
			toText(s1, x1);
			Assert::IsTrue(x1 == "<11,33,55,77,99>");

			//I figured I might as well test that we get the correct length back
			int t;
			t = s1.length();
			Assert::IsTrue(t == 5);

		}


	};
}