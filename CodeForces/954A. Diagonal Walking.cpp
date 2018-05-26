/*
	Idea:
		- Dynamic Programming, in each step if we have "RU" or "UR" from the current
			index try to delete it and add 1 to the answer, of leave it and move to the
			next index.
*/

#include <bits/stdc++.h>

using namespace std;

int n, dp[101][2];
string s;

int rec(int idx, bool tak) {
	if(idx >= n)
		return 0;

	int &ret = dp[idx][tak];
	if(ret != -1)
		return ret;
	ret = rec(idx + 1, 0);

	if(idx + 1 < n && s.substr(idx, 2) == "RU" || s.substr(idx, 2) == "UR")
		ret = max(rec(idx + 2, true) + 1, ret);

	return ret;
}

int main() {
  cin >> n >> s;
  memset(dp, -1, sizeof dp);
  cout << (n - 2 * rec(0, 0)) + rec(0, 0) << endl;

  return 0;
}
