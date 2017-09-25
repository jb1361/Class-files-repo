#include "Wrapper.h"
#include "Sequence\Sequence1.hpp"



typedef Sequence1<Integer> IntegerSequence;
IntegerSequence seq1, seq2;

void moveItemsFromS1ToS2(IntegerSequence& s1, IntegerSequence& s2);
//! updates s1
//! replaces s2
//! ensures: all odd integers in #s1 have been removed 
//!          and put into s2 in same order and
//!          the even integers remaining in s1 are in the 
//!          same order as they were in #s1


void moveItemsFromS1ToS2(IntegerSequence& s1, IntegerSequence& s2) {
	wcout << "s1 before moving: " << s1 << endl;
	wcout << "s2 before moving: " << s2<< endl;
	IntegerSequence temp;
	//wcout << s1.length();
	Integer k;
	for (int i = 0; i < s1.length(); i++)
	{

		if (s1.entry(i) == 0) {
			s1.remove(i, k);
			temp.add(temp.length(), k);
			i--;
		}else if (abs(s1.entry(i)) % 2 == 1) {
			s1.remove(i,k);
			temp.add(temp.length(), k);
			i--;
		}
		
	}
	s2 = temp;
	wcout << "s1 after moving: " << s1<< endl;
	wcout << "s2 after moving: " << s2 << endl;

}

int main(){
Integer t;
t = 47;
seq1.add(seq1.length(),t);
t = -10;
seq1.add(seq1.length(), t);
t = -9;
seq1.add(seq1.length(), t);
t = 57;
seq1.add(seq1.length(), t);
t = 67;
seq1.add(seq1.length(), t);
t = -8;
seq1.add(seq1.length(), t);
t = 0;
seq1.add(seq1.length(), t);
t = 18;
seq2.add(seq2.length(), t);
moveItemsFromS1ToS2(seq1, seq2);
return 0;
}