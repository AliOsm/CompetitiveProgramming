#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int const N = 2e6 + 1;
int n, rng[N], dp[N][25];
pair<int, int> a[N];
vector<int> all;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].F, &a[i].S);
    all.push_back(a[i].F);
    all.push_back(a[i].F + 1);
    all.push_back(a[i].F - 1);
    all.push_back(a[i].S);
    all.push_back(a[i].S + 1);
    all.push_back(a[i].S - 1);
  }
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  
  for(int i = 0; i < n; ++i) {
    a[i].F = lower_bound(all.begin(), all.end(), a[i].F) - all.begin();
    a[i].S = lower_bound(all.begin(), all.end(), a[i].S) - all.begin();
    ++rng[a[i].F];
    --rng[a[i].S + 1];
  }
  
  for(int i = 1; i < all.size() + 10; ++i)
    rng[i] += rng[i - 1];
  
  for(int i = 0; i < all.size() + 10; ++i)
    dp[i][0] = rng[i];
  
  for(int j = 1; (1 << j) <= all.size() + 10; ++j)
		for(int i = 0; i + (1 << j) - 1 < all.size() + 10; ++i)
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	
	for(int i = 0; i < n; ++i) {
	  int len = a[i].S - a[i].F + 1;
	  int log = 0;
	  while((1 << log) <= len)
	    ++log;
	  --log;
    
    int mn = min(dp[a[i].F][log], dp[a[i].F + len - (1 << log)][log]);
    if(mn > 1) {
      printf("%d\n", i + 1);
      return 0;
    }
	}
	
	puts("-1");
  
  return 0;
}
