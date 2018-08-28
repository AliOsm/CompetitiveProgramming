/*
  Idea:
    - Brute force.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, fr[100];

bool can(int mid) {
  int need = n;
  for(int i = 0; i < 100; ++i)
    need -= fr[i] / mid;
  return need <= 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0, tmp; i < m; ++i) {
    scanf("%d", &tmp);
    ++fr[--tmp];
  }

  int res = 0;
  for(int i = 1; i <= 100; ++i)
    if(can(i))
      res = i;

  printf("%d\n", res);

  return 0;
}
