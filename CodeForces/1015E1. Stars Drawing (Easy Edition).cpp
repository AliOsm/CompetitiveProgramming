/*
  Idea:
    - Greedy.
    - Start from each '*' and try to expand as you can.
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
  int x, y, c;
  node() {}
  node(int x, int y, int c) :
  x(x), y(y), c(c) {}
};

int n, m, ii[4], jj[4];
bool vis[101][101];
char g[101][101];
vector<node> sol;

bool check() {
  for(int i = 0; i < 4; ++i)
    if(ii[i] < 0 || ii[i] >= n || jj[i] < 0 || jj[i] >= m || g[ii[i]][jj[i]] != '*')
      return false;
  return true;
}

int can(int i, int j) {
  int c = 0;
  if(g[i][j] != '*')
    return c;
  ii[0] = i + 1, jj[0] = j;
  ii[1] = i - 1, jj[1] = j;
  ii[2] = i, jj[2] = j + 1;
  ii[3] = i, jj[3] = j - 1;
  while(check()) {
    ++c;
    for(int k = 0; k < 4; ++k)
      vis[ii[k]][jj[k]] = true;
    ++ii[0];
    --ii[1];
    ++jj[2];
    --jj[3];
  }
  if(c > 0)
    vis[i][j] = true;
  return c;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%s", g[i]);

  for(int i = 0; i < n; ++i)
    for(int j = 0, cur; j < m; ++j) {
      cur = can(i, j);
      if(cur > 0)
        sol.push_back(node(i, j, cur));
    }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(g[i][j] == '*' && !vis[i][j]) {
        puts("-1");
        return 0;
      }

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d %d %d\n", sol[i].x + 1, sol[i].y + 1, sol[i].c);

  return 0;
}
