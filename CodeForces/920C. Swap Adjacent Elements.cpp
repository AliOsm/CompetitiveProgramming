#include <bits/stdc++.h>

using namespace std;

int a[int(2e5 + 2)], cs[int(2e5 + 2)];

int main() {
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	string s;
	cin >> s;

	cs[0] = 0;
	for(int i = 1; i <= s.length(); ++i)
		cs[i] = cs[i - 1] + (s[i - 1] - '0');

	for(int i = 1; i <= n; ++i) {
		if(a[i] != i) {
			if(a[i] < i) {
				if(i - a[i] != cs[i - 1] - cs[a[i] - 1]) {
					cout << "NO" << endl;
					return 0;
				}
			} else {
				if(a[i] - i != cs[a[i] - 1] - cs[i - 1]) {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}
