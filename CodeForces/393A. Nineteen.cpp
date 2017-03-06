#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, res = "";
	int c = 0, x;

	cin >> s;
	x = s.length();

	for (int i = 0; i < x; i++) {
		if (s.find('n') < x) {
			res += 'n';
			s[s.find('n')] = ' ';
		}
		else {
			break;
		}

		if (s.find('i') < x) {
			res += 'i';
			s[s.find('i')] = ' ';
		}
		else {
			break;
		}

		if (s.find('n') < x) {
			res += 'n';
			s[s.find('n')] = ' ';
		}
		else {
			break;
		}

		if (s.find('e') < x) {
			res += 'e';
			s[s.find('e')] = ' ';
		}
		else {
			break;
		}


		if (s.find('t') < x) {
			res += 't';
			s[s.find('t')] = ' ';
		}
		else {
			break;
		}

		if (s.find('e') < x) {
			res += 'e';
			s[s.find('e')] = ' ';
		}
		else {
			break;
		}

		if (s.find('e') < x) {
			res += 'e';
			s[s.find('e')] = ' ';
		}
		else {
			break;
		}
	}

	while (res.length() > 1) {
		if(res.substr(0, 8) == "nineteen")
			c++;

		res.erase(0, 7);
	}

	cout << c << endl;

	return 0;
}
