#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, x, y, xx[N], yy[N];
bool vis[N];

bool collinear(int i, int j) {
  return fabs((y - yy[i]) * (x - xx[j]) - (y - yy[j]) * (x - xx[i])) <= 1e-9;
}

int main() {
  scanf("%d %d %d", &n, &x, &y);
  for(int i = 0; i < n; ++i)
    scanf("%d %d", xx + i, yy + i);
  
  int res = 0;

  for(int i = 0; i < n; ++i) {
    if(vis[i])
      continue;
    
    for(int j = 0; j < n; ++j) {
      if(vis[j])
        continue;
      
      if(collinear(i, j))
        vis[j] = true;
    }

    vis[i] = true;
    ++res;
  }

  printf("%d\n", res);

  return 0;
}
