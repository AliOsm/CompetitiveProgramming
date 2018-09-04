/*
  Idea:
    - http://codeforces.com/blog/entry/61015
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n, m, a[N], b[N];

int main() {
  int cur = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), cur ^= a[i];
  for(int i = 0; i < m; ++i)
    scanf("%d", b + i), cur ^= b[i];

  if(cur != 0) {
    puts("NO");
    return 0;
  }

  puts("YES");

  for(int i = 1; i < m; ++i)
    cur ^= b[i];
  cur ^= a[0];

  printf("%d ", cur);
  for(int i = 1; i < m; ++i)
    printf("%d ", b[i]);
  puts("");

  for(int i = 1; i < n; ++i) {
    printf("%d ", a[i]);
    for(int j = 1; j < m; ++j)
      printf("0 ");
    puts("");
  }

  return 0;
}
