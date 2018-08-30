/*
  Idea:
    - Next and Previous array.
    - Maintain next array for the closest dot after each dot
      in both rows and columns.
    - Maintain previous array for the closest dot after each dot
      in both rows and columns.
    - Use them to check each cell if it is center of any star
      of any size and add it to the answer.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1005;
int n, m, nxt[N][N][2], prv[N][N][2], vis[N][N][2];
char g[N][N];

struct node {
  int x, y, c;
  node() {}
  node(int x, int y, int c) :
  x(x), y(y), c(c) {}
};

vector<node> sol;

int main() {
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      g[i][j] = '.';

  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      scanf(" %c", &g[i][j]);

  for(int i = 1; i <= n; ++i) {
    int lst = 0;
    for(int j = 1; j <= m; ++j) {
      prv[i][j][0] = lst;
      if(g[i][j] == '.')
        lst = j;
    }
  }

  for(int i = 1; i <= n; ++i) {
    int lst = m + 1;
    for(int j = m; j > 0; --j) {
      nxt[i][j][0] = lst;
      if(g[i][j] == '.')
        lst = j;
    }
  }

  for(int i = 1; i <= m; ++i) {
    int lst = 0;
    for(int j = 1; j <= n; ++j) {
      prv[j][i][1] = lst;
      if(g[j][i] == '.')
        lst = j;
    }
  }

  for(int i = 1; i <= m; ++i) {
    int lst = n + 1;
    for(int j = n; j > 0; --j) {
      nxt[j][i][1] = lst;
      if(g[j][i] == '.')
        lst = j;
    }
  }

  for(int i = 1; i <= n; ++i) {
    int mn = 1e5;
    for(int j = 1; j <= m; ++j) {
      if(g[i][j] == '.')
        continue;

      mn = min(j - prv[i][j][0], nxt[i][j][0] - j);
      mn = min(i - prv[i][j][1], mn);
      mn = min(nxt[i][j][1] - i, mn);

      if(mn > 1) {
        sol.push_back(node(i, j, mn - 1));
        ++vis[i][j - mn + 1][0];
        --vis[i][j + mn - 1][0];
        ++vis[i - mn + 1][j][1];
        --vis[i + mn - 1][j][1];
      }
    }
  }

  for(int i = 1; i <= n; ++i) {
    int cur = 0;
    for(int j = 1; j <= m; ++j) {
      cur += vis[i][j][0];
      int old = vis[i][j][0];
      vis[i][j][0] = cur;
      if(old > 0 || old < 0)
        vis[i][j][0] = 1;
    }
  }

  for(int i = 1; i <= m; ++i) {
    int cur = 0;
    for(int j = 1; j <= n; ++j) {
      cur += vis[j][i][1];
      int old = vis[j][i][1];
      vis[j][i][1] = cur;
      if(old > 0 || old < 0)
        vis[j][i][1] = 1;
    }
  }

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= m; ++j)
      if(g[i][j] == '*' && !vis[i][j][0] && !vis[i][j][1]) {
        puts("-1");
        return 0;
      }

  printf("%d\n", int(sol.size()));
  for(int i = 0; i < sol.size(); ++i)
    printf("%d %d %d\n", sol[i].x, sol[i].y, sol[i].c);

  return 0;
}
