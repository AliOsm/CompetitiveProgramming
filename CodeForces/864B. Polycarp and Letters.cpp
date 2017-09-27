#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int n, m, q, p, k, x, y, a[N];
string s, tmp = "";
vector<string> all;

int dist(string t) {
	int fr[26] = { 0 };
	for(int i = 0; i < (int)t.length(); ++i)
		++fr[t[i] - 'a'];
	int ret = 0;
	for(int i = 0; i < 26; ++i)
		if(fr[i] != 0)
			++ret;
	return ret;
}

int main() {
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		if(islower(s[i]))
			tmp += s[i];
		else {
			if(!tmp.empty())
				all.push_back(tmp);
			tmp = "";
		}
	}
	if(!tmp.empty())
		all.push_back(tmp);

	int res = 0;
	for(int i = 0; i < (int)all.size(); ++i)
		res = max(res, dist(all[i]));
	cout << res << endl;

	return 0;
}
