#include "stdafx.h"
#include "CppUnitTest.h"
#include "Wrapper.h"
#include "TextToIntegerMap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace L4Sol
{
	TEST_CLASS(UnitTest1)
	{

	public:

		TEST_METHOD(UT01ConstructorV1)
		{
			TextToIntegerMap m1;
			Text x1;

			Logger::WriteMessage(L"UT01ConstructorV1: Map1();");
			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>])");

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
			Assert::IsTrue(x1 == "(0,[<>,<>,<>,<>,<>])", L"m1 = (0,[<>,<>,<>,<>,<>])");
		} // UT01ConstructorV1

		TEST_METHOD(UT02ClearV1)
		{
			TextToIntegerMap m1;
			Text x1;

			Logger::WriteMessage(L"UT02ClearV1: m1.clear();");
			Logger::WriteMessage(L"\tincoming: m1 = (0,[<>,<>,<>,<>,<>])");
			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>])");

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
			Assert::IsTrue(x1 == "(0,[<>,<>,<>,<>,<>])", L"m1 = (0,[<>,<>,<>,<>,<>])");
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
			Logger::WriteMessage(L"\tincoming: m1 = (0,[<>,<>,<>,<>,<>]) and m2 = (1,[<(\"UIO\",7874)>,<>,<>,<>,<>])");
			Logger::WriteMessage(L"\toutgoing: m1 = (1,[<(\"UIO\",7874)>,<>,<>,<>,<>]) and m2 = (0,[<>,<>,<>,<>,<>])");

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
			Assert::IsTrue(x1 == "(1,[<(\"UIO\",7874)>,<>,<>,<>,<>])", L"m1 = (1,[<(\"UIO\",7874)>,<>,<>,<>,<>])");

			// Verify clears parameter mode: clears source
			Assert::IsTrue(x2 == "(0,[<>,<>,<>,<>,<>])", L"m2 = (0,[<>,<>,<>,<>,<>])");
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
			Logger::WriteMessage(L"\tincoming: m1 = (1,[<>,<>,<(\"MAD\",2001)>,<>,<>]) and m2 = (0,[<>,<>,<>,<>,<>])");
			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>]) and m2 = (0,[<>,<>,<>,<>,<>])");

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
			Assert::IsTrue(x2 == "(0,[<>,<>,<>,<>,<>])", L"m2 = (0,[<>,<>,<>,<>,<>])");
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
			Logger::WriteMessage(L"\tincoming: m1 = (0,[<>,<>,<>,<>,<>])");
			Logger::WriteMessage(L"\tincoming: key = \"SDF\"");
			Logger::WriteMessage(L"\tincoming: value = 501");

			Logger::WriteMessage(L"\toutgoing: m1 = (1,[<>,<>,<>,<(\"SDF\",501)>,<>])");
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
				x1 == "(1,[<>,<>,<>,<(\"SDF\",501)>,<>])",
				L"m1 = (1,[<>,<>,<>,<(\"SDF\",501)>,<>])");

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
			Logger::WriteMessage(L"\tincoming: m1 = (1,[<>,<>,<>,<>,<(\"ORD\",668)>])");
			Logger::WriteMessage(L"\tincoming: key = \"ORD\"");
			Logger::WriteMessage(L"\tincoming: keyFromMap = \"\"");
			Logger::WriteMessage(L"\tincoming: valueFromMap = 0");

			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>])");
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
				x1 == "(0,[<>,<>,<>,<>,<>])",
				L"m1 = (0,[<>,<>,<>,<>,<>])");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k1 == "ORD", L"key = \"ORD\"");

			// Verify ensures: keyFromMap = "ORD"
			Assert::IsTrue(k2 == "ORD", L"keyFromMap = \"ORD\"");

			// Verify ensures: valueFromMap = 668
			Assert::IsTrue(v == 668, L"valueFromMap = 668");
		} // UT06RemoveV1

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
			Logger::WriteMessage(L"\tincoming: m1 = (2,[<>,<>,<>,<>,<(\"ORL\",82),(\"ORD\",668)>])");

			Logger::WriteMessage(L"\toutgoing: m1 = (2,[<>,<>,<>,<>,<(\"ORD\",668),(\"ORL\",82)>])");


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
				x1 == "(2,[<>,<>,<>,<>,<(\"ORD\",668),(\"ORL\",82)>])",
				L"m1 = (2,[<>,<>,<>,<>,<(\"ORD\",668),(\"ORL\",82)>])");

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
			Logger::WriteMessage(L"\tincoming: m1 = (1,[<>,<(\"LAX\",125)>,<>,<>,<>])");
			Logger::WriteMessage(L"\tincoming: key = \"\"");
			Logger::WriteMessage(L"\tincoming: value = 0");


			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>])");
			Logger::WriteMessage(L"\toutgoing: key = \"LAX\"");
			Logger::WriteMessage(L"\toutgoing: value = 125");

			// Test set up
			// Airport: LAX   Altitude: 125
			k = "LAX";
			v = 125;
			m1.add(k, v);

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
				x1 == "(0,[<>,<>,<>,<>,<>])",
				L"m1 = (0,[<>,<>,<>,<>,<>])");

			// Verify restores parameter mode: restores k1
			Assert::IsTrue(k == "LAX", L"key = \"LAX\"");

			// Verify ensures: valueFromMap = 125
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
			Logger::WriteMessage(L"\tincoming: m1 = (0,[<>,<>,<>,<>,<>])");

			Logger::WriteMessage(L"\toutgoing: m1 = (0,[<>,<>,<>,<>,<>])");

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
				x1 == "(0,[<>,<>,<>,<>,<>])",
				L"m1 = (0,[<>,<>,<>,<>,<>])");

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
			Logger::WriteMessage(L"\tincoming: m1 = (5,[<(\"UIO\",7874)>,<(\"LIM\",112)>,<(\"CUZ\",10860)>,<(\"DEN\",5430),(\"SDF\",501)>,<>])");
			Logger::WriteMessage(L"\toutgoing: m1 = (5,[<(\"UIO\",7874)>,<(\"LIM\",112)>,<(\"CUZ\",10860)>,<(\"DEN\",5430),(\"SDF\",501)>,<>])");


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
				"(5,[<(\"UIO\",7874)>,<(\"LIM\",112)>,<(\"CUZ\",10860)>,<(\"DEN\",5430),(\"SDF\",501)>,<>])", 
				L"m1 = (5,[<(\"UIO\",7874)>,<(\"LIM\",112)>,<(\"CUZ\",10860)>,<(\"DEN\",5430),(\"SDF\",501)>,<>])");
		} // UT09SizeV2

	};
}


