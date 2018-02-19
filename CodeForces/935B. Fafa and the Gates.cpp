#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	int x, y, cur;
	x = y = 0;

	if(s[0] == 'U')
		++x, cur = 1;
	else
		++y, cur = 2;

	int res = 0;
	for(int i = 1; i < s.length(); ++i) {
		if(s[i] == 'U') {
			if(x == y && cur == 2)
				++res, cur = 1;
			++x;
		}

		if(s[i] == 'R') {
			if(x == y && cur == 1)
				++res, cur = 2;
			++y;
		}
	}

	cout << res << endl;

	return 0;
}

