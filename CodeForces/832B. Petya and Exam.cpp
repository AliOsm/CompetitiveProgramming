#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <string>
#include <memory.h>
#include <cmath>
#include <cctype>

using namespace std;

string goods, pat, tmp;
bool goodChars[26], badChars[26];
int q, star = -1;

int main() {
	cin >> goods >> pat >> q;

	memset(goodChars, false, sizeof goodChars);
	memset(badChars, true, sizeof badChars);
	for(int i = 0; i < (int)goods.size(); ++i) {
		goodChars[goods[i] - 'a'] = true;
		badChars[goods[i] - 'a'] = false;
	}

	for(int i = 0; i < (int)pat.size(); ++i)
		if(pat[i] == '*')
			star = i;

	if(star != -1)
		pat.erase(star, 1);

	bool ok;
	while(q-- != 0) {
		ok = true;
		cin >> tmp;

		if(star == -1) {
			if(pat.size() != tmp.size()) {
				puts("NO");
				continue;
			}

			for(int i = 0; i < (int)pat.size() && i < (int)tmp.size(); ++i)
				if(isalpha(pat[i]) && pat[i] != tmp[i]) {
					ok = false;
					break;
				} else if(pat[i] == '?' && badChars[tmp[i] - 'a']) {
					ok = false;
					break;
				}
			if(!ok) {
				puts("NO");
				continue;
			}
		}

		if(star != -1) {
			if(tmp.size() < pat.size()) {
				puts("NO");
				continue;
			}

			int diff = abs((int)(pat.size()) - (int)tmp.size());
			string seg = tmp.substr(star, diff);
			tmp.erase(star, diff);
			for(int i = 0; i < (int)seg.size(); ++i)
				if(goodChars[seg[i] - 'a']) {
					ok = false;
					break;
				}

			if(!ok) {
				puts("NO");
				continue;
			}

			for(int i = 0; i < (int)pat.size() && i < (int)tmp.size(); ++i)
				if(isalpha(pat[i]) && pat[i] != tmp[i]) {
					ok = false;
					break;
				} else if(pat[i] == '?' && badChars[tmp[i] - 'a']) {
					ok = false;
					break;
				}

			if(!ok) {
				puts("NO");
				continue;
			}
		}

		puts("YES");
	}

	return 0;
}
