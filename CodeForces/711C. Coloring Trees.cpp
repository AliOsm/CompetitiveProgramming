#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[101], p[101][101];
long long dp[101][105][101];

long long rec(int idx, int lst, int cur) {
	if(idx == n) {
		if(cur == k)
			return 0;
		return 2e14;
	}

	long long &ret = dp[idx][lst + 1][cur];
	if(ret != -1)
		return ret;
	ret = 2e14;

	if(idx == 0) {
		if(a[idx] != -1)
			return ret = rec(idx + 1, a[idx], cur + 1);

		for(int i = 0; i < m; ++i)
			ret = min(ret, rec(idx + 1, i, cur + 1) + p[idx][i]);		

		return ret;
	}

	if(a[idx] != -1)
		return ret = rec(idx + 1, a[idx], cur + (lst != a[idx]));

	for(int i = 0; i < m; ++i)
		ret = min(ret, rec(idx + 1, i, cur + (lst != i)) + p[idx][i]);

	return ret;
}

void build_path(int idx, int lst, int cur) {
	if(idx == n) {
		return;
	}

	long long opt = rec(idx, lst, cur);

	if(idx == 0) {
		if(a[idx] != -1) {
			build_path(idx + 1, a[idx], cur + 1);
			return;
		}

		for(int i = 0; i < m; ++i) {
			if(rec(idx + 1, i, cur + 1) + p[idx][i] == opt) {
				cout << i +1 << ' ';
				build_path(idx + 1, i, cur + 1);
				return;
			}
		}
	}

	if(a[idx] != -1) {
		cout << a[idx] + 1 << ' ';
		build_path(idx + 1, a[idx], cur + (lst != a[idx]));
		return;
	}

	for(int i = 0; i < m; ++i) {
		if(opt == rec(idx + 1, i, cur + (lst != i)) + p[idx][i]) {
			cout << i+ 1 << ' ';
			build_path(idx + 1, i, cur + (lst != i));
			return;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	int zeros = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		zeros += (a[i] == 0);
	}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> p[i][j];

	for(int i = 0; i < n; ++i)
		--a[i];

	memset(dp, -1, sizeof dp);
	long long ans = rec(0, a[0], 0);

	if(ans >= 2e14)
		cout << -1 << endl;
	else
		cout << ans << endl;

	return 0;
}
