#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int ax, ay, bx, by, tx, ty;
int n;
int xi[N], yi[N];
long double dp[N][2][2];

long double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}

long double rec(int idx, bool at, bool bt) {
	if(idx == n)
		return (at || bt) ? 0 : 2e18;

	long double &ret = dp[idx][at][bt];
	if(ret == ret)
		return ret;
	ret = rec(idx + 1, at, bt) + dist(tx, ty, xi[idx], yi[idx]) * 2;

	if(!at)
		ret = min(ret, rec(idx + 1, 1, bt) + dist(ax, ay, xi[idx], yi[idx]) + dist(tx, ty, xi[idx], yi[idx]));

	if(!bt)
		ret = min(ret, rec(idx + 1, at, 1) + dist(bx, by, xi[idx], yi[idx]) + dist(tx, ty, xi[idx], yi[idx]));

	return ret;
}

int main() {
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> n;
  for(int i = 0; i < n; ++i)
  	cin >> xi[i] >> yi[i];

  memset(dp, -1, sizeof dp);
  cout << fixed << setprecision(12) << rec(0, 0, 0) << endl;

  return 0;
}
