#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int countLower(string s) {
	int c = 0, x = s.length();
	for (int i = 0; i < x; i++) {
		if (islower(s[i]))
			c++;
	}
	return c;
}

string lower(string s) {
	int  x = s.length();
	for (int i = 0; i < x; i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}

string upper(string s) {
	int  x = s.length();
	for (int i = 0; i < x; i++) {
		s[i] = toupper(s[i]);
	}
	return s;
}

int main() {
	string s;

	cin >> s;

	if (countLower(s) >= s.length() / 2.0) {
		cout << lower(s);
	}
	else {
		cout << upper(s);
	}

	cout << endl;

	return 0;
}
