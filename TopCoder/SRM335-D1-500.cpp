/*
  Idea:
    - Dijkstra.
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct node {
  int x, y, num, den, m;
  node(int x, int y, int num, int den, int m) :
  x(x), y(y), num(num), den(den), m(m) {}
  bool operator<(const node &n) const {
    if(m != n.m)
      return m > n.m;
    return (1.0 * num / den) - 1e-9 > (1.0 * n.num / n.den);
  }
};

pair<int, int> add(int num1, int den1, int num2, int den2) {
  int num = den1 * num2 + den2 * num1;
  int den = den1 * den2;
  int gcd = __gcd(num, den);
  return make_pair(num / gcd, den / gcd);
}

bool vis[51][51];
priority_queue<node> pq;

class ExpensiveTravel {
public:
  int minTime(vector<string> m, int startRow, int startCol, int endRow, int endCol) {
    --startRow, --startCol;
    --endRow, --endCol;
    if(m[startRow][startCol] == '1' || m[endRow][endCol] == '1')
      return -1;

    pq.push(node(startRow, startCol, 1, m[startRow][startCol] - '0', 0));

    while(!pq.empty()) {
      node fr = pq.top();
      pq.pop();

      if(vis[fr.x][fr.y])
        continue;
      vis[fr.x][fr.y] = true;

      if(fr.x == endRow && fr.y == endCol)
        return fr.m + 1;

      for(int i = 0, nx, ny; i < 4; ++i) {
        nx = fr.x + dx[i];
        ny = fr.y + dy[i];

        if(nx == fr.x && ny == fr.y)
          continue;

        if(nx < 0 || nx >= m.size() || ny < 0 || ny >= m[0].length() || m[nx][ny] == '1')
          continue;

        pair<int, int> frac = add(fr.num, fr.den, 1, m[nx][ny] - '0');

        if(frac.first > frac.second) {
          frac = add(1, m[fr.x][fr.y] - '0', 1, m[nx][ny] - '0');
          pq.push(node(nx, ny, frac.first, frac.second, fr.m + 1));
        } else
          pq.push(node(nx, ny, frac.first, frac.second, fr.m));
      }
    }

    return -1;
  }
};
