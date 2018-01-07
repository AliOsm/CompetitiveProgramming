#include <bits/stdc++.h>

using namespace std;

string s;
bool light[26];
char srcm, srct, lstsrcm;
int k, cnt;

char nxt() {
	string tmp = ":";
	tmp = srcm + tmp;
	if(s.find(tmp) == string::npos)
		return ' ';

	int cur = s.find(tmp) + 2;

	while(s[cur] != ';' && s[cur] != '.') {
		if(s[cur] != srct && !light[s[cur] - 'A'] && s[cur] != lstsrcm)
			return s[cur];
		++cur;
	}

	return ' ';
}

int main() {
	while(getline(cin, s) && s != "#") {
		memset(light, false, sizeof light);
		lstsrcm = ' ';
		cnt = 0;
		k = 0;

		srcm = s[s.find('.') + 2];
		srct = s[s.find('.') + 4];
		for(int i = s.find('.') + 6; i < s.length(); ++i)
			k *= 10, k += s[i] - '0';

		cnt = 0;
		while((lstsrcm = srcm, srcm = nxt()) && srcm != ' ') {
			srct = lstsrcm;

			++cnt;
			if(cnt == k) {
				cnt = 0;
				light[srct - 'A'] = true;
				cout << srct << ' ';
			}
		}

		cout << "/" << lstsrcm << endl;
	}

	return 0;
}

