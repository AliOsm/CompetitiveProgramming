#include <bits/stdc++.h>

using namespace std;

int const N = 101;
int n;
int di[] = { 1, 0, -1, 0 };
int dj[] = { 0, 1, 0, -1 };
char g[N][N];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%s", g[i]);
  
  int res = 0;
  for(int i = 0; i < n; ++i)
    for(int j = 0, cnt = 0; j < n; ++j) {
      for(int k = 0, ni, nj; k < 4; ++k) {
        ni = i + di[k];
        nj = j + dj[k];
        if(ni >= 0 && ni < n && nj >= 0 && nj < n && g[ni][nj] == 'o')
          ++cnt;
      }
      if(cnt % 2 == 0)
        ++res;
    }
  if(res == (n * n))
    puts("YES");
  else
    puts("NO");
  
  return 0;
}
