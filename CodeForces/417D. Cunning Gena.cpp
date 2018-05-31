/*
  Idea:
    - We can sort the friends based on the number of monitors.
    - Then start a dp and for each friend we take it we will add the amount
      of money he will add to the total and if we reach the point of all
      problems solved so we can add the monitors price and minimize the result.
*/

#include <bits/stdc++.h>

using namespace std;

struct fri {
	int x, k, msk;

	bool operator<(fri f) {
		return k < f.k;
	}
};

int const N = 101;
int n, m, b, M, all;
long long dp[(1 << 20)];
fri fris[N];

int main() {
  scanf("%d %d %d", &n, &m, &b);
  M = (1 << m) - 1;
  for(int i = 0, m; i < n; ++i) {
  	scanf("%d %d %d", &fris[i].x, &fris[i].k, &m);
  	for(int j = 0, tmp; j < m; ++j) {
  		scanf("%d", &tmp);
  		--tmp;
  		fris[i].msk |= (1 << tmp);
  	}
  	all |= fris[i].msk;
  }

  if(__builtin_popcount(all) != m) {
  	puts("-1");
  	return 0;
  }

  sort(fris, fris + n);

  for(int i = 0; i < (1 << m); ++i)
  	dp[i] = 2e18;
  dp[0] = 0;

  long long res = 2e18;
  for(int i = 0; i < n; ++i) {
  	for(int j = 0; j < (1 << m); ++j)
  		if(dp[j] < 2e18)
  			dp[j | fris[i].msk] = min(dp[j | fris[i].msk], dp[j] + fris[i].x);

		if(dp[M] < 2e18)
			res = min(res, dp[M] + 1ll * b * fris[i].k);
  }

  if(res == 2e18)
  	puts("-1");
  else
  	printf("%lld\n", res);

  return 0;
}
