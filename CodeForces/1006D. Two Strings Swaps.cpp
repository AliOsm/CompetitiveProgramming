/*
  Idea:
    - Each 2 mirror indexes in `a` and `b` are solvable alone,
      in other words they does not affect the other indexes.
    - We can use the fact in the previous point and solve each
      2 mirror indexes and add the result of them to the solution
      of the problem.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
char a[N], b[N];
int n;

int main() {
  scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);

  int res = 0;
  for(int i = 1, j = n; i <= j; ++i, --j) {
    if(i == j) {
      if(a[i] != b[i])
        ++res;
      continue;
    }

    if(a[i] == b[j] && b[i] == a[j])
      continue;
    if(a[i] == a[j] && b[i] == b[j])
      continue;
    if(a[i] == b[i] && a[j] == b[j])
      continue;

    if(a[i] != a[j] && a[i] != b[i] && a[i] != b[j] && a[j] != b[i] && a[j] != b[j] && b[i] != b[j]) {
      res += 2;
      continue;
    }
    
    if(a[i] != a[j] && b[i] == b[j] && a[i] != b[i] && a[j] != b[i]) {
      res += 1;
      continue;
    }

    if(a[i] == a[j] && b[i] != b[j] && a[i] != b[i] && a[i] != b[j]) {
      res += 2;
      continue;
    }

    ++res;
  }

  printf("%d\n", res);

  return 0;
}
