#include <bits/stdc++.h>

using namespace std;

int n, id;
vector<vector<pair<int, long long> > > all;
vector<pair<int, long long> > cur, fin, tmp;
map<int, long long> mp;

bool cmp(vector<pair<int, long long> > a, vector<pair<int, long long> > b) {
	return a[0].second < b[0].second;
}

void work(int idx) {
	cur.clear();
	tmp.clear();

	sort(all[idx].begin(), all[idx].end());

	for(int i = 0, pos; i < all[idx].size(); i += 2) {
		long long val;
		if(i + 1 >= all[idx].size())
			break;

		val = all[idx][i].second * 2;
		pos = all[idx][i + 1].first;

		all[idx][i].second = -1;
		all[idx][i + 1].second = -1;

		if(mp.count(val)) {
			all[mp[val]].push_back({pos, val});
		} else {
			cur.push_back({pos, val});
		}
	}

	if(all[idx].size() & 1) {
		fin.push_back(all[idx].back());
		all[idx].back().second = -1;
	}

	while(true) {
		if(cur.size() <= 1)
			break;

		for(int i = 0, pos; i < cur.size(); i += 2) {
			long long val;
			if(i + 1 >= cur.size())
				break;

			val = cur[i].second * 2;
			pos = cur[i + 1].first;

			if(mp.count(val)) {
				all[mp[val]].push_back({pos, val});
			} else {
				tmp.push_back({pos, val});
			}
		}

		if(cur.size() & 1) {
			fin.push_back(cur.back());
		}

		cur.swap(tmp);
		tmp.clear();
	}

	fin.insert(fin.end(), cur.begin(), cur.end());
}

int main() {
	all.resize(200001);
	id = -1;

	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		if(mp.count(tmp)) {
			all[mp[tmp]].push_back({i, tmp});
		} else {
			mp[tmp] = ++id;
			all[id].push_back({i, tmp});
		}
	}
	++id;

	sort(all.begin(), all.begin() + id, cmp);

	for(int i = 0; i < id; ++i)
		mp[all[i][0].second] = i;

	for(int i = 0; i < id; ++i)
		work(i);

	for(int i = 0; i < id; ++i)
		for(int j = 0; j < all[i].size(); ++j)
			if(all[i][j].second != -1)
				fin.push_back(all[i][j]);

	sort(fin.begin(), fin.end());

	printf("%d\n", int(fin.size()));
	for(int i = 0; i < fin.size(); ++i)
		printf("%lld ", fin[i].second);
	puts("");

  return 0;
}
