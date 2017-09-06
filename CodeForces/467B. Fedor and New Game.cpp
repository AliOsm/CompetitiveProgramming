#include <bits/stdc++.h>

using namespace std;

int diff(int a, int b) {
  bitset<32> aa(a), bb(b);
  int res = 0;
  for(int i = 0; i < 32; ++i)
    res += (aa[i] != bb[i]);
  return res;
}

int main() {
  int n, m, k, f;
  scanf("%d %d %d", &n, &m, &k);
  int a[1001];
  for(int i = 0; i < m; ++i)
    scanf("%d", a + i);
  scanf("%d", &f);
  
  int res = 0;
  for(int i = 0; i < m; ++i) {
    int d = diff(a[i], f);
    if(d <= k)
      ++res;
  }
  printf("%d\n", res);
  
  return 0;
}
