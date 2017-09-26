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