/*
  Idea:
    - We can solve this problem using Dynamic programming and bit masking.
    - For each query start with mask contains zeros only and where are
      we now in the mask.
    - In each state try to put each number i (0 <= i <= n - 1) in the current
      mask if the i_th bit is not set and the idx does not equal i.
*/

#include <bits/stdc++.h>

using namespace std;

int t, n, dp[(1 << 13)][13];

int rec(int msk, int idx) {
  if(idx == -1)
    return 1;
  
  int &ret = dp[msk][idx];
  if(ret != -1)
    return ret;
  ret = 0;

  for(int i = 0; i < n; ++i)
    if(i != idx && ((msk >> i) & 1) == 0)
      ret += rec(msk | (1 << i), idx - 1);
  
  return ret;
}

int main() {
  memset(dp, -1, sizeof dp);

  long long facts[20] = {1};
  for(int i = 1; i < 20; ++i)
    facts[i] = facts[i - 1] * i;
  
  cin >> t;
  while(t-- != 0) {
    cin >> n;
    cout << rec(0, n - 1) << '/' << facts[n] << endl;
  }

  return 0;
}
