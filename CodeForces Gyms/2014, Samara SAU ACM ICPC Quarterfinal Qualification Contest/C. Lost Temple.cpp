#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
long long k, tmp, tmp1;
vector<pair<int, int> > fact;
set<pair<long long, long long> > st;

long long fst(long long b, long long p) {
  if(p == 0)
    return 1ll;
  if(p == 1)
    return b;

  long long ret = fst(b, p >> 1);
  ret *= ret;
  if(p & 1ll)
    ret *= b;

  return ret;
}

void rec(int idx, long long num) {
  if(idx == fact.size()) {
    st.insert(make_pair(min(num, tmp / num), max(num, tmp / num)));
    return;
  }

  for(int i = 0; i <= fact[idx].second; ++i)
    rec(idx + 1, num * fst(fact[idx].first, i));
}

int main() {
  scanf("%lld", &k);
  tmp = k * k, tmp1 = k;

  for(long long i = 2, freq; i * i <= k; ++i) {
    freq = 0;
    while(k % i == 0) {
      k /= i;
      ++freq;
    }

    if(freq > 0)
      fact.push_back(make_pair(i, freq * 2));
  }

  if(k != 1)
    fact.push_back(make_pair(k, 2));

  rec(0, 1);

  printf("%d\n", int(st.size() * 2 - 1));
  long long x, y;
  for(set<pair<long long, long long> >::iterator it = st.begin(); it != st.end(); ++it) {
    x = tmp1 + it->first;
    y = tmp1 + it->second;
    printf("%lld %lld\n", x, y);
    if(x != y)
      printf("%lld %lld\n", y, x);
  }

  return 0;
}
