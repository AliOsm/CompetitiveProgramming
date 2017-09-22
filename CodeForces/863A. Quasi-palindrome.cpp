#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int n, m, q, k, x, y, a[N];

int main() {
	string s, rev;
	cin >> s;
	rev = s;
	reverse(rev.begin(), rev.end());

	if(s == rev) {
		puts("YES");
		return 0;
	}

	int zeros = 0;
	for(int i = s.length() - 1; i >= 0 && s[i] == '0'; --i)
		++zeros;

	for(int i = 0; i < zeros; ++i)
		s = "0" + s;

	rev = s;
	reverse(rev.begin(), rev.end());

	if(s == rev) {
		puts("YES");
		return 0;
	}

	puts("NO");

	return 0;
}
