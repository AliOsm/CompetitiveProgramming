#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int a[3][3];
bool vis[3][3];

int main() {
  memset(vis, true, sizeof vis);
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      scanf("%d", &a[i][j]);
  
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
      while(a[i][j]-- != 0) {
        vis[i][j] = !vis[i][j];
        for(int k = 0, nx, ny; k < 4; ++k) {
          nx = i + dx[k];
          ny = j + dy[k];
          if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
            vis[nx][ny] = !vis[nx][ny];
        }
      }
  
  for(int i = 0; i < 3; ++i, puts(""))
    for(int j = 0; j < 3; ++j)
      printf("%d", vis[i][j]);
  
  return 0;
}

