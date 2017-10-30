#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int str_to_int(string t) {
	int res = 0;
	for(int i = 0; i < (int)t.size(); ++i) {
		res *= 10;
		res += t[i] - '0';
	}
	return res;
}

int q;
string s;

int main() {
	// freopen("in", "r", stdin);

	scanf("%d", &q);
	while(q-- != 0) {
		cin >> s;

		if(s.size() == 1) {
			cout << "NO" << endl;
			continue;
		}

		bool ok;
		for(int l = 1; l < (int)s.length() + 1 / 2; ++l) {
			ok = true;

			int lst = str_to_int(s.substr(0, l));

			for(int i = l, add = 0; i < (int)s.length(); i += l + add) {
				string t = s.substr(i, l + add);
				if(t[0] == '0') {
					ok = false;
					break;
				}

				int tmp = str_to_int(s.substr(i, l + add));
				if(tmp - 1 == lst) {
					lst = tmp;
					continue;
				}

				tmp = str_to_int(s.substr(i, l + add + 1));
				if(tmp - 1 == lst) {
					lst = tmp;
					++add;
					continue;
				}

				ok = false;
				break;
			}
			if(ok) {
				cout << "YES " << s.substr(0, l) << endl;
				break;
			}
		}

		if(!ok) {
			cout << "NO" << endl;
		}
	}

	return 0;
}

