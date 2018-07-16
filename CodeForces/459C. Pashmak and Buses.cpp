#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int n, d, k, all[N][N];

int main() {
  scanf("%d %d %d", &n, &k, &d);

  long long f = 1;
  bool ok = false;
  for(int i = 0; i < d; ++i) {
    f *= k;
    if(f >= n) {
      ok = true;
      break;
    }
  }

  if(!ok) {
    puts("-1");
    return 0;
  }

  for(int i = 1; i < n; ++i) {
    for(int j = 0; j < d; ++j)
      all[i][j] = all[i - 1][j];
    
    for(int j = 0; j < d; ++j) {
      all[i][j] = (all[i][j] + 1) % k;
      if(all[i][j] != 0)
        break;
    }
  }

  for(int i = 0; i < d; ++i, puts(""))
    for(int j = 0; j < n; ++j)
      printf("%s%d", j == 0 ? "" : " ", all[j][i] + 1);

  return 0;
}
