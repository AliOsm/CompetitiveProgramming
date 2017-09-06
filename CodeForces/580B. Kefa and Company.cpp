#include <bits/stdc++.h>

using namespace std;

int n, d;
pair<int, int> a[100001];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int can(long long mid) {
	int l = 0, r = 0;
	long long sum = 0;
	while(r < n) {
		sum += a[r].second;

		while(a[r].first - a[l].first >= d) {
			sum -= a[l].second;
			++l;
		}

		if(sum >= mid)
			return true;

		++r;
	}
	return false;
}

int main() {
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a, a + n, cmp);

	long long l = 0, r = 1e14, mid, res = 0;
	while(l <= r){
		mid = (l +r) >> 1;
		if(can(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}

	printf("%lld\n", res);

	return 0;
}

