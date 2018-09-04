/*
  Idea:
    - Math, Implementation.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, a[N];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  int rem = m;
  for(int d = 0; d < n; ++d) {
    int cur = a[d], res = 0;
    if(cur < rem)
      rem -= cur;
    else if(cur == rem)
      ++res, rem = m;
    else {
      cur -= rem;
      rem = m;
      ++res;

      if(cur < rem)
        rem -= cur;
      else if(cur == rem)
        ++res, rem = m;
      else {
        res += cur / rem;
        cur = cur % rem;
        rem -= cur;
      }
    }

    printf("%d ", res);
  }

  puts("");

  return 0;
}
