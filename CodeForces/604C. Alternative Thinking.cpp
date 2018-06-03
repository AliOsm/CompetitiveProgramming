/*
	Idea:
		- We can solve this problem using Dynamic Programming.
		- The state is the index, have I flip a substring or not?, am I still
			flipping? and the last character.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, dp[N][2][2][3];
string s;

int rec(int idx, bool tak, bool til, int lst) {
  if(idx == n)
    return 0;

  int &ret = dp[idx][tak][til][lst];
  if(ret != -1)
    return ret;
  ret = rec(idx + 1, tak, til, lst);

  if(!tak) {
    if(s[idx] - '0' != lst)
      ret = max(ret, rec(idx + 1, tak, til, s[idx] - '0') + 1);
    if(s[idx] - '0' == lst)
      ret = max(ret, rec(idx + 1, true, true, !(s[idx] - '0')) + 1);
  } else {
    if(!til) {
      if(s[idx] - '0' != lst)
        ret = max(ret, rec(idx + 1, tak, til, s[idx] - '0') + 1);
    } else {
      if(s[idx] - '0' != lst)
        ret = max(ret, rec(idx + 1, tak, false, s[idx] - '0') + 1);
      if(s[idx] - '0' == lst)
        ret = max(ret, rec(idx + 1, tak, til, !(s[idx] - '0')) + 1);
    }
  }

  return ret;
}

int main() {
  cin >> n >> s;

  memset(dp, -1, sizeof dp);
  int res = 0;
  for(int i = 0; i < n; ++i)
    res = max(res, rec(i, 0, 0, 2));
  cout << res << endl;

  return 0;
}
