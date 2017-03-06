#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int a = s.find('+'), b = s.find('=') - a - 1, c = s.length() - b - a - 2;

	if (a + b == c) {
		cout << s << endl;
	}
	else if (a + 1 + b == c - 1) {
		for (int i = 0; i < a + 1; i++) {
			cout << '|';
		}
		cout << '+';
		for (int i = 0; i < b; i++) {
			cout << '|';
		}
		cout << '=';
		for (int i = 0; i < c - 1; i++) {
			cout << '|';
		}
		cout << endl;
	}
	else if (a > 1 && a - 1 + b == c + 1) {
		for (int i = 0; i < a - 1; i++) {
			cout << '|';
		}
		cout << '+';
		for (int i = 0; i < b; i++) {
			cout << '|';
		}
		cout << '=';
		for (int i = 0; i < c + 1; i++) {
			cout << '|';
		}
		cout << endl;
	}
	else if (b > 1 && a + b - 1 == c + 1) {
		for (int i = 0; i < a; i++) {
			cout << '|';
		}
		cout << '+';
		for (int i = 0; i < b - 1; i++) {
			cout << '|';
		}
		cout << '=';
		for (int i = 0; i < c + 1; i++) {
			cout << '|';
		}
		cout << endl;
	}
	else
		cout << "Impossible" << endl;

	return 0;
}
