#include <iostream>
#include <string>

using namespace std;

int main() {
	string s, t;
	short c1, c2;
	bool sameSame = true;

	cin >> s;
	cin >> t;

	c1 = s.length() - 1;
	c2 = 0;

	while (c1 >= 0) {
		if (s[c1] != t[c2]) {
			sameSame = false;
			break;
		}

		c1--;
		c2++;
	}

	if (sameSame)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
