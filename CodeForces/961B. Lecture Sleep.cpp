#include <bits/stdc++.h>

using namespace std;

int n, m, t[100001], a[100001], cs[100001];

int main() {
	cin >> n >> m;
	long long res = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
		if(t[i]) {
			res += a[i];
			a[i] = 0;
		}
	}

	cs[0] = 0;
	for(int i = 1; i <= n; ++i) {
		cs[i] = a[i-1] + cs[i-1];
	}

	long long tmp = 0;
	for(int i = n; i >= m; --i) {
		tmp = max(tmp, 1ll * cs[i] - cs[i-m]);
	}

	cout << res + tmp << endl;

  return 0;
}
