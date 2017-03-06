#include <iostream>
#include <string>

using namespace std;

int main() {
	int total = 0, arr[26] = { 0 };
	string s, LANGUAGE_LETTERS = "abcdefghijklmnopqrstuvwxyz";

	getline(cin, s);
	s.erase(0, 1);
	s.erase(s.length() - 1, 1);

	if (s == "") {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == ',')
			continue;

		arr[LANGUAGE_LETTERS.find(s[i])]++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0)
			continue;

		if (arr[i] == 1) {
			total++;
		}
		else {
			total++;
		}
	}

	cout << total << endl;


	return 0;
}
