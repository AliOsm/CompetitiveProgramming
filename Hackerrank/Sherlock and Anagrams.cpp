#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> mp;
string s, tmp;

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		mp.clear();
		cin >> s;

		for(int i = 0; i < (int)s.length(); ++i)
			for(int j = 1; j <= (int)s.length() - i; ++j) {
				tmp = s.substr(i, j);
				sort(tmp.begin(), tmp.end());
				++mp[tmp];
			}

		int res = 0, tmp;
		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it)
			if(it->second >= 2) {
				tmp = it->second;
				res += tmp * (tmp - 1) / 2;
			}

		printf("%d\n", res);
	}

    return 0;
}

