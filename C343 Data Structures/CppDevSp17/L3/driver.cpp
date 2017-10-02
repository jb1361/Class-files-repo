// File: DRIVER.CPP
// Client of Sorting Machine
// Date: 2/17

#include "wrapper.h"
#include "IntegerSequence.h"
#include "IntegerSorter.h"

void loadData(IntegerSequence& s) {
	for (int k = 0; k <= 50; k++) {
		Integer y = rand() % 10000;
		s.add(0, y);
	} // loadData
}
  //------------------------------------------------------------

void sortData(IntegerSequence& s) {
	IntegerSorter integerSorter;

	for (int k = 0, z = s.length(); k < z; k++) {
		IntegerSequence r;

		s.remove(0, r);
		integerSorter.add(r);
	} // end for

	integerSorter.changeToExtractionMode();

	for (int k = 0, z = integerSorter.size(); k < z; k++) {
		IntegerSequence r;

		integerSorter.removeFirst(r);
		s.add(s.length(), r);
	} // end for
} // sortData

  //------------------------------------------------------------

int main(int argc, char* argv[])
{
	IntegerSequence eSequence;

	loadData(eSequence);
	wcout << "Unsorted integers" << endl;
	wcout << eSequence << endl;

	sortData(eSequence);

	// Now do something with sorted data in eSequence
	wcout << "Sorted integers" << endl;
	wcout << eSequence << endl;

	system("pause");

	return 0;
} // main    