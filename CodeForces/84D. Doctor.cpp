/*
  Idea:
    - We can reduce `k` if we try to remove animals from the smallest number of
      examinations to the biggest.
    - Then we can reduce `k` even more, we know that in the current state we
      cannot remove any animal, but we can remove some examinations from the
      animals by divide the remaining `k` by the remaining animals.
    - Finally, the remaining `k` will be less than 10^5, so we can brute force
      it.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, a[N];
long long k, to, tt;
vector<int> v;
map<int, int> mp;
queue<pair<int, int> > q;

int main() {
  scanf("%d %lld", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    v.push_back(a[i]);
    ++mp[a[i]];
    to += a[i];
  }

  if(to < k) {
    puts("-1");
    return 0;
  }

  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int cnt = n;
  for(int i = 0, prv = 0; i < v.size(); ++i) {
    if(k >= 1ll * (v[i] - prv) * cnt) {
      k -= 1ll * (v[i] - prv) * cnt;
      tt += (v[i] - prv);
      cnt -= mp[v[i]];
    } else
      break;

    prv = v[i];
  }

  for(int i = 0; i < n; ++i)
    a[i] -= tt, a[i] = max(0, a[i]);

  if(cnt == 0)
    return 0;

  int rem = k / cnt;
  k -= 1ll * rem * cnt;

  for(int i = 0; i < n; ++i)
    if(a[i] > 0)
      a[i] -= rem, q.push({a[i], i + 1});

  for(int i = 0; i < k; ++i) {
    pair<int, int> p = q.front();
    q.pop();
    if(--p.first == 0)
      continue;
    q.push(p);
  }

  while(!q.empty()) {
    printf("%d ", q.front().second);
    q.pop();
  }
  puts("");

  return 0;
}
