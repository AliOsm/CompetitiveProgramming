/*
  Idea:
    - https://gmatclub.com/forum/what-is-the-last-non-zero-digit-of-expression-239473.html
*/

#include <bits/stdc++.h>

using namespace std;

long long const N = 1e6 + 1000;
char s[N];
int len, freq[26];
bitset<N> bs;
vector<int> p;
vector<map<int, int> > all;
map<int, int> ff;

void sieve() {
  bs[0] = bs[1] = 1;
  
  for(int i = 2; i * i < N; i++)
    if(bs[i] == 0)
      for(int j = i * i; j < N; j += i)
        bs[j] = 1;
 
  for(int i = 0; i < N; i++)
    if(bs[i] == 0)
      p.push_back(i);
}
 
void fact(int n) {
  int tmp = n;
  for(int i = 0, freq; i < p.size() && p[i] * p[i] <= n; i++) {
    freq = 0;
 
    while (n % p[i] == 0)
      freq++, n /= p[i];
 
    if(freq != 0)
      all[tmp][p[i]] = freq;
  }
 
  if(n != 1)
    all[tmp][n] = 1;
}

int fast(int b, int p) {
  if(p == 1)
    return b;
  if(p == 0)
    return 1;

  int ret = fast(b, p / 2) % 10;
  ret = ret * ret % 10;

  if(p & 1)
    ret = ret * b % 10;

  return ret;
}

int main() {
  sieve();

  all.resize(N);
  for(int i = 2; i < N; ++i)
    fact(i);

  while(scanf("%s", s) != EOF) {
    len = strlen(s);

    memset(freq, 0, sizeof freq);
    for(int i = 0; i < len; ++i)
      ++freq[s[i] - 'a'];

    ff.clear();
    for(int i = 2; i <= len; ++i)
      for(map<int, int>::iterator it = all[i].begin(); it != all[i].end(); ++it)
        ff[it->first] += it->second;
    for(int j = 0; j < 26; ++j)
      for(int i = 0; i <= freq[j]; ++i)
        for(map<int, int>::iterator it = all[i].begin(); it != all[i].end(); ++it)
          ff[it->first] -= it->second;

    int res = 1;
    ff[2] = max(0, ff[2] - ff[5]), ff[5] = 0;
    for(map<int, int>::iterator it = ff.begin(); it != ff.end(); ++it)
      res = res * fast(it->first, it->second) % 10;

    printf("%d\n", res);
  }

  return 0;
}
