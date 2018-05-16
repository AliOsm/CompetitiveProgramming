#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[101][101];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(s[i][j] == '.') {
        for(int k = 0, ni, nj; k < 8; ++k) {
          ni = i + dx[k];
          nj = j + dy[k];

          if(ni < 0 || ni >= n || nj < 0 || nj >= m)
            continue;

          if(s[ni][nj] == '*') {
            cout << "NO" << endl;
            return 0;
          }
        }
      } else if(isdigit(s[i][j])) {
        int cnt = 0;
        for(int k = 0, ni, nj; k < 8; ++k) {
          ni = i + dx[k];
          nj = j + dy[k];

          if(ni < 0 || ni >= n || nj < 0 || nj >= m)
            continue;

          if(s[ni][nj] == '*') {
            ++cnt;
          }
        }

        if(cnt != (s[i][j] - '0')) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }

  cout << "YES" << endl;

  return 0;
}
