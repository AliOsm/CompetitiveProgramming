#include <bits/stdc++.h>

using namespace std;

int n, m, freq[101][26], all[101];
char s[101];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf("%s", s);
    for(int j = 0; j < m; ++j)
      ++freq[j][s[j] - 'A'];
  }
  
  for(int i = 0; i < m; ++i)
    for(int j = 0; j < 26; ++j)
      all[i] += (freq[i][j] != 0);
  
  long long res = 1;
  for(int i = 0; i < m; ++i)
    res = (res * (all[i] == 0 ? 1 : all[i])) % int(1e9 + 7);
  printf("%lld\n", res);
  
  return 0;
}

