#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long b, d, s;
	cin >> b >> d >> s;
	long long maxI = max(b, max(d, s));

	if ((b == d && d == s && s == b)) {
		cout << 0 << endl;
	} else if (d == s && (b - 1 == s || b + 1 == s)) {
		cout << 0 << endl;
	} else if (b == d && (s - 1 == d || s + 1 == d)) {
		cout << 0 << endl;
	} else if (b == s && (d - 1 == b || d + 1 == b)) {
		cout << 0 << endl;
	} else if (maxI == b) {
		if (b == d) {
			cout << b - s - 1 << endl;
		} else if (b == s) {
			cout << b - d - 1 << endl;
		} else {
			b--;
			cout << b - d + b - s << endl;
		}
	} else if (maxI == d) {
		if (d == b) {
			cout << d - s - 1 << endl;
		} else if (d == s) {
			cout << d - b - 1 << endl;
		} else {
			d--;
			cout << d - b + d - s << endl;
		}
	} else {
		if (s == b) {
			cout << s - d - 1 << endl;
		} else if (s == d) {
			cout << s - b - 1 << endl;
		} else {
			s--;
			cout << s - b + s - d << endl;
		}
	}

	return 0;
}
