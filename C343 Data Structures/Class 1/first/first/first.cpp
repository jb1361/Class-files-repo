
#include <ioStream>
using namespace std;

//we can get rid of this and move the entire sq method above our main (sorta like how python does it)
int sq(int);


int main() {
	for (int i = 0; i <= 10; i++){cout << sq(i) << endl;}
	return 0;
}

int sq(int count) { return count * count; }