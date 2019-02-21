#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <sstream>
#include <list>
using namespace std;

int hashCode1(string name);
int hashCode2(string name);

int main()
{
	ifstream myfile("employee.txt");
	string line;
	string fullName;
	string data_name;
	std::list<string> names;
	std::list<string> data;	
	if (myfile.is_open())
	{		
		bool skip = true;
		cout << "Reading File" << '\n';
		while (getline(myfile, line, '\r'))
		{
			if (skip) { //This is really bad but I could'nt be bothered to figure out a good way to skip the headers
				skip = false;
				continue;
			}
			fullName = "";
			data_name = "";			
			istringstream iss(line);
			int i = 0;
			while (iss)
			{
				string subs;
				iss >> subs;					
				subs.erase(remove_if(subs.begin(), subs.end(), [](char c) { return !isalpha(c); }), subs.end());
				if (i <= 1) {
					fullName = fullName + subs;
					cout << fullName << endl;					
				}
				else {
					data_name = data_name + subs;
				}
				i++;
			}	
			names.push_back(fullName);
			data.push_back(data_name);
		}
		myfile.close();
	}
	cout << "Finished reading" << '\n';
	int size = names.size();
	string* hashTable1 = new string[size];
	string* hashTable2 = new string[size];
	cout << "Creating Hash tables" << '\n';

	int collisions1 = 0;
	int collisions2 = 0;

	for (int i = 0; i < size; i++)
	{
		string key = names.front();
		string elem = data.front();
		cout << key << endl;
		int hashkey1 = abs(hashCode1(key)) % size;
		int hashkey2 = abs(hashCode2(key)) % size;
		cout << "Hashkey1 " << hashkey1 << endl;
		cout << "Hashkey2 " << hashkey2 << endl;
		if()
		hashTable1[hashkey1] = elem;
		hashTable2[hashkey2] = elem;		
		names.pop_front();
		data.pop_front();
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Hash table 1 at: " << i << " " << hashTable1[i] << endl;
	}

	delete[] hashTable1;
	delete[] hashTable2;

}

//Hash Function 1
int hashCode1(string name)
{
	int hash = 0;
	for (int i = 0; i < (int)name.length(); i++)
		hash = (hash * 31) + name.at(i);
	return hash;
}

//Hash Function 2
int hashCode2(string name)
{
	int hash = 0;
	int x = (name.length() / 8);
	int skip = max(1, x);
	for (int i = 0; i < (int)name.length(); i += skip)
		hash = (hash * 37) + name.at(i);
	return hash;
}