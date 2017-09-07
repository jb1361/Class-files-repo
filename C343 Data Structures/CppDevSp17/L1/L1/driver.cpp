#include "Wrapper.h"
#include "createInstance.h"


void loadRandomIntoSequence(IntegerSequence& s, Integer numberToLoad)
//! replaces s
//! restores numberToLoad
//! requires: numberToLoad >= 0
//! ensures: |s| = numberToLoad and s contains integers generated from rand() function
{
	for (int k = 0; k < numberToLoad; k++) {
		Integer y = rand() % 1000;
		s.add(0, y);
	} // end for
} // loadRandomIntoSequence



//-------------------------------------------------------------------

 
void displaySequence(IntegerSequence& s)
//! restores s
//! ensures: contents of s are displayed, separated by commas
{
	IntegerSequence sTemp;

	wcout << "<";
	for (int k = 0, z = s.length(); k < z; k++) {
		Integer y;

		s.remove(0, y);
		wcout << y;
		if (s.length() > 0) {
			wcout << ",";
		} // end if
		sTemp.add(sTemp.length(), y);
	} // end for
	wcout << ">";
	s.transferFrom(sTemp);
} // displaySequence



//-------------------------------------------------------------------



void moveLargestToFront(IntegerSequence& s)
//! updates s
//! requires: |s| > 0
//! ensures: the largest value found in s is moved to position zero and
//!          perms(#s, s)
{
	Integer temp;
	s.remove(0, temp);
	Integer previous = temp;
	s.add(0, temp);
	Integer lowest_position = 0;
	for (int i = 0; i < s.length(); i++) {
		Integer next;
		s.remove(s.length()-1, next);
		if (next > previous) {
			lowest_position = 0;
			previous = next;
		}
		else lowest_position++;
		s.add(0, next);
	}//for loop
	
	Integer low;
	s.remove(lowest_position, low);
	s.add(0, low);

} // moveLargestToFront

  //-------------------------------------------------------------------

void reverse(IntegerSequence& s)
//! updates s
//! ensures: s = rev(#s)
{
	int low = 0;
	int high = s.length()-1;
	
	Integer l;
	Integer h;
	for (int i = 0; i < s.length(); i++)
	{
		
		if (low > high) break;
		if (low != high) {
			s.remove(high, h);
			s.remove(low, l);
			s.add(low, h);
			s.add(high, l);
		}
		low++;
		high--;
	}
} // reverse



//-------------------------------------------------------------------
// main executable body
//-------------------------------------------------------------------

int main(int argc, char* argv[])
{
	// Do not change the next 5 lines
	Integer numToLoad = 7;
	if (argc > 1) {
		// obtain from the command line the number of integers to load
		numToLoad = atoi(argv[1]);
	} // end if

	IntegerSequence s1, s2;

	wcout << "s1 = " << s1 << endl;
	loadRandomIntoSequence(s1, numToLoad);
	wcout << "s1 = " << s1 << " after loading " << numToLoad << " items into s1" << endl << endl;

	wcout << "Display s1 using displaySequence: ";
	displaySequence(s1);
	wcout << endl << endl;
	
	wcout << "s1 = " << s1 << " before moving largest to the front" << endl;
	moveLargestToFront(s1);
	wcout << "s1 = " << s1 << " with largest at the front" << endl << endl;
	
	wcout << "s1 = " << s1 << " before reversing the order" << endl;
	reverse(s1);
	wcout << "s1 = " << s1 << " with items in reverse order" << endl << endl;

	system("pause");
	return 0;
}	// end main

