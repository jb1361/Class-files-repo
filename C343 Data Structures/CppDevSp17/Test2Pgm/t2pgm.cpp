#include "Wrapper.h"
#include "Sequence\Sequence1.hpp"

typedef Sequence1<Integer> SequenceOfIntegers;

void reverse(SequenceOfIntegers& s) {
	Integer previous;
	Integer next;
	s.remove(0, previous);
	if (s.length() > 0) {
		reverse(s);
	}
	s.add(s.length(), previous);

}//reverse


Integer findLargestValue(SequenceOfIntegers& s) {
	Integer previous;
	Integer next;
	s.remove(0, previous);
	if (s.length() > 0) {	
		next = findLargestValue(s);
		Integer t;
		t = previous;
		s.add(0, t);
		if (previous > next) return previous;
		else return next;
	}
		return previous;
	//}
}//findLargestValue

int main() {
	Integer t;
	SequenceOfIntegers seq1;
	t = 47;
	seq1.add(seq1.length(), t);
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

	Integer z;
	z = findLargestValue(seq1);
	wcout << "The largest value in seq1 is: " << z << endl;
	wcout << "Sequence Before Reverse: " << seq1 << endl;
	reverse(seq1);
	wcout << "Sequence after Reverse: " << seq1 << endl;
	return 0;
}