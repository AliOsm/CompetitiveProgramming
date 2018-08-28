/*
  Idea:
    - If we have the sequence `p`, then we can do a Binary Search
      to find the value of `x`.
    - To find the sequence `p` we can ask `n` times for the same
      number `1` and save the answers, if 1 is not the answer
      and the rocket says `x < y`, then it is lie.
*/

#include <bits/stdc++.h>

using namespace std;

int m, n, tmp, p[31];

int main() {
  scanf("%d %d", &m, &n);

  for(int i = 0; i < n; ++i) {
    puts("1");
    fflush(stdout);
    scanf("%d", &tmp);
    if(tmp == 0)
      return 0;
    p[i] = tmp;
  }

  for(int i = 0; i < n; ++i)
    if(p[i] == -1)
      p[i] = 0;

  int l = 1, r = m, mid, res, cnt = 0;
  while(l <= r) {
    mid = (l + r) / 2;

    printf("%d\n", mid);
    fflush(stdout);
    scanf("%d", &tmp);

    if(tmp == 0)
      return 0;

    if(p[cnt] == 1) {
      if(tmp == -1)
        r = mid - 1, res = mid;
      else
        l = mid + 1, res = mid;
    } else {
      if(tmp == -1)
        l = mid + 1, res = mid;
      else
        r = mid - 1, res = mid;
    }

    ++cnt;
    cnt %= n;
  }

  printf("%d\n", res);
  fflush(stdout);
  scanf("%d", &tmp);  

  return 0;
}
