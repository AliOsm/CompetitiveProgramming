#include <bits/stdc++.h>

using namespace std;

int n, m;
long long k;

bool can(long long mid) {
  long long cnt = 0;
  for(int i = 1; i <= n; ++i)
    cnt += min((mid - 1) / i, 1ll * m);
  return cnt < k;
}

int main() {
  scanf("%d %d %lld", &n, &m, &k);
  
  long long l = 1, r = 1e12, mid, res;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(can(mid)) {
      res = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%lld\n", res);
  
  return 0;
}
