#include <bits/stdc++.h>

using namespace std;

vector<int> inv;

int main() {
	int n, a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;

	for(int i = 0; i < s.length(); ++i) {
		if(s[i] == '.') {
			int t1 = i;
			while(i < s.length() && s[i] == '.') {
				++i;
			}
			int t2 = i - 1;
			inv.push_back(t2 - t1 + 1);
		}
	}

	if(inv.size() == 0) {
		cout << 0 << endl;
		return 0;
	}

	int res = 0;
	for(int i = 0; i < inv.size(); ++i) {
		if(inv[i] % 2 == 0) {
			if(a >= inv[i] / 2) {
				a -= inv[i] / 2;
				res += inv[i] / 2;
			} else {
				res += a;
				a -= a;
			}

			if(b >= inv[i] / 2) {
				b -= inv[i] / 2;
				res += inv[i] / 2;
			} else {
				res += b;
				b -= b;
			}
		} else {
			int t1 = inv[i] / 2, t2 = inv[i] - t1;

			if(a > b) {
				if(b >= t1) {
					b -= t1;
					res += t1;
				} else {
					res += b;
					b -= b;
				}

				if(a >= t2) {
					a -= t2;
					res += t2;
				} else {
					res += a;
					a -= a;
				}
			} else {
				if(a >= t1) {
					a -= t1;
					res += t1;
				} else {
					res += a;
					a -= a;
				}

				if(b >= t2) {
					b -= t2;
					res += t2;
				} else {
					res += b;
					b -= b;
				}
			}
		}
	}

	cout << res << endl;

  return 0;
}
