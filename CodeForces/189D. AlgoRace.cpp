/*
  Idea:
    - Using Floyd-Warshall algorithm we can calculate the shortest
      path for each car independently.
    - Then using Floyd-Warshall again we can calculate the shortest
      path using at most `k` changes.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 61;
int n, m, r, cars[N][N][N], floyd[N][N][N];

int main() {
  scanf("%d %d %d", &n, &m, &r);

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int k = 0; k < n; ++k)
        cars[i][j][k] = 1e9;

  for(int c = 0; c < m; ++c) {
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        scanf("%d", &cars[i][j][c]);

    for(int k = 0; k < n; ++k)
      for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
          cars[i][j][c] = min(cars[i][j][c], cars[i][k][c] + cars[k][j][c]);
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int c = 0; c < N; ++c)
        floyd[i][j][c] = 1e9;

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      for(int c = 0; c < m; ++c)
        floyd[i][j][0] = min(floyd[i][j][0], cars[i][j][c]);

  for(int c = 1; c <= 60; ++c)
    for(int k = 0; k < n; ++k)
      for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
          floyd[i][j][c] = min(floyd[i][j][c], floyd[i][k][c - 1] + floyd[k][j][0]);

  for(int i = 0, s, t, k; i < r; ++i) {
    scanf("%d %d %d", &s, &t, &k);
    --s, --t, k = min(k, 60);
    printf("%d\n", floyd[s][t][k]);
  }

  return 0;
}
