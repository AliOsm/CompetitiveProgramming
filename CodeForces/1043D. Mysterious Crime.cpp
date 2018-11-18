#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1, M = 1e9 + 9;
int n, m, a[N][10], p, idxs[N][10];
long long hash_value[N][10], p_pow[N], ip_pow[N];

long long fst(long long b, long long p) {
  if(p == 0)
    return 1;
  if(p == 1)
    return b;

  long long ret = fst(b, p >> 1) % M;
  ret = ret * ret % M;

  if(p & 1)
    ret = ret * b % M;

  return ret;
}

void compute_hash(int idx) {
  hash_value[1][idx] = (1ll * a[1][idx] * p_pow[1]) % M;
  for(int i = 2; i <= n; ++i)
    hash_value[i][idx] = (hash_value[i - 1][idx] + (1ll * a[i][idx] * p_pow[i]) % M) % M;
}

bool can(int mid, int v) {
  if(idxs[v][0] + mid - 1 > n)
    return false;
  long long cur = (1ll * (((hash_value[idxs[v][0] + mid - 1][0] - hash_value[idxs[v][0] - 1][0]) + M) % M) * ip_pow[idxs[v][0]]) % M;
  for(int i = 0; i < m; ++i) {
    if(idxs[v][i] + mid - 1 > n)
      return false;
    if((1ll * (((hash_value[idxs[v][i] + mid - 1][i] - hash_value[idxs[v][i] - 1][i]) + M) % M) * ip_pow[idxs[v][i]]) % M != cur)
      return false;
  }
  return true;
}

int calc(int v) {
  int ret = 0, l, r, mid, res;

  l = 1, r = N, mid, res = 0;
  while(l <= r) {
    mid = (l + r) >> 1;
    if(can(mid, v))
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  ret += res;

  return ret;
}

int main() {
  p = 100003;
  p_pow[1] = ip_pow[1] = 1;
  for(int i = 2; i < N; ++i) {
    p_pow[i] = (1ll * p_pow[i - 1] * p) % M;
    ip_pow[i] = fst(p_pow[i], M - 2);
  }

  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    for(int j = 1; j <= n; ++j) {
      scanf("%d", &a[j][i]);
      idxs[a[j][i]][i] = j;
    }
    compute_hash(i);
  }

  long long res = 0;
  for(int i = 1; i <= n; ++i)
    res += calc(i);

  printf("%lld\n", res);

  return 0;
}
