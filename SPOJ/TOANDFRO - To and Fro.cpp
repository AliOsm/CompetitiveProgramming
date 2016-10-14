#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverse(string &s1) {
	string s2 = "";

	for (int i = s1.length() - 1; i >= 0; i--) {
		s2 += s1[i];
	}

	return s2;
}

int main() {
	int n, c;
	string s, tmp;

	cin >> n;

	while (n != 0) {
		cin.ignore();
		getline(cin, s);

		c = s.length() / n;

		vector<string> arr(c);

		for(int i = 0; i < c; i++) {
			tmp = s.substr(0, n);
			s.erase(0, n);

			if (i % 2 != 0)
				tmp = reverse(tmp);

			arr[i] = tmp;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[j][i];
			}
		}

		cout << endl;

		cin >> n;
	}

	return 0;
}
