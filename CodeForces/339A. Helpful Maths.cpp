#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int ones = 0, twos = 0, threes = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1')
			ones++;
		else if (s[i] == '2')
			twos++;
		else if (s[i] == '3')
			threes++;
	}

	s.clear();

	for (int i = 0; i < ones; i++) {
		s += "1+";
	}

	for (int i = 0; i < twos; i++) {
		s += "2+";
	}

	for (int i = 0; i < threes; i++) {
		s += "3+";
	}

	s.erase(s.length() - 1);

	cout << s << endl;


	return 0;
}
