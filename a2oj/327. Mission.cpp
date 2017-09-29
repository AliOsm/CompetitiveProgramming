#include <bits/stdc++.h>

using namespace std;

int t, n, m, k;
map<string, int> mp;
vector<string> sol;
string team, nm;

int main() {
  scanf("%d", &t);
  for(int kase = 1; t-- != 0; ++kase) {
    mp.clear();
    sol.clear();
    int cnt = 0;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; ++i) {
      cin >> team >> nm;
      if(cnt >= k || mp[nm] >= m)
        continue;
      ++mp[nm];
      sol.push_back(team);
      ++cnt;
    }
    
    printf("Case %d:\n", kase);
    for(int i = 0; i < (int)sol.size(); ++i)
      cout << sol[i] << endl;
  }
  
  return 0;
}
