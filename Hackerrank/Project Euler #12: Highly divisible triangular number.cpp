#include <bits/stdc++.h>

using namespace std;

map<int, int> mp;

int d(int x) {
  int ret = 0, sqrtx = sqrt(x);
  for(int i = 1; i <= sqrtx; ++i)
    if(x % i == 0) {
      ++ret;

      if(x / i != i)
        ++ret;
    }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t-- != 0) {
    int n;
    scanf("%d", &n);

    int cur = 1, tri = 1, cnt = 1;
    while(cnt <= n) {
      ++cur;
      tri = cur * (cur + 1) / 2;

      if(mp.count(tri)) {
        cnt = mp[tri];
        continue;
      }

      cnt = d(tri);
      mp[tri] = cnt;
    }

    printf("%d\n", tri);
  }

  return 0;
}
