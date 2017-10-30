#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;

int str_to_int(string t) {
	int res = 0;
	for(int i = 0; i < (int)t.size(); ++i) {
		res *= 10;
		res += t[i] - '0';
	}
	return res;
}

ll n, a[100001];

bool can(double mid) {
	for(int i = 0; i < n; ++i) {
		if(a[i] > mid)
			mid -= (a[i] - mid);
		else
			mid += (mid - a[i]);

		if(mid < 0)
			return false;
	}

	return true;
}

int main() {
	scanf("%lld", &n);
	for(int i = 0; i < n; ++i)
		scanf("%lld", a + i);

	ll l = 0, r = 1e5 + 1, mid, res = 0;
	while(l <= r) {
		mid = (l + r) / 2;
		if(can(mid)) {
			res = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}

	printf("%lld\n", res);

	return 0;
}

