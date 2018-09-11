/*
  Idea:
    - Simple BFS using 3D state.
*/

#include <bits/stdc++.h>

using namespace std;

bool vis[30][30][30];
char g[30][30][30];
int l, r, c, sl, sr, sc, el, er, ec;
int dl[] = {1, -1};
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, pair<int, int> > > q;

int BFS() {
  memset(vis, false, sizeof vis);
  while(!q.empty())
    q.pop();

  vis[sl][sr][sc] = true;
  q.push(make_pair(sl, make_pair(sr, sc)));

  int cost = 0;
  while(!q.empty()) {
    int size = q.size();

    while(size-- != 0) {
      int cl = q.front().first;
      int cr = q.front().second.first;
      int cc = q.front().second.second;
      q.pop();

      if(g[cl][cr][cc] == 'E')
        return cost;

      for(int i = 0, ncl; i < 2; ++i) {
        ncl = cl + dl[i];

        if(ncl < 0 || ncl >= l || g[ncl][cr][cc] == '#' || vis[ncl][cr][cc])
          continue;

        vis[ncl][cr][cc] = true;
        q.push(make_pair(ncl, make_pair(cr, cc)));
      }

      for(int i = 0, ncr, ncc; i < 4; ++i) {
        ncr = cr + dx[i];
        ncc = cc + dy[i];

        if(ncr < 0 || ncr >= r || ncc < 0 || ncc >= c || g[cl][ncr][ncc] == '#' || vis[cl][ncr][ncc])
          continue;

        vis[cl][ncr][ncc] = true;
        q.push(make_pair(cl, make_pair(ncr, ncc)));
      }
    }

    ++cost;
  }

  return -1;
}

int main() {
  while(scanf("%d %d %d", &l, &r, &c) && l != 0 && r != 0 && c != 0) {
    for(int i = 0; i < l; ++i)
      for(int j = 0; j < r; ++j)
        for(int k = 0; k < c; ++k) {
          scanf(" %c", &g[i][j][k]);

          if(g[i][j][k] == 'S')
            sl = i, sr = j, sc = k;
          if(g[i][j][k] == 'E')
            el = i, er = j, ec = k;
        }

    int res = BFS();

    if(res == -1)
      puts("Trapped!");
    else
      printf("Escaped in %d minute(s).\n", res);
  }

  return 0;
}
