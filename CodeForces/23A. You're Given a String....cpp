#include <iostream>
#include <algorithm>
#include <string>
#include <map>

typedef long long ll;

using namespace std;

map<string, int> mp;

int main() {
	string s, tmp;
	cin >> s;

	for(int i = 0; i < (int)s.length(); ++i)
		for(int j = 0; j <= (int)s.length() - i; ++j) {
			tmp = s.substr(i, j);
			if(tmp != "")
				mp[tmp]++;
		}

	map<string, int>::iterator it;
	int res = 0;
	for(it = mp.begin(); it != mp.end(); it++)
		if(it->second >= 2)
			res = max(res, (int)it->first.length());

	cout << res << endl;

	return 0;
}

