#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	
	while (input != "") {
		char char_array[sizeof(input)];
		strcpy_s(char_array, input.c_str());
		char* pch;
		pch = strtok(char_array, " ");
		while (pch != NULL)
		{
			printf("%s\n", pch);
			if (pch != "-1") {
				pch = strtok(NULL, " ");
			}
			else {
				break;
			}

		}
		getline(cin, input);
	}
	return 0;
}
