/*
  - Brute force and Binary search.
  - We can save where each 1 and 2 appear in the array `a`.
  - When while looping over the array `a` we can count the current
    score of player1 and player2.
  - If one of them be larger than the other, then we check if there is
    a valid number of games with `p` points to end.
  - `p` here is the max between player1 and player2 points.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N];
vector<int> nxt[2];
vector<pair<int, int> > sol;

int check(int p) {
  int i = -1, j = -1, wi = 0, wj = 0;
  for(; i < int(nxt[0].size()) && j < int(nxt[1].size());) {
    if(i == int(nxt[0].size()) - 1 && j == int(nxt[1].size()) - 1)
      break;

    if(i + p < nxt[0].size() && j + p < nxt[1].size() && nxt[0][i + p] < nxt[1][j + p])
      i += p, j = upper_bound(nxt[1].begin(), nxt[1].end(), nxt[0][i]) - nxt[1].begin(), --j, ++wi;
    else if(i + p < nxt[0].size() && j + p < nxt[1].size() && nxt[0][i + p] > nxt[1][j + p])
      j += p, i = upper_bound(nxt[0].begin(), nxt[0].end(), nxt[1][j]) - nxt[0].begin(), --i, ++wj;
    else if(i + p < nxt[0].size() && j + p >= nxt[1].size())
      i += p, j = upper_bound(nxt[1].begin(), nxt[1].end(), nxt[0][i]) - nxt[1].begin(), --j, ++wi;
    else if(i + p >= nxt[0].size() && j + p < nxt[1].size())
      j += p, i = upper_bound(nxt[0].begin(), nxt[0].end(), nxt[1][j]) - nxt[0].begin(), --i, ++wj;
    else
      return -1;
  }

  if(wi == wj || (!nxt[0].empty() && !nxt[1].empty() &&
                  ((wi > wj && nxt[0].back() < nxt[1].back()) ||
                   (wi < wj && nxt[0].back() > nxt[1].back()))))
    return -1;
  return max(wi, wj);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    nxt[a[i] - 1].push_back(i);
  }

  int o = 0, t = 0;
  for(int i = 0; i < n; ++i) {
    o += a[i] == 1;
    t += a[i] == 2;

    if(o != t) {
      int res = check(max(o, t));
      if(res > 0)
        sol.push_back({res, max(o, t)});
    }
  }

  sort(sol.begin(), sol.end());
  sol.resize(unique(sol.begin(), sol.end()) - sol.begin());
  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d %d\n", sol[i].first, sol[i].second);

  return 0;
}
