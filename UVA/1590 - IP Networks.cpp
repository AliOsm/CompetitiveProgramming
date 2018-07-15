/*
  Idea:
    - Convert the IPs to binary representation and store them in
      an array.
    - Brute force to find the common prefix of the IPs.
*/

#include <bits/stdc++.h>

using namespace std;

int m, a, b, c, d, all[1001][32];

int main() {
  while(scanf("%d", &m) != EOF) {
    for(int i = 0; i < m; ++i) {
      scanf("%d.%d.%d.%d", &a, &b, &c, &d);
      for(int j = 7, cnt = 0; j >= 0; --j, ++cnt)
        all[i][j] = ((a >> cnt) & 1);
      for(int j = 15, cnt = 0; j >= 8; --j, ++cnt)
        all[i][j] = ((b >> cnt) & 1);
      for(int j = 23, cnt = 0; j >= 16; --j, ++cnt)
        all[i][j] = ((c >> cnt) & 1);
      for(int j = 31, cnt = 0; j >= 24; --j, ++cnt)
        all[i][j] = ((d >> cnt) & 1);
    }

    int mx = -1;
    for(int i = 0; i < 32; ++i) {
      int def = all[0][i];
      
      bool ok = true;
      for(int j = 0; j < m; ++j)
        if(all[j][i] != def) {
          ok = false;
          break;
        }

      if(ok)
        mx = i;
      else
        break;
    }

    int res[4] = {0};
    
    for(int i = 0, cnt = 0; i < 4; ++i)
      for(int j = 0; j <= min(7, (mx - i * 8)); ++j, ++cnt)
        res[i] |= (all[0][cnt] << (7 - j));
    printf("%d.%d.%d.%d\n", res[0], res[1], res[2], res[3]);

    for(int i = 0, cnt = 0; i < 4; ++i) {
      res[i] = 0;
      for(int j = 0; j <= min(7, (mx - i * 8)); ++j, ++cnt)
        res[i] |= (1 << (7 - j));
    }
    printf("%d.%d.%d.%d\n", res[0], res[1], res[2], res[3]);
  }

  return 0;
}
