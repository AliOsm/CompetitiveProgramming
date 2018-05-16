#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
long long t, n, m, a[N];
long long k;
char s[N];

int main() {
	cin >> n >> m >> k;

	if(k < n) {
		++k;
		cout << k << ' ' << 1 << endl;
		return 0;
	}

	if(k == n) {
		cout << n << ' ' << 2 << endl;
		return 0;
	}

	k -= n;

	long long tmp = m;
	m -= 2;

	long long can = k / (m + 1);

	long long x = n, y = 2;

	if(can % 2 == 0) {
		x -= can;
	} else {
		x -= can;
		y = tmp;
	}

	long long mod = k % (m + 1);

	if(y == 2)
		y += mod;
	else
		y -= mod;

	cout << x << ' ' << y << endl;

	return 0;
}
