#include <iostream>
#include <string>

using namespace std;

int main() {
	int t, c = 0;
	cin >> t;

	if (t > 26) {
		cout << -1 << endl;
		return 0;
	}

	string s;
	cin >> s;

	int arr[26] = { 0 };

	for (int i = 0; i < t; i++)
		arr[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
		if (arr[i] > 0)
			c += arr[i] - 1;

	cout << c << endl;

	return 0;
}
