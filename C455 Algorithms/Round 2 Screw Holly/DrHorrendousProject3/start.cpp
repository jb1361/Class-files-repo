#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
class DirectedGraphMatrix {
public:
	int vertices[100][100] = {0};
	void addVertice(int v1, int v2) {
		vertices[v1][v2] = 1;
	}
};
int main(int argc, char *argv[]) {
	string input;
	getline(cin, input);
	DirectedGraphMatrix* graph = new DirectedGraphMatrix();
	while (input != "") {
		char char_array[sizeof(input)];
		strcpy_s(char_array, input.c_str());
		char* pch;
		pch = strtok(char_array, " ");
		while (pch != NULL)
		{
			if (pch != "-1") {
				int v1;				
				if (v1 != NULL) {				
					graph->addVertice(v1, stoi(pch));
					v1 = NULL;					
				}
				else {
					v1 = stoi(pch);
				}				
				pch = strtok(NULL, " ");
			}
			else {
				break;
			}

		}
		getline(cin, input);
	}
	cout << graph->vertices << endl;
	return 0;
}
