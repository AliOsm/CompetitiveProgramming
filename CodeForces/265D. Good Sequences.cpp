/*
  Idea:
    - Dynamic programming with Prime factorization.
    - Any two numbers share at least one prime factor, then the GCD between them
      not equal to 1.
    - Based on the previous point we can start a DP from each index and try
      to add a new number to the sequence based on the prime factorization of the 
      current number.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N], dp[N];
vector<vector<int> > g, d;

int rec(int idx) {
  if(idx == n)
  	return 0;

  int &ret = dp[idx];
  if(ret != -1)
  	return ret;
  ret = 0;

  for(int i = 0, cur; i < d[idx].size(); ++i) {
  	cur = upper_bound(g[d[idx][i]].begin(), g[d[idx][i]].end(), idx) - g[d[idx][i]].begin();
  	if(cur != g[d[idx][i]].size())
  		ret = max(ret, rec(g[d[idx][i]][cur]) + 1);
  }

  return ret;
}

int main() {
	g.resize(N);
	d.resize(N);

  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);

    int x = a[i], sqrtx = sqrt(x);
    for(int j = 2, fr; j <= sqrtx; ++j) {
    	fr = 0;
    	while(x % j == 0)
    		++fr, x /= j;
    	if(fr != 0)
    		g[j].push_back(i), d[i].push_back(j);
    }
    if(x != 1)
    	g[x].push_back(i), d[i].push_back(x);
  }

  memset(dp, -1, sizeof dp);
  int res = 0;
  for(int i = 0; i < n; ++i)
    res = max(res, rec(i) + 1);
  printf("%d\n", res);

  return 0;
}
