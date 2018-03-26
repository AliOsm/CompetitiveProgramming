#include <bits/stdc++.h>

using namespace std;

int const N = 501;
int n, m, k;
int tt[N][N], mn[N][N], cnt[N], dp[N][N];

int rec(int idx, int rem) {
	if(rem < 0)
		return 1e9;

	if(idx == n)
		return 0;

	int &ret = dp[idx][rem];
	if(ret != -1)
		return ret;
	ret = 1e9;

	for(int i = 0; i <= cnt[idx]; ++i)
		ret = min(ret, rec(idx + 1, rem - (cnt[idx] - i)) + mn[idx][i]);

	return ret;
}

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < m; ++j) {
  		char ch;
  		cin >> ch;
  		tt[i][j] = ch - '0';
  		cnt[i] += tt[i][j];
  	}

  	fill(mn[i], mn[i] + N, 1e9);

  	for(int j = 0; j < m; ++j) {
  		int tmp = 0;
  		for(int l = j; l < m; ++l) {
  			tmp += tt[i][l];
  			mn[i][tmp] = min(mn[i][tmp], l - j + 1);
  		}
  	}
  	mn[i][0] = 0;
  }

  memset(dp, -1, sizeof dp);
  cout << rec(0, k) << endl;

  return 0;
}