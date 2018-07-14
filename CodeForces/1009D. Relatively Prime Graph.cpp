#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, v;
pair<int, int> phi[N];
set<pair<int, int> > e;

void print(int x, int &cnt) {
  for(int i = 1; cnt > 0 && i <= n; ++i)
    if(i != x && __gcd(x, i) == 1) {
      if(e.count({min(x, i), max(x, i)}) == 1)
        continue;
      e.insert({min(x, i), max(x, i)});
      printf("%d %d\n", x, i), --cnt;
    }
}

int main() {
  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; ++i)
    phi[i].first = phi[i].second = i;

  for(int p = 2; p <= n; ++p)
    if(phi[p].first == p) {
      phi[p].first = p - 1;

      for(int i = 2 * p; i <= n; i += p)
        phi[i].first = (phi[i].first / p) * (p - 1);
    }

  long long to = 0;
  for(int i = 1; i <= n; ++i)
    to += phi[i].first;

  if(to - 1 < m || m < n - 1) {
    puts("Impossible");
    return 0;
  }

  puts("Possible");

  for(int i = n; i > 0; --i)
    if(phi[i].first == phi[i].second - 1) {
      v = phi[i].second;
      break;
    }
  
  for(int i = 1; i <= n; ++i) {
    if(i == v)
      continue;

    printf("%d %d\n", v, i);
    e.insert({min(v, i), max(v, i)});
  }
  m -= (n - 1);

  sort(phi + 1, phi + n + 1);
  reverse(phi + 1, phi + n + 1);

  for(int i = 1; m > 0 && i <= n; ++i)
    print(phi[i].second, m);

  return 0;
}
