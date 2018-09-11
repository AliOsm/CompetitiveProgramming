#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, k, a[N];
long long p[11];
vector<long long> rem[11];

int main() {
  p[0] = 1;
  for(int i = 1; i < 11; ++i)
    p[i] = p[i - 1] * 10;

  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);

  for(int i = 0; i < n; ++i)
    rem[int(floor(log10(a[i])) + 1)].push_back(a[i] % k);

  for(int i = 1; i <= 10; ++i)
    sort(rem[i].begin(), rem[i].end());

  long long res = 0;
  for(int i = 0, l, r; i < n; ++i) {
    for(int j = 1; j <= 10; ++j) {
      if(rem[j].empty())
        continue;

      long long tmp = (k - ((1ll * (a[i] % k) * (p[j] % k)) % k)) % k;
      if(tmp < 0)
        continue;

      l = lower_bound(rem[j].begin(), rem[j].end(), tmp) - rem[j].begin();
      r = upper_bound(rem[j].begin(), rem[j].end(), tmp) - rem[j].begin();

      res += r - l;
    }

    if((1ll * ((a[i] % k) * (p[int(floor(log10(a[i])) + 1)] % k)) % k + a[i]) % k == 0)
      --res;
  }

  printf("%lld\n", res);

  return 0;
}
