/*
  Idea:
    - https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=srm319
*/

#include <bits/stdc++.h>

using namespace std;

class ConstructBST {
  void paskal() {
    nCk[0][0] = 1;
    nCk[1][0] = 1;
    nCk[1][1] = 1;
    for(int i = 2; i < 30; ++i)
      for(int j = 0; j <= i; ++j)
        if(j == 0 || j == i)
          nCk[i][j] = 1;
        else
          nCk[i][j] = nCk[i - 1][j] + nCk[i - 1][j - 1];
  }

  int DFS(int u) {
    vis.insert(u);

    cnt[u] = 1;
    for(int i = 0; i < g[u].size(); ++i) {
      if(vis.count(g[u][i]))
        continue;
      cnt[u] += DFS(g[u][i]);
    }

    if(cnt[u] == 1)
      leaf.insert(u);

    return cnt[u];
  }

  long long count(int u, int p) {
    if(leaf.count(u))
      return 1;

    long long ret = 1;
    int all = 0, child;
    for(int i = 0; i < g[u].size(); ++i)
      if(g[u][i] != p) {
        ret *= count(g[u][i], u);
        all += cnt[g[u][i]];
        child = i;
      }

    return ret * nCk[all][cnt[g[u][child]]];
  }

public:
  static long long nCk[30][30];
  static set<int> vis, leaf;
  static map<int, int> cnt;
  static map<int, vector<int> > g;

  long long numInputs(vector<int> tree) {
    sort(tree.begin(), tree.end());
    for(int i = 1, a, b; i < tree.size(); ++i) {
      a = tree[i];
      b = a / 2;
      g[a].push_back(b);
      swap(a, b);
      g[a].push_back(b);
    }

    paskal();
    DFS(1);
    return count(1, -1);
  }
};

long long ConstructBST::nCk[30][30] = {0};
set<int> ConstructBST::vis;
set<int> ConstructBST::leaf;
map<int, int> ConstructBST::cnt;
map<int, vector<int> > ConstructBST::g;
