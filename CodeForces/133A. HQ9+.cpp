#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	bool sho = false;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'H' || s[i] == '9' || s[i] == 'Q') {
			sho = true;
			break;
		}
	}

	if (sho)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
