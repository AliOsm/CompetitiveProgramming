#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;

	int fa[26] = {0}, fb[26] = {0}, fc[26] = {0};

	for(int i = 0; i < (int)a.length(); ++i)
		++fa[a[i] - 'a'];
	for(int i = 0; i < (int)b.length(); ++i)
		++fb[b[i] - 'a'];
	for(int i = 0; i < (int)c.length(); ++i)
		++fc[c[i] - 'a'];

	int cb = 0, cc = 0;

	for(int i = 0; i < 1e5 + 1; ++i) {
		int tb = 1e9, tc = 1e9;

		bool ok = true;
		for(int j = 0; j < 26; ++j)
			if(fb[j] != 0 && fa[j] < 1LL * fb[j] * i) {
				ok = false;
				break;
			}

		if(!ok)
			tb = 0;
		else
			tb = i;

		for(int j = 0; j < 26; ++j)
			if(fc[j] != 0)
				tc = min(1LL * tc, max(0LL, (fa[j] - (1LL * fb[j] * tb)) / fc[j]));

		if(tb + tc > cb + cc)
			cb = tb, cc = tc;
	}

	for(int i = 0; i < cb; ++i) cout << b;
	for(int i = 0; i < cc; ++i) cout << c;

	for(int i = 0; i < 26; ++i) {
		fa[i] -= (fb[i] * cb) + (fc[i] * cc);
		for(int j = 0; j < fa[i]; ++j)
			cout << char(i + 'a');
	}
	cout << endl;

	return 0;
}

