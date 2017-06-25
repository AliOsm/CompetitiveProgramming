#include <iostream>

using namespace std;

int n;
string s;

int main() {
	cin >> n >> s;

	int a = 0, c = 0, g = 0, t = 0;
	for(int i = 0; i < (int)s.length(); ++i)
		switch(s[i]) {
		case 'A': ++a; break;
		case 'C': ++c; break;
		case 'G': ++g; break;
		case 'T': ++t; break;
		}

	int opt = (int)s.length() / 4;
	a = a - opt <= 0 ? 0 : a - opt;
	c = c - opt <= 0 ? 0 : c - opt;
	g = g - opt <= 0 ? 0 : g - opt;
	t = t - opt <= 0 ? 0 : t - opt;

	int l = 0, r = 0, res = 1e6 + 1;
	int ta = 0, tc = 0, tg = 0, tt = 0;
	while(r < n) {
		if(ta >= a && tc >= c && tg >= g && tt >= t)
			res = min(res, r - l);

		switch(s[r++]) {
		case 'A': ++ta; break;
		case 'C': ++tc; break;
		case 'G': ++tg; break;
		case 'T': ++tt; break;
		}

		while((ta > a && a > 0 && s[l] == 'A') || (tc > c && c > 0 && s[l] == 'C') ||
			  (tg > g && g > 0 && s[l] == 'G') || (tt > t && t > 0 && s[l] == 'T') ||
			  (ta > 0 && a == 0 && s[l] == 'A') || (tc > 0 && c == 0 && s[l] == 'C') ||
			  (tg > 0 && g == 0 && s[l] == 'G') || (tt > 0 && t == 0 && s[l] == 'T')) {
			if(ta >= a && tc >= c && tg >= g && tt >= t)
				res = min(res, r - l);

			switch(s[l++]) {
			case 'A': --ta; break;
			case 'C': --tc; break;
			case 'G': --tg; break;
			case 'T': --tt; break;
			}
		}
	}

	cout << res << endl;

    return 0;
}

