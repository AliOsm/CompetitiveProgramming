#include <bits/stdc++.h>

using namespace std;

int n, m, k, cost[100001];
vector<string> all;
vector<vector<int> > groups;
map<string, int> mp;

int main() {
	cin >> n >> k >> m;
	all.resize(n);
	for(int i = 0; i < n; ++i)
		cin >> all[i];
	for(int i = 0; i < n; ++i)
		cin >> cost[i];

	groups.resize(k);
	for(int i = 0, tmp; i < k; ++i) {
		cin >> tmp;
		for(int j = 0, cur; j < tmp; ++j) {
			cin >> cur;
			--cur;
			groups[i].push_back(cost[cur]);
			mp[all[cur]] = i;
		}
		sort(groups[i].begin(), groups[i].end());
	}

	string tmp;
	long long res = 0;
	for(int i = 0; i < m; ++i) {
		cin >> tmp;
		res += groups[mp[tmp]][0];
	}

	cout << res << endl;

  return 0;
}
