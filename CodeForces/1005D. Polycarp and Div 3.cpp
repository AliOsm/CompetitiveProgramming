#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int dp[N][3][2];
string s;

int rec(int idx, int mod, bool tak) {
  if(idx == s.length())
    return mod == 0;

  int &ret = dp[idx][mod][tak];
  if(ret != -1)
    return ret;
  ret = 0;

  ret = max(ret, (idx != 0 && mod == 0) + rec(idx + 1, (s[idx] - '0') % 3, s[idx] != '0'));
  ret = max(ret, rec(idx + 1, (mod + (s[idx] - '0')) % 3, tak));

  return ret;
}

int main() {
  cin >> s;

  memset(dp, -1, sizeof dp);
  cout << rec(0, 0, 0) << endl;

  return 0;
}
