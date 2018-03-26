#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<string> g;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    g.push_back(s);
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      if(g[i][j] == '#')
        for(int k = 0; k < n; ++k)
          if(g[k][j] == '#' && g[i] != g[k]) {
            puts("No");
            return 0;
          }

  cout << "Yes" << endl;

  return 0;
}
