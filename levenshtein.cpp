#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printTable(vector< vector<int> >&, string&, string&);

int main(int argc, char** argv) {
	if(argc < 3) {
		cout << "Not enough args!\n";
		return 0;
	} else if(argc > 3) {
		cout << "Too many args!\n";
		return 0;
	}
	
	string s1(argv[1]);
	string s2(argv[2]);

	cout << "Words: " << s1 << ", " << s2 << '\n';
	s1 = "-" + s1;
	s2 = "-" + s2;

	vector< vector<int> > table(s1.size(), vector<int>(s2.size(), 0));

	cout << "Table dimensions: " << table.size() << " " << table[0].size() << '\n';

	for(unsigned i = 0; i < s1.size(); i++) {
		table[i][0] = i;
	}
	for(unsigned j = 0; j < s2.size(); j++) {
		table[0][j] = j;
	}

	for(unsigned i = 1; i < s1.size(); i++) {
		for(unsigned j = 1; j < s2.size(); j++) {
			if(i == 0 || j == 0) {
				table[i][j] = i + j;
			} else {
				int leftVal = table[i - 1][j] + 1;
				int upVal = table[i][j - 1] + 1;
				int diagVal = table[i - 1][j - 1];
				if(s1[i] != s2[j]) {
					diagVal++;
				}

				int min = leftVal;
				if(upVal < min) {
					min = upVal;
				}
				if(diagVal < min) {
					min = diagVal;
				}
	
				table[i][j] = min;
			}
		}
	}

	cout << '\n';
	printTable(table, s1, s2);
	cout << '\n';

	cout << "Distance: " << table[s1.size() - 1][s2.size() - 1] << '\n';

	return 0;
}

void printTable(vector< vector<int> >& table, string& s1, string& s2) {
	cout << "\033[1m*\t*";
	for(unsigned i = 0; i < s2.size(); i++) {
		cout << '\t' << s2[i];
	}
	cout << "\033[0m\n";
	
	cout << "\033[1m*\t*\033[1;31m";
	for(unsigned i = 0; i < s2.size(); i++) {
		cout << '\t' << i;
	}
	cout << "\033[0m\n";

	for(unsigned i = 0; i < s1.size(); i++) {
		cout << "\033[1m" << s1[i];
		cout << "\t\033[1;31m" << i << "\033[0m";

		for(unsigned j = 0; j < s2.size(); j++) {
			cout << '\t' << table[i][j];
		}
		cout << '\n';
	}
}
