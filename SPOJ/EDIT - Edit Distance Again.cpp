#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;
int dp[N][2];
string s;

int rec(int i, bool c) {
	if(i == s.length()) {
		return 0;
	}

	int &res = dp[i][c];
	if(res != -1) {
		return res;
	}
	res = 1e9;

	if(c) {
		if(islower(s[i])) {
			res = min(res, rec(i + 1, false));
		} else {
			res = min(res, rec(i + 1, true) + 1);
		}
	} else {
		if(islower(s[i])) {
			res = min(res, rec(i + 1, false) + 1);
		} else {
			res = min(res, rec(i + 1, true));
		}
	}

	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	while(cin >> s) {
		memset(dp, -1, sizeof dp);
		cout << rec(0, islower(s[0])) << endl;
	}

	return 0;
}
