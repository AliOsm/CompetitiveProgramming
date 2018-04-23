#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a[1001] = {0};
	cin >> n >> m;
	for(int i = 0, tmp; i < m; ++i) {
		cin >> tmp;
		--tmp;
		++a[tmp];
	}

	int res = 1e9;
	for(int i = 0; i < n; ++i)
		res = min(res, a[i]);

	cout << res << endl;

  return 0;
}
