#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "TextToIntegerMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L6
{
	TEST_CLASS(UnitTest1)
	{

	public:

		TEST_METHOD(UT01ConstructorV1)
		{
			TextToIntegerMap m1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Map1();");
			Logger::WriteMessage(L"\toutgoing: m1 = E");

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			// Verify ensures: self = {}
			Assert::IsTrue(x1 == "E", L"m1 = E");
		} // UT01ConstructorV1

		  // -----------------------------------------------------------------------------------
		  // clear
		  // -----------------------------------------------------------------------------------
		  //! clears self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT02ClearV1)
		{
			TextToIntegerMap m1;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV1: m1.clear();");
			Logger::WriteMessage(L"\tincoming: m1 = E");
			Logger::WriteMessage(L"\toutgoing: m1 = E");

			// Execute operation: clear
			m1.clear();

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			// Verify parameter mode clears: clears self
			Assert::IsTrue(x1 == "E", L"m1 = E");
		} // UT02ClearV1

		  // -----------------------------------------------------------------------------------
		  // transferFrom
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! restores rhs
		  //! ensures: self = #source
		  // -----------------------------------------------------------------------------------
		
		TEST_METHOD(UT03TransferFromV3)
		{
			TextToIntegerMap m1, m2;
			Text x1, x2;
			Text k;
			Integer v;

			Logger::WriteMessage(L"UT03TransferFromV3: m1.transferFrom(m2);");
			Logger::WriteMessage(L"\tincoming: m1 = E and m2 = (E,\"UIO\",E)");
			Logger::WriteMessage(L"\toutgoing: m1 = (E,\"UIO\",E) and m2 = E");

			// Test set up
			// Airport: UIO   Altitude: 7874
			k = "UIO";
			v = 7874;
			m2.add(k, v);

			// Execute operation: transferFrom
			m1.transferFrom(m2);

			toText(m1, x1);
			toText(m2, x2);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);

				outputMsg = "m2 = ";
				outputMsg.append(x2);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #source
			Assert::IsTrue(x1 == "(E,\"UIO\",E)", L"m1 = (E,\"UIO\",E)");

			// Verify clears parameter mode: clears source
			Assert::IsTrue(x2 == "E", L"m2 = E");
		} // UT03TransferFromV3

		  // -----------------------------------------------------------------------------------
		  // operator =
		  // -----------------------------------------------------------------------------------
		  //! replaces self
		  //! restores rhs
		  //! ensures: self = rhs
		  // -----------------------------------------------------------------------------------
		
		TEST_METHOD(UT04AssignmentV2)
		{
			TextToIntegerMap m1, m2;
			Text x1, x2;
			Text k;
			Integer v;

			Logger::WriteMessage(L"UT04AssignmentV2: m1 = m2;");
			Logger::WriteMessage(L"\tincoming: m1 = (E,\"MAD\",E) and m2 = E");
			Logger::WriteMessage(L"\toutgoing: m1 = E and m2 = E");

			// Test set up
			// Airport: MAD   Altitude: 2001
			k = "MAD";
			v = 2001;
			m1.add(k, v);

			// Execute operation: operator =
			m1 = m2;

			toText(m1, x1);
			toText(m2, x2);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);

				outputMsg = "m2 = ";
				outputMsg.append(x2);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			// Verify ensures: self = rhs
			Assert::IsTrue(x1 == x2, L"m1 = m2");

			// Verify restores parameter mode: restores rhs
			Assert::IsTrue(x2 == "E", L"m2 = E");
		} // UT04AssignmentV2
		TEST_METHOD(UT04AssignmentV3)
		{
			TextToIntegerMap m1, m2;
			Text x1, x2;
			Text k;
			Integer v;

			Logger::WriteMessage(L"UT04AssignmentV2: m1 = m2;");
			Logger::WriteMessage(L"\tincoming: m1 = E and m2 = (E,\"MAD\",E)");
			Logger::WriteMessage(L"\toutgoing: m1 = (E,\"MAD\",E) and m2 = (E,\"MAD\",E)");

			// Test set up
			// Airport: MAD   Altitude: 2001
			k = "MAD";
			v = 2001;
			m2.add(k, v);

			// Execute operation: operator =
			m1 = m2;

			toText(m1, x1);
			toText(m2, x2);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);

				outputMsg = "m2 = ";
				outputMsg.append(x2);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = rhs
			Assert::IsTrue(x1 == x2, L"m1 = m2");

			// Verify restores parameter mode: restores rhs
			//Assert::IsTrue(x2 == x1, L"m2 = E");
		} // UT04AssignmentV2
		  // -----------------------------------------------------------------------------------
		  // add
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! clears key, value
		  //! requires: key not in DOMAIN(self)
		  //! ensures: self = #self union {(#key, #value)}
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT05AddV1)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k;
			Integer v;

			Logger::WriteMessage(L"UT05AddV1: m1.add(key, value);");
			Logger::WriteMessage(L"\tincoming: m1 = E");
			Logger::WriteMessage(L"\tincoming: key = \"SDF\"");
			Logger::WriteMessage(L"\tincoming: value = 501");

			Logger::WriteMessage(L"\toutgoing: m1 = (E,\"SDF\",E)");
			Logger::WriteMessage(L"\toutgoing: key = \"\"");
			Logger::WriteMessage(L"\toutgoing: value = 0");

			// Test set up
			// Airport: SDF   Altitude: 501
			k = "SDF";
			v = 501;

			// Execute operation: add
			m1.add(k, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");


			} // End Extra Debugging Output Section

			// Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "(E,\"SDF\",E)",
				L"m1 = (E,\"SDF\",E)");

			// Verify clears parameter mode: clears k
			Assert::IsTrue(k == "", L"key = \"\"");

			// Verify clears parameter mode: clears v
			Assert::IsTrue(v == 0, L"value = 0");
		} // UT05AddV1

		  // -----------------------------------------------------------------------------------
		  // remove
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! restores key
		  //! replaces keyFromMap, valueFromMap
		  //! requires: key is in DOMAIN(self)
		  //! ensures: (key, valueFromMap) is in #self  and
		  //!           self = #self \ {(keyFromMap, valueFromMap)}  and  keyFromMap = key
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT06RemoveV1)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT06RemoveV1: m1.remove(key, keyFromMap, valueFromMap);");
			Logger::WriteMessage(L"\tincoming: m1 = (E,\"ORD\",E)");
			Logger::WriteMessage(L"\tincoming: key = \"ORD\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = E");
			Logger::WriteMessage(L"\toutgoing: key = \"ORD\"");
			Logger::WriteMessage(L"\toutgoing: keyFromMap = \"ORD");
			Logger::WriteMessage(L"\toutgoing: valueFromMap = 668");

			// Test set up
			// Airport: ORD   Altitude: 668
			k1 = "ORD";
			v = 668;
			m1.add(k1, v);

			// Execute operation: remove

			k1 = "ORD";
			m1.remove(k1, k2, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "E",
				L"m1 = E");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "ORD", L"key = \"ORD\"");

			// Verify ensures: keyFromMap = "ORD"
			Assert::IsTrue(k2 == "ORD", L"keyFromMap = \"ORD\"");

			// Verify ensures: valueFromMap = 668
			Assert::IsTrue(v == 668, L"valueFromMap = 668");
		} // UT06RemoveV1

		TEST_METHOD(UT06RemoveV2)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT06RemoveV2: m1.remove(key, keyFromMap, valueFromMap);");
			Logger::WriteMessage(L"\tincoming: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\tincoming: key = \"LIM\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",(E,\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\toutgoing: key = \"LIM\"");
			Logger::WriteMessage(L"\toutgoing: keyFromMap = \"LIM");
			Logger::WriteMessage(L"\toutgoing: valueFromMap = 112");

			// Test set up
			// Airport: DEN   Altitude: 5430
			k1 = "DEN";
			v = 5430;
			m1.add(k1, v);

			// Airport: SDF   Altitude: 501
			k1 = "SDF";
			v = 501;
			m1.add(k1, v);

			// Airport: UIO   Altitude: 7874
			k1 = "UIO";
			v = 7874;
			m1.add(k1, v);

			// Airport: LIM   Altitude: 112
			k1 = "LIM";
			v = 112;
			m1.add(k1, v);

			// Airport: CDG   Altitude: 390
			k1 = "CDG";
			v = 390;
			m1.add(k1, v);

			// Airport: CUZ   Altitude: 10860
			k1 = "CUZ";
			v = 10860;
			m1.add(k1, v);

			// Airport: CLE   Altitude: 791
			k1 = "CLE";
			v = 791;
			m1.add(k1, v);

			// Airport: TIJ   Altitude: 489
			k1 = "TIJ";
			v = 489;
			m1.add(k1, v);

			// Execute operation: remove

			k1 = "LIM";
			m1.remove(k1, k2, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",(E,\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))",
				L"m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",(E,\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "LIM", L"key = \"LIM\"");

			// Verify ensures: keyFromMap = "LIM"
			Assert::IsTrue(k2 == "LIM", L"keyFromMap = \"LIM\"");

			// Verify ensures: valueFromMap = 112
			Assert::IsTrue(v == 112, L"valueFromMap = 112");
		} // UT06RemoveV2

		TEST_METHOD(UT06RemoveV3)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT06RemoveV3: m1.remove(key, keyFromMap, valueFromMap);");
			Logger::WriteMessage(L"\tincoming: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\tincoming: key = \"CDG\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = (((E,\"CLE\",E),\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\toutgoing: key = \"CDG\"");
			Logger::WriteMessage(L"\toutgoing: keyFromMap = \"CDG");
			Logger::WriteMessage(L"\toutgoing: valueFromMap = 390");

			// Test set up
			// Airport: DEN   Altitude: 5430
			k1 = "DEN";
			v = 5430;
			m1.add(k1, v);

			// Airport: SDF   Altitude: 501
			k1 = "SDF";
			v = 501;
			m1.add(k1, v);

			// Airport: UIO   Altitude: 7874
			k1 = "UIO";
			v = 7874;
			m1.add(k1, v);

			// Airport: LIM   Altitude: 112
			k1 = "LIM";
			v = 112;
			m1.add(k1, v);

			// Airport: CDG   Altitude: 390
			k1 = "CDG";
			v = 390;
			m1.add(k1, v);

			// Airport: CUZ   Altitude: 10860
			k1 = "CUZ";
			v = 10860;
			m1.add(k1, v);

			// Airport: CLE   Altitude: 791
			k1 = "CLE";
			v = 791;
			m1.add(k1, v);

			// Airport: TIJ   Altitude: 489
			k1 = "TIJ";
			v = 489;
			m1.add(k1, v);

			// Execute operation: remove

			k1 = "CDG";
			m1.remove(k1, k2, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "(((E,\"CLE\",E),\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))",
				L"m1 = (((E,\"CLE\",E),\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "CDG", L"key = \"CDG\"");

			// Verify ensures: keyFromMap = "CDG"
			Assert::IsTrue(k2 == "CDG", L"keyFromMap = \"CDG\"");

			// Verify ensures: valueFromMap = 390
			Assert::IsTrue(v == 390, L"valueFromMap = 390");
		} // UT06RemoveV3

		TEST_METHOD(UT06RemoveV4)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT06RemoveV4: m1.remove(key, keyFromMap, valueFromMap);");
			Logger::WriteMessage(L"\tincoming: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\tincoming: key = \"UIO\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"TIJ\",E)))");
			Logger::WriteMessage(L"\toutgoing: key = \"UIO\"");
			Logger::WriteMessage(L"\toutgoing: keyFromMap = \"UIO");
			Logger::WriteMessage(L"\toutgoing: valueFromMap = 7874");

			// Test set up
			// Airport: DEN   Altitude: 5430
			k1 = "DEN";
			v = 5430;
			m1.add(k1, v);

			// Airport: SDF   Altitude: 501
			k1 = "SDF";
			v = 501;
			m1.add(k1, v);

			// Airport: UIO   Altitude: 7874
			k1 = "UIO";
			v = 7874;
			m1.add(k1, v);

			// Airport: LIM   Altitude: 112
			k1 = "LIM";
			v = 112;
			m1.add(k1, v);

			// Airport: CDG   Altitude: 390
			k1 = "CDG";
			v = 390;
			m1.add(k1, v);

			// Airport: CUZ   Altitude: 10860
			k1 = "CUZ";
			v = 10860;
			m1.add(k1, v);

			// Airport: CLE   Altitude: 791
			k1 = "CLE";
			v = 791;
			m1.add(k1, v);

			// Airport: TIJ   Altitude: 489
			k1 = "TIJ";
			v = 489;
			m1.add(k1, v);

			// Execute operation: remove

			k1 = "UIO";
			m1.remove(k1, k2, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"TIJ\",E)))",
				L"m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"TIJ\",E)))");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "UIO", L"key = \"UIO\"");

			// Verify ensures: keyFromMap = "UIO"
			Assert::IsTrue(k2 == "UIO", L"keyFromMap = \"UIO\"");

			// Verify ensures: valueFromMap = 7874
			Assert::IsTrue(v == 7874, L"valueFromMap = 7874");
		} // UT06RemoveV4

		TEST_METHOD(UT06RemoveV5)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT06RemoveV5: m1.remove(key, keyFromMap, valueFromMap);");
			Logger::WriteMessage(L"\tincoming: m1 = ((E,\"CDG\",((E,\"CLE\",E),\"CUZ\",E)),\"DEN\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\tincoming: key = \"DEN\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = ((E,\"CDG\",(E,\"CLE\",E)),\"CUZ\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");
			Logger::WriteMessage(L"\toutgoing: key = \"DEN\"");
			Logger::WriteMessage(L"\toutgoing: keyFromMap = \"DEN");
			Logger::WriteMessage(L"\toutgoing: valueFromMap = 5430");

			// Test set up
			// Airport: DEN   Altitude: 5430
			k1 = "DEN";
			v = 5430;
			m1.add(k1, v);

			// Airport: SDF   Altitude: 501
			k1 = "SDF";
			v = 501;
			m1.add(k1, v);

			// Airport: UIO   Altitude: 7874
			k1 = "UIO";
			v = 7874;
			m1.add(k1, v);

			// Airport: LIM   Altitude: 112
			k1 = "LIM";
			v = 112;
			m1.add(k1, v);

			// Airport: CDG   Altitude: 390
			k1 = "CDG";
			v = 390;
			m1.add(k1, v);

			// Airport: CUZ   Altitude: 10860
			k1 = "CUZ";
			v = 10860;
			m1.add(k1, v);

			// Airport: CLE   Altitude: 791
			k1 = "CLE";
			v = 791;
			m1.add(k1, v);

			// Airport: TIJ   Altitude: 489
			k1 = "TIJ";
			v = 489;
			m1.add(k1, v);

			// Execute operation: remove

			k1 = "DEN";
			m1.remove(k1, k2, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "((E,\"CDG\",(E,\"CLE\",E)),\"CUZ\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))",
				L"m1 = ((E,\"CDG\",(E,\"CLE\",E)),\"CUZ\",((E,\"LIM\",E),\"SDF\",((E,\"TIJ\",E),\"UIO\",E)))");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "DEN", L"key = \"DEN\"");

			// Verify ensures: keyFromMap = "UIO"
			Assert::IsTrue(k2 == "DEN", L"keyFromMap = \"DEN\"");

			// Verify ensures: valueFromMap = 5430
			Assert::IsTrue(v == 5430, L"valueFromMap = 5430");
		} // UT06RemoveV5

		  // -----------------------------------------------------------------------------------
		  // value
		  // -----------------------------------------------------------------------------------
		  //! restores self, key
		  //! requires: key is in DOMAIN(self)
		  //! ensures: (key, value) is in self
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT07ValueV1)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k1, k2;
			Integer v;

			Logger::WriteMessage(L"UT07ValueV1: m1.value(key);");
			Logger::WriteMessage(L"\tincoming: m1 = (E,\"ORD\",(E,\"ORL\",E))");

			Logger::WriteMessage(L"\toutgoing: m1 = (E,\"ORD\",(E,\"ORL\",E))");


			// Test set up
			// Airport: ORD   Altitude: 668
			k1 = "ORD";
			v = 668;
			m1.add(k1, v);

			k1 = "ORL";
			// Airport: ORL   Altitude: 82
			v = 82;
			m1.add(k1, v);

			// Execute operation: value

			k1 = "ORD";

			Integer accessV = m1.value(k1);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify restores parameter mode: self 
			Assert::IsTrue(
				x1 == "(E,\"ORD\",(E,\"ORL\",E))",
				L"m1 = (E,\"ORD\",(E,\"ORL\",E))");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "ORD", L"key = \"ORD\"");

			// Verify ensures: value = 668
			Assert::IsTrue(accessV == 668, L"value = 668");
		} // UT07ValueV1


		  // -----------------------------------------------------------------------------------
		  // removeAny
		  // -----------------------------------------------------------------------------------
		  //! updates self
		  //! replaces key, value
		  //! requires: |self| > 0
		  //! ensures: (key, value) is in #self  and  self = #self \ {(key, value)}
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT08RemoveAnyV1)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k;
			Integer v;

			Logger::WriteMessage(L"UT08RemoveAnyV1: m1.removeAny(key, value);");
			Logger::WriteMessage(L"\tincoming: m1 = (E,\"LAX\",E)");
			Logger::WriteMessage(L"\tincoming: key = \"\"");
			Logger::WriteMessage(L"\tincoming: value = 0");


			Logger::WriteMessage(L"\toutgoing: m1 = E");
			Logger::WriteMessage(L"\toutgoing: key = \"LAX\"");
			Logger::WriteMessage(L"\toutgoing: value = 125");

			// Test set up
			// Airport: LAX   Altitude: 125
			k = "LAX";
			v = 125;
			m1.add(k, v);
			k = "LAX";
			v = 125;
			// Execute operation: removeAny

			m1.removeAny(k, v);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: self = #self union {(#key, #value)}
			Assert::IsTrue(
				x1 == "E",
				L"m1 = E");

			// Verify replaces parameter mode: replaces key
			Assert::IsTrue(k == "LAX", L"key = \"LAX\"");

			// Verify ensures: value = 125
			Assert::IsTrue(v == 125, L"value = 125");
		} // UT08RemoveAnyV1

		  // -----------------------------------------------------------------------------------
		  // hasKey
		  // -----------------------------------------------------------------------------------
		  //! restores self, key
		  //! ensures: hasKey = (key is in DOMAIN(self))
		  // -----------------------------------------------------------------------------------

		TEST_METHOD(UT08HasKeyV1)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k;
			Boolean inMap;

			Logger::WriteMessage(L"UT08HasKeyV1: m1.hashKey(key);");
			Logger::WriteMessage(L"\tincoming: m1 = E");

			Logger::WriteMessage(L"\toutgoing: m1 = E");

			// Test set up
			k = "LAX";

			// Execute operation: hasKey

			inMap = m1.hasKey(k);

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify restores parameter mode: self 
			Assert::IsTrue(
				x1 == "E",
				L"m1 = E");

			// Verify ensures: hasKey = false
			Assert::IsTrue(inMap == false, L"hasKey = false");
		} // UT08HasKeyV1

		  // -----------------------------------------------------------------------------------
		  // size
		  // -----------------------------------------------------------------------------------
		  //! restores self
		  //! ensures: size = |self|
		  // -----------------------------------------------------------------------------------
		
		TEST_METHOD(UT09SizeV2)
		{
			TextToIntegerMap m1;
			Text x1;
			Text k;
			Integer v;
			Integer z;

			Logger::WriteMessage(L"UT09SizeV1: m1.size();");
			Logger::WriteMessage(L"\tincoming: m1 = ((E,\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"UIO\",E)))");
			Logger::WriteMessage(L"\toutgoing: m1 = ((E,\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"UIO\",E)))");


			// Test set up
			// Airport: DEN   Altitude: 5430
			k = "DEN";
			v = 5430;
			m1.add(k, v);

			// Airport: SDF   Altitude: 501
			k = "SDF";
			v = 501;
			m1.add(k, v);

			// Airport: UIO   Altitude: 7874
			k = "UIO";
			v = 7874;
			m1.add(k, v);

			// Airport: LIM   Altitude: 112
			k = "LIM";
			v = 112;
			m1.add(k, v);

			// Airport: CUZ   Altitude: 10860
			k = "CUZ";
			v = 10860;
			m1.add(k, v);

			//((E,\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"UIO\",E)))

			// Execute operation: size

			z = m1.size();

			toText(m1, x1);

			{
				// Extra Debugging Output Section
				// Send debugging information to Visual Studio's Output window
				// Must do this before 1st call to Assert because a failed Assert stops execution of unit test
				// If Assert(s) below fail, use this output to see actual values of variables

				Logger::WriteMessage(L"*** Debugging Output Section:");

				Text outputMsg = "m1 = ";
				outputMsg.append(x1);
				Logger::WriteMessage(outputMsg);
				Logger::WriteMessage(L"*** End Debugging Output Section");
			} // End Extra Debugging Output Section

			  // Verify ensures: size = |self|
			Assert::IsTrue(z == 5, L"|m1| = 5");

			// Verify restores parameter mode: restores self
			Assert::IsTrue(x1 == 
				"((E,\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"UIO\",E)))", 
				L"m1 = ((E,\"CUZ\",E),\"DEN\",((E,\"LIM\",E),\"SDF\",(E,\"UIO\",E)))");
		} // UT09SizeV2

	};
}


