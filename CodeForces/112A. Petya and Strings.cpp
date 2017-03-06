#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	for(int i = 0, len = s1.length(); i < len; i++) {
		if(tolower(s1[i]) != tolower(s2[i])) {
			if(tolower(s1[i]) > tolower(s2[i]))
				cout << 1 << endl;
			else
				cout << -1 << endl;

			return 0;
		}
	}

	cout << 0 << endl;

	return 0;
}
