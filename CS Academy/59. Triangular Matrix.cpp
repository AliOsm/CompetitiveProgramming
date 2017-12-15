#include <bits/stdc++.h>

using namespace std;

int const N = 3005;
int n;
char g[N][N], mn;
string sol;
pair<int, int> cur;
set<pair<int, int> > a, b;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%s", g[i]);
  
  sol = g[0][0];
  a.insert({0, 0});
  for(int i = 1; i < n; ++i) {
    mn = 'z';
    for(set<pair<int, int> >::iterator it = a.begin(); it != a.end(); ++it) {
      cur = *it;
      mn = min(mn, min(g[cur.first + 1][cur.second], g[cur.first + 1][cur.second + 1]));
    }
    
    sol += mn;
    
    for(set<pair<int, int> >::iterator it = a.begin(); it != a.end(); ++it) {
      cur = *it;
      if(g[cur.first + 1][cur.second] == mn)
        b.insert({cur.first + 1, cur.second});
      if(g[cur.first + 1][cur.second + 1] == mn)
        b.insert({cur.first + 1, cur.second + 1});
    }
    
    swap(a, b);
    b.clear();
  }
  
  cout << sol << endl;
  
  return 0;
}

