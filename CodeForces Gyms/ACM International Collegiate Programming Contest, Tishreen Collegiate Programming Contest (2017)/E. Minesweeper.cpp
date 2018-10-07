#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int t, r, c, m, dp[6][(1 << 6)][(1 << 6)];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int rec(int row, int i, int j) {
  if(row == r - 1) {
    int msk[3];
    msk[0] = i, msk[1] = j;
    bool ok = true;

    for(int l1 = 1, c1, c2, cnt; ok && l1 < 2; ++l1) {
      for(int l2 = 0; l2 < c; ++l2) {
        c1 = ((msk[l1] >> l2) & 1), cnt = 0;
        
        for(int d = 0, nx, ny; d < 8; ++d) {
          nx = l1 + dx[d];
          ny = l2 + dy[d];
          if(nx < 0 || nx >= 2 || ny < 0 || ny >= c)
            continue;
          c2 = ((msk[nx] >> ny) & 1);
          if(c1 == 0)
            cnt += (c2 == 1);
          else
            cnt += (c2 == 0);
        }

        if(c1 == 0) {
          if(cnt > m) {
            ok = false;
            break;
          }
        } else {
          if(cnt == 0) {
            ok = false;
            break;
          }
        }
      }
    }

    if(!ok)
      return -1e9;

    return 0;
  }

  int &ret = dp[row][i][j];
  if(ret != -1)
    return ret;
  ret = -1e9;

  int msk[3];
  for(int k = 0; k < (1 << c); ++k) {
    msk[0] = i, msk[1] = j, msk[2] = k;
    bool ok = true;

    for(int l1 = 1, c1, c2, cnt; ok && l1 < 2; ++l1) {
      for(int l2 = 0; l2 < c; ++l2) {
        c1 = ((msk[l1] >> l2) & 1), cnt = 0;
        
        for(int d = 0, nx, ny; d < 8; ++d) {
          nx = l1 + dx[d];
          ny = l2 + dy[d];
          if(nx < 0 || nx >= 3 || ny < 0 || ny >= c)
            continue;
          c2 = ((msk[nx] >> ny) & 1);
          if(c1 == 0)
            cnt += (c2 == 1);
          else
            cnt += (c2 == 0);
        }

        if(c1 == 0) {
          if(cnt > m) {
            ok = false;
            break;
          }
        } else {
          if(cnt == 0) {
            ok = false;
            break;
          }
        }
      }
    }

    if(ok)
      ret = max(ret, rec(row + 1, j, k) + __builtin_popcount(k));
  }

  return ret;
}

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d %d", &r, &c, &m);

    memset(dp, -1, sizeof dp);
    int res = 0;
    for(int i = 0; i < (1 << c); ++i)
      for(int j = 0; j < (1 << c); ++j) {
        int msk[3];
        msk[0] = i, msk[1] = j;
        bool ok = true;

        for(int l1 = 0, c1, c2, cnt; ok && l1 < 1; ++l1) {
          for(int l2 = 0; l2 < c; ++l2) {
            c1 = ((msk[l1] >> l2) & 1), cnt = 0;
            
            for(int d = 0, nx, ny; d < 8; ++d) {
              nx = l1 + dx[d];
              ny = l2 + dy[d];
              if(nx < 0 || nx >= 2 || ny < 0 || ny >= c)
                continue;
              c2 = ((msk[nx] >> ny) & 1);
              if(c1 == 0)
                cnt += (c2 == 1);
              else
                cnt += (c2 == 0);
            }

            if(c1 == 0) {
              if(cnt > m) {
                ok = false;
                break;
              }
            } else {
              if(cnt == 0) {
                ok = false;
                break;
              }
            }
          }
        }

        if(ok)
          res = max(res, rec(1, i, j) + __builtin_popcount(i) + __builtin_popcount(j));
      }

    printf("%d\n", res);
  }

  return 0;
}
