#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N];
long long dp[N][2];
vector<string> s, sr;

long long rec(int idx, bool rv) {
	if(idx == n)
		return 0;

	long long &ret = dp[idx][rv];
	if(ret != -1)
		return ret;
	ret = 2e18;

	if(rv) {
		if(s[idx] >= sr[idx - 1])
			ret = min(ret, rec(idx + 1, 0));

		if(sr[idx] >= sr[idx - 1])
			ret = min(ret, rec(idx + 1, 1) + a[idx]);

		return ret;
	}

	if(s[idx] >= s[idx - 1])
		ret = min(ret, rec(idx + 1, 0));

	if(sr[idx] >= s[idx - 1])
		ret = min(ret, rec(idx + 1, 1) + a[idx]);

	return ret;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> a[i];

  string tmp;
  for(int i = 0; i < n; ++i) {
  	cin >> tmp;
  	s.push_back(tmp);
  	reverse(tmp.begin(), tmp.end());
  	sr.push_back(tmp);
  }

  memset(dp, -1, sizeof dp);
  long long res = min(rec(1, 0), rec(1, 1) + a[0]);

  if(res >= 2e18)
  	cout << -1 << endl;
  else
  	cout << res << endl;

  return 0;
}
