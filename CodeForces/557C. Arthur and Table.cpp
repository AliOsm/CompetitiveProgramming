#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, cs[N][201];
pair<int, int> all[N];
set<int> st;
map<int, pair<int, int> > mp;

int work(int val) {
	int ret = 0;

	int s = mp[val].first, e = mp[val].second;

	for(int i = 0; i < 201; ++i)
		ret += i * (cs[n - 1][i] - cs[e][i]);

	int mxr = e - s + 1;
	int otr = s;

	if(mxr == otr) {
		for(int i = 0; i < 201; ++i)
			if(cs[s - 1][i] != 0) {
				ret += i;
				break;
			}
	} else if(mxr < otr) {
		int need = otr - mxr + 1;
		for(int i = 0; need > 0 && i < 201; ++i) {
			if(cs[s - 1][i] >= need) {
				ret += i * need;
				break;
			}
			else {
				need -= cs[s - 1][i];
				ret += i * cs[s - 1][i];
			}
		}
	}

	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &all[i].first);
		st.insert(all[i].first);
	}
	for(int i = 0; i < n; ++i)
		scanf("%d", &all[i].second);
	sort(all, all + n);

	if(n == 1) {
		puts("0");
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		if(mp.count(all[i].first))
			mp[all[i].first].second = i;
		else {
			mp[all[i].first].first = i;
			mp[all[i].first].second = i;
		}
	}

	++cs[0][all[0].second];
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < 201; ++j)
			cs[i][j] = cs[i - 1][j];
		++cs[i][all[i].second];
	}

	int res = 2e9;
	for(set<int>::iterator it = st.begin(); it != st.end(); ++it)
		res = min(res, work(*it));

	printf("%d\n", res);

  return 0;
}
