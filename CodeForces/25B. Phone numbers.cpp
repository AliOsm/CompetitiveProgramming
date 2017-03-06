#include <iostream>
#include <string>

using namespace std;

int main() {
	int len, i;
	string s;
	cin >> len >> s;

	if (len % 2 == 0) {
		for (i = 0; i < len; i++) {
			if (i && i % 2 == 0)
				cout << '-';

			cout << s[i];
		}
	}
	else {
		for (i = 0; i < len - 3; i++) {
			if (i && i % 2 == 0)
				cout << '-';

			cout << s[i];
		}

		if(i)
			cout << '-';
		cout << s[len - 3];
		cout << s[len - 2];
		cout << s[len - 1];
	}

	cout << endl;

	return 0;
}
