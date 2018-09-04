/*
  Idea:
    - Brute force to find all occurrences of string `t` in `s`,
      then use this information to answer the queries.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
char s[N], t[N];
int n, m, q;
vector<int> all;

int main() {
  scanf("%d %d %d", &n, &m, &q);
  scanf("%s\n%s", s, t);

  int slen = strlen(s);
  int tlen = strlen(t);

  for(int i = 0; i + tlen - 1 < slen; ++i) {
    bool ok = true;
    for(int j = 0, k = i; j < tlen; ++j, ++k)
      if(s[k] != t[j]) {
        ok = false;
        break;
      }
    if(ok)
      all.push_back(i);
  }

  for(int i = 0, a, b; i < q; ++i) {
    int res = 0;
    scanf("%d %d", &a, &b);
    --a, --b;
    for(int j = 0; j < all.size(); ++j)
      if(all[j] >= a && all[j] + tlen - 1 <= b)
        ++res;
    printf("%d\n", res);
  }

  return 0;
}
