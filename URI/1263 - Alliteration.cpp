#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string s;

	while (getline(cin, s)) {
		s += ' ';
		char cur = tolower(s[0]);
		int c = 0, cc = 0;

		for (int i = 0, len = s.length(); i <= len; i++) {
			if (tolower(s[i]) == cur) cc++;
			else if(cc >= 2) {
				cc = 1;
				c++;
				cur = tolower(s[i]);
			}
			else {
				cc = 1;
				cur = tolower(s[i]);
			}

			while (i < len && s[i] != ' ') i++;
		}

		cout << c << endl;
	}

	return 0;
}
