#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, m, a[N];
char s[N];

int main() {
	cin >> n;
	string s;
	cin >> s;

	if(n == 1) {
		cout << s << endl;
		return 0;
	}

	int z = 0, o = 0;
	for(int i = 0; i < s.length(); ++i)
		if(s[i] == '0')
			++z;
		else
			++o;

	if(o > 0)
		cout << 1;
	for(int i = 0; i < z; ++i)
		cout << 0;
	cout << endl;

	return 0;
}
