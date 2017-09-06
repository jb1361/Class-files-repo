#include "Wrapper.h"
#include "createInstance.h"

/*
TODO #1:
	1) Build this project - if you have followed the instructions for creating a new project 
	   correctly, then it will build and run
	2.1) If the build fails, then delete the project's folder CppDevSp17\L1 and 
	     then recreate the project from scratch, i.e., try again
	2.3) When the build is successful, open up the file createInstance.h and do TODO #2
*/

//-------------------------------------------------------------------

void loadRandomIntoQueue(IntegerQueue& q, Integer numberToLoad)
//! replaces q
//! restores numberToLoad
//! requires: numberToLoad >= 0
//! ensures: |q| = numberToLoad and q contains integers generated from rand() function
{
	for (int k = 0; k < numberToLoad; k++) {
		Integer y = rand() % 1000;
		q.enqueue(y);
	} // end for
} // loadRandomIntoQueue

  /*
  TODO #4:
	  1) Copy and paste the entire loadRandomIntoQueue operation that is just above this comment,
		 put the copied operation just below this comment 
	  2) Change the name of the copied version to loadRandomIntoSequence
	  3) Change loadRandomIntoSequence as outlined in the following steps: 4 - 7
	  4) Change loadRandomIntoSequence's 1st formal parameter so that it is an IntegerSequence
	  5) Change the first formal parameter's name to s
	  6) Change all comments that refernce q so that they reference s instead
	  7) Change the for loop so that it adds the integers to s at location zero each time through loop
	  8) Rebuild - there should be no compiler errors
	  9) Navigate back down to the main operation and do TODO #5
  */

//-------------------------------------------------------------------

void displayQueue(IntegerQueue& q)
//! restores q
//! ensures: contents of q are displayed, separated by commas
{
	IntegerQueue qTemp;

	wcout << "<";
	for (int k = 0, z = q.length(); k < z; k++) {
		Integer y;

		q.dequeue(y);
		wcout << y;
		if (q.length() > 0) {
			wcout << ",";
		} // end if
		qTemp.enqueue(y);
	} // end for
	wcout << ">";
	q.transferFrom(qTemp);
} // displayQueue

  /*
  TODO #6:
	  1) Copy and paste the entire displayQueue operation that is just above this comment,
	     put the copied operation just below this comment
	  2) Change the name of the copied version to displaySequence
	  3) Change displaySequence as outlined in the following steps: 4 - 9
	  4) Change displaySequence's formal parameter so that it is an IntegerSequence
	  5) Change the formal parameter's name to s
	  6) Change all comments that refernce q so that they reference s instead
	  7) Change local variable qTemp to sTemp and change its type to IntegerSequence
	  8) Remove items from s at position zero
	  9) Add the removed items to sTemp so that the order of items is not changed
	  10) Rebuild - there should be no compiler errors
	  11) Navigate back down to main and do TODO #7
  */

//-------------------------------------------------------------------

  /*
   TODO #8:
       1) Uncomment the moveLargestToFront and reverse operations that are below	      
	   2) Implement moveLargestToFront and reverse
	   3) Rebuild the project and edit these operations until all compiler errors are eliminated
	   4) Navigate back down to main and do TODO #9
  */

/*
void moveLargestToFront(IntegerSequence& s)
//! updates s
//! requires: |s| > 0
//! ensures: the largest value found in s is moved to position zero and
//!          perms(#s, s)
{
	// Insert implementation code here
} // moveLargestToFront

  //-------------------------------------------------------------------

void reverse(IntegerSequence& s)
//! updates s
//! ensures: s = rev(#s)
{
	// Insert implementation code here
} // reverse

*/

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

	/*
	TODO #3:
		1) Just after the following declaration of q1 and q2,
		   declare IntegerSequences s1 and s2
		2) Rebuild - there should be no compiler errors
		3) Navigate upward to TODO #4
	*/
	IntegerQueue q1, q2;


	wcout << "q1 = " << q1 << endl;
	loadRandomIntoQueue(q1, numToLoad);
	wcout << "q1 = " << q1 << " after loading " << numToLoad << " items into q1" << endl << endl;
	/*
	TODO #5:
		1) Copy and paste the 3 lines of code just above this comment, put the copy just below the comment
		2) Modify the copied lines so that all 3 utilize loadRandomIntoSequence and s1
		3) Rebuild - there should be no compiler errors
		4) Run your program - you should see Sequence s1 displayed similar to how Queue q1 is displayed
		5) Navigate upward to TODO #6
	*/




	wcout << "Display q1 using displayQueue: ";
	displayQueue(q1);
	wcout << endl << endl;
	/*
	TODO #7:
		1) Copy and paste the 3 lines of code just above this comment, put the copy just below the comment
		2) Modify the copied lines so that they utilize displaySequence and s1
		3) Rebuild - there should be no compiler errors
		4) Run your program - you should see Sequence s1 displayed similar to how Queue q1 is displayed
		5) Navigate upward to TODO #8
	*/





	/*
	TODO #9:
	    1) Uncomment the 2 lines of code found just inside the bottom of this comment
		2) Insert a line of code between the two wcout lines of code 
		   This new line should make a call to moveLargestToFront passing s1 as the actual parameter
	    3) Rebuild and edit until all compiler errors are eliminated
		4) Run your program - you should see Sequence s1 displayed both before and after the
		   largest item has been moved to the front
		5) Navigate downward to TODO #10
	

	wcout << "s1 = " << s1 << " before moving largest to the front" << endl;
	wcout << "s1 = " << s1 << " with largest at the front" << endl << endl;
	*/



	/*
	TODO #10:
		1) Copy and paste the 3 lines of code that you ended up with by doing "TODO #9" 
		2) Change the procedure call to in the middle line so that a call is made to operation reverse
	    3) Rebuild and edit until all compiler errors are eliminated
		4) Run your program - you should see Sequence s1 displayed in reverse order
		5) Navigate downward to TODO #11
	*/



	system("pause");
	return 0;
}	// end main




	/*
	TODO #11:
		1) Eliminate from this file all "TODO" comments
		2) Rebuild and run - there should be no compiler errors
		3) Eliminate from this file all lines that have to do with Queue
		4) Rebuild and run - there should be no compiler errors
		5) Your output should now look similar to the output from L1Sol.exe except
		   that the random integers might be different
		6) Go back to the file createInstance.h and do TODO #12
	*/