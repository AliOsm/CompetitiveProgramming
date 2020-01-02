#include <bits/stdc++.h>

using namespace std;

int n;
string s, t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	cin >> s >> t;

	string per = "abc";

	do {
		string res;

		res = "";
		for(int i = 0; i < n; ++i)
			res += per;
		if(res.find(s) == string::npos && res.find(t) == string::npos) {
			cout << "YES" << endl << res << endl;
			return 0;
		}

		res = "";
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < n; ++j)
				res += per[i];
		if(res.find(s) == string::npos && res.find(t) == string::npos) {
			cout << "YES" << endl << res << endl;
			return 0;
		}
	} while(next_permutation(per.begin(), per.end()));

	puts("NO");

	return 0;
}