#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<string> all;

	bool ok = false;
	while(n-- != 0) {
		string s;
		cin >> s;

		if(!ok && s[0] == 'O' && s[1] == 'O') {
			s[0] = s[1] = '+';
			ok = true;
		} else if(!ok && s[3] == 'O' && s[4] == 'O') {
			s[3] = s[4] = '+';
			ok = true;
		}

		all.push_back(s);
	}

	if(ok) {
		cout << "YES" << endl;
		for(int i = 0; i < all.size(); ++i)
			cout << all[i] << endl;
	} else
		cout << "NO" << endl;

	return 0;
}
