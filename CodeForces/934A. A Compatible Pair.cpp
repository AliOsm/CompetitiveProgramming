#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int a[51] = {0}, b[51] = {0};
	long long c[51] = {0};

	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < m; ++i)
		cin >> b[i];

	for(int i = 0; i < n; ++i) {
		long long mx = -2e18;
		for(int j = 0; j < m; ++j) {
			mx = max(mx, 1ll * a[i] * b[j]);
		}
		c[i] = mx;
	}

	sort(c, c + n);

	cout << c[n - 2] << endl;

	return 0;
}
