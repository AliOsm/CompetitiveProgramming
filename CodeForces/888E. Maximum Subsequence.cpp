#include <bits/stdc++.h>

using namespace std;

int n, m, a[35];
vector<int> all[2];

void rec(int idx, int end, int val, int cur) {
	if(idx == end) {
		all[cur].push_back(val);
		return;
	}

	rec(idx + 1, end, (val + a[idx]) % m, cur);
	rec(idx + 1, end, val, cur);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);

	rec(0, n / 2, 0, 0);
	rec(n / 2, n, 0, 1);

	sort(all[1].begin(), all[1].end());

	int best = 0;
	for(int i = 0; i < all[0].size(); ++i) {
		int dif = m - all[0][i];

		if(dif <= 0) {
			best = max(best, (all[0][i] + all[1].back()) % m);
		} else {
			int idx = upper_bound(all[1].begin(), all[1].end(), dif - 1) - all[1].begin();
			--idx;

			if(idx >= 0) {
				best = max(best, (all[0][i] + all[1][idx]) % m);
			} else {
				best = max(best, (all[0][i] + all[1].back()) % m);
			}
		}
	}

	cout << best << endl;

	return 0;
}
