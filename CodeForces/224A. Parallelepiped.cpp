#include <bits/stdc++.h>

using namespace std;

int a[3], b[3];
vector<int> d[3];

int main() {
  for(int i = 0; i < 3; ++i)
    scanf("%d", a + i);
  sort(a, a + 3);

  for(int i = 0; i < 3; ++i) {
    int sqrta = sqrt(a[i]) + 1;
    for(int j = 1; j <= sqrta; ++j) {
      if(a[i] % j == 0)
        d[i].push_back(j), d[i].push_back(a[i] / j);
    }
  }

  for(int i = 0; i < d[0].size(); ++i)
    for(int j = 0; j < d[1].size(); ++j)
      for(int k = 0; k < d[2].size(); ++k) {
        b[0] = d[0][i] * d[1][j];
        b[1] = d[0][i] * d[2][k];
        b[2] = d[1][j] * d[2][k];
        sort(b, b + 3);

        bool ok = true;
        for(int l = 0; l < 3; ++l)
          if(a[l] != b[l])
            ok = false;
        
        if(ok) {
          printf("%d\n", 4 * d[0][i] + 4 * d[1][j] + 4 * d[2][k]);
          return 0;
        }
      }

  return 0;
}
