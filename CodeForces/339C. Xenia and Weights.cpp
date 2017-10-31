#include <bits/stdc++.h>

using namespace std;

int k, dp[1001][55][25][2];
string num;
vector<int> all, sol;

bool rec(int idx, int dif, int lst, bool ply, int s1, int s2) {
  if(idx == k)
    return 1;
  
  int &ret = dp[idx][dif+25][lst][ply];
  if(ret != -1)
    return ret;
  ret = 0;
  
  if(ply) {
    for(int i = 0; i < (int)all.size(); ++i)
      if(s2 + all[i] > s1 && i != lst) {
        if(rec(idx + 1, dif - all[i], i, false, s1, s2 + all[i])) {
          sol.push_back(all[i]);
          return ret = 1;
        }
      }
  } else {
    for(int i = 0; i < (int)all.size(); ++i)
      if(s1 + all[i] > s2 && i != lst) {
        if(rec(idx + 1, dif + all[i], i, true, s1 + all[i], s2)) {
          sol.push_back(all[i]);
          return ret = 1;
        }
      }
  }
  
  return ret = 0;
}

int main() {
  cin >> num;
  cin >> k;
  
  for(int i = 0; i < 10; ++i)
    if(num[i] == '1')
      all.push_back(i + 1);
  
  memset(dp, -1, sizeof dp);
  rec(0, 0, 11, 0, 0, 0);
  
  if(sol.size() == k) {
    puts("YES");
    reverse(sol.begin(), sol.end());
    for(int i = 0; i < (int)sol.size(); ++i)
      printf("%s%d", i != 0 ? " " : "", sol[i]);
    puts("");
  } else {
    puts("NO");
  }
  
  return 0;
}
