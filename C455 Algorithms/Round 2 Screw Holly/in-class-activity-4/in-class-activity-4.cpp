#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <sstream>

using namespace std;

int main()
{
	ifstream myfile("employee.txt");
	string line;
	string fullName;
	if (myfile.is_open())
	{
		while (getline(myfile, line, '\r'))
		{
			cout << line << '\n';
			istringstream iss(line);
			int i = 0;
			string subs = "";
			do
			{
				string subs;
				iss >> subs;
				cout << "Substring: " << subs << endl;
				i++;
			} while (i <= 1);
		}
		myfile.close();
	}
	return 0;
	myfile.close();
}

//Hash Function 1
int hashCode(string name) {
	int hash = 0;
	for (int i = 0; i < name.length(); i++)
		hash = (hash * 31) + name.at(i);
	return hash; }

//Hash Function 2
int hashCode2(string name) {
	int hash = 0;
	int x = (name.length() / 8);
	int skip = max(1, x);
	for (int i = 0; i < name.length(); i += skip)
		hash = (hash * 37) + name.at(i);
	return hash; }