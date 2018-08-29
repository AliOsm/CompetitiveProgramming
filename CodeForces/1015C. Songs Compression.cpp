/*
  Idea:
    - Greedy.
    - Sort the audios in decreasing order using the difference
      between `b` and `a`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m;
long long t;
pair<int, int> a[N];

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first - a.second) > (b.first - b.second);
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
    t += a[i].first;
  }

  long long need = t - m;

  if(need <= 0) {
    puts("0");
    return 0;
  }

  sort(a, a + n, cmp);

  int res = 0;
  for(int i = 0; i < n; ++i) {
    if(need <= 0)
      break;
    ++res;
    need -= a[i].first - a[i].second;
  }

  if(need <= 0)
    printf("%d\n", res);
  else
    puts("-1");

  return 0;
}
