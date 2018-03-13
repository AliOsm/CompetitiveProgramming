#include <bits/stdc++.h>

using namespace std;

string s;
int k, n, bn[27][27], dp[101][27][101];

int rec(int idx, int prv, int cur) {
	if(idx == s.length())
		return 0;

	int &ret = dp[idx][prv][cur];
	if(ret != -1e9)
		return ret;

	ret = max(ret, rec(idx + 1, s[idx] - 'a', cur) + bn[prv][s[idx] - 'a']);
	for(int i = 0; cur < k && i < 26; ++i)
		ret = max(ret, rec(idx + 1, i, cur + 1) + bn[prv][i]);

	return ret;
}

void build_path(int idx, int prv, int cur) {
	if(idx == s.length())
		return;

	int opt = rec(idx, prv, cur);

	if(opt == rec(idx + 1, s[idx] - 'a', cur) + bn[prv][s[idx] - 'a']) {
		cout << s[idx];
		build_path(idx + 1, s[idx] - 'a', cur);
		return;
	}

	for(int i = 0; cur < k && i < 26; ++i) {
		if(opt == rec(idx + 1, i, cur + 1) + bn[prv][i]) {
			cout << char(i + 'a');
			build_path(idx + 1, i, cur + 1);
			return;
		}
	}
}

int main() {
	cin >> s >> k;
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		bn[a - 'a'][b -'a'] = c;
	}

	for(int i = 0; i < 101; ++i)
		for(int j = 0; j < 27; ++j)
			for(int k = 0; k < 101; ++k)
				dp[i][j][k] = -1e9;
	cout << rec(0, 26, 0) << endl;

	return 0;
}