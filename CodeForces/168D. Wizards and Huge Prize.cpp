/*
	idea:
		- We can solve this problem using dynamic programmin.
		- dp[idx][win][cnt] means the probability of winning `win` games till the
			`idx` day with `cnt` places in the bag for the prizes.
		- then in each day either we go to the next day with probability (1 - p[i])
			or win the tour with probability (p[i]) and win the prize or the bag
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e2 + 1;
int n, l, k;
long double dp[N][N][N];
pair<int, long double> a[N];

long double rec(int idx, int win, int cnt) {
  if(idx == n)
    return win >= l;

  long double &ret = dp[idx][win][cnt];
  if(ret == ret)
    return ret;
  ret = 0;
  ret += rec(idx + 1, win, cnt) * (1.0 - a[idx].second);

  if(a[idx].first == -1) {
    if(cnt > 0)
      ret += rec(idx + 1, win + 1, cnt - 1) * a[idx].second;
  } else
    ret += rec(idx + 1, win + 1, min(n, cnt + a[idx].first)) * a[idx].second;

  return ret;
}

int main() {
  cin >> n >> l >> k;
  for(int i = 0; i < n; ++i)
    cin >> a[i].second, a[i].second /= 100.0;
  for(int i = 0; i < n; ++i)
    cin >> a[i].first;

  sort(a, a + n);
  reverse(a, a + n);
  memset(dp, -1, sizeof dp);
  cout << fixed << setprecision(10) << rec(0, 0, k) << endl;

  return 0;
}
