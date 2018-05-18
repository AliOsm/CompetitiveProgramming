#include <bits/stdc++.h>

using namespace std;

int const N = 5e6;
int t, n, res[5000001];

int rec(long long x) {
  if(x == 1)
    return 0;

  if(x <= N && res[x] != -1)
    return res[x];

  if(x & 1)
    return rec(3 * x + 1) + 1;
  return rec(x / 2) + 1;
}

int main() {
  memset(res, -1, sizeof res);
  for(int i = 1; i <= N; ++i)
    res[i] = rec(i);

  int mx = 0, cur = 1;
  for(int i = 1; i <= N; ++i) {
    if(res[i] >= mx)
      mx = res[i], cur = i;
    res[i] = cur;
  }

  scanf("%d", &t);
  while(t-- != 0) {
    scanf("%d", &n);
    printf("%d\n", res[n]);
  }

  return 0;
}
