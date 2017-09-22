#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

int const N = 41;
int t, n;
bool vis[N];
pair<int, int> a[N];

int main() {
  scanf("%d", &t);
  
  while(t-- != 0) {
    memset(vis, false, sizeof vis);
    
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
      scanf("%d %d", &a[i].F, &a[i].S);
    
    int cnt = 0, cur = 0, res = 0;
    while(cnt < n) {
      int idx, mn = 1e9;
      for(int i = 0; i < n; ++i) {
        if(!vis[i] && i != cur) {
          if(min(abs(a[cur].F - a[i].F), abs(a[cur].S - a[i].S)) < mn) {
            mn = min(abs(a[cur].F - a[i].F), abs(a[cur].S - a[i].S));
            idx = i;
          }
        }
      }
      res ^= (cur + 1);
      vis[cur] = true;
      cur = idx;
      ++cnt;
    }
    printf("%d\n", res);
  }
  
  return 0;
}

