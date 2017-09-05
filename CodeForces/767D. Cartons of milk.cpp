#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1, M = 1e7 + 1;
int n, m, k, f[N], fr[M];
pair<int, int> s[N];
vector<int> all;

bool can(int mid) {
	memset(fr, 0, sizeof fr);

	for(int i = 0; i < n; ++i)
		++fr[f[i]];
	for(int i = 0; i < mid; ++i)
		++fr[s[i].first];

	int day = 0, c = 0;
	for(int i = 0; i < (int)all.size(); ++i) {
		while(fr[all[i]]) {
			if(c == k) {
				c = 0;
				++day;
			}

			if(day > all[i])
				return false;

			++c;
			--fr[all[i]];
		}
	}

	return true;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", f + i);
		all.push_back(f[i]);
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d", &s[i].first);
		all.push_back(s[i].first);
		s[i].second = i + 1;
	}
	sort(s, s + m);
	reverse(s, s + m);

	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());

	int l = 0, r = m, mid, res = -1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(can(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}

	printf("%d\n", res);
	for(int i = 0; i < res; ++i)
		printf("%d ", s[i].second);

    return 0;
}

