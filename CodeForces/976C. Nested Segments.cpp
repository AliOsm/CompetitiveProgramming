#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int t, n, m;
pair<pair<int, int>, int> seg[N];

bool check(int i, int j) {
	if(seg[i].first.first <= seg[j].first.first && seg[i].first.second >= seg[j].first.second)
		return true;
	return false;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &seg[i].first.first, &seg[i].first.second);
		seg[i].second = i + 1;
	}

	if(n == 1) {
		puts("-1 -1");
		return 0;
	}

	sort(seg, seg + n);

	for(int i = 1; i < n; ++i) {
		if(check(i, i - 1)) {
			printf("%d %d\n", seg[i - 1].second, seg[i].second);
			return 0;
		} else if(check(i - 1, i)) {
			printf("%d %d\n", seg[i].second, seg[i - 1].second);
			return 0;
		}
	}

	puts("-1 -1");

	return 0;
}
