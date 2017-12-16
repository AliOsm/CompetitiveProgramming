#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
map<string, vector<string> > mp;
vector<string> tmp;
set<string> sol;

int main() {
	cin >> n;

	string name, cur;
	int ent;
	for(int i = 0; i < n; ++i) {
		cin >> name >> ent;
		for(int j = 0; j < ent; ++j) {
			cin >> cur;
			mp[name].push_back(cur);
		}
	}

	cout << mp.size() << endl;
	for(map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); ++it) {
		tmp.clear();
		tmp = it->second;

		sort(tmp.begin(), tmp.end());
		tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

		sol.clear();
		for(int i = 0; i < (int)tmp.size(); ++i) {
			bool ok = true;
			for(int j = 0; j < (int)tmp.size(); ++j) {
				if(i != j) {
					if(tmp[i] == tmp[j])
						break;
					if(tmp[j].size() > tmp[i].size()) {
						bool ok1 = true;
						for(int k = tmp[j].size() - 1, l = tmp[i].size() - 1; l >= 0; --k, --l) {
							if(tmp[j][k] != tmp[i][l]) {
								ok1 = false;
								break;
							}
						}
						if(ok1) {
							ok = false;
							break;
						}
					}
				}
			}
			if(ok)
				sol.insert(tmp[i]);
		}

		cout << it->first << ' ' << sol.size();
		for(set<string>::iterator it = sol.begin(); it != sol.end(); ++it)
			cout << ' ' << *it;
		cout << endl;
	}

	return 0;
}
