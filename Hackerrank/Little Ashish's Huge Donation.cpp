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

ll x;

bool can(int mid) {
	if(1LL * mid * (mid + 1) * (2 * mid + 1) / 6 <= x)
		return true;
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%lld", &x);

		int l = 1, r = 1e6, mid, res = 1;
		while(l <= r) {
			mid = (l + r) / 2;
			if(can(mid)) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;
		}

		printf("%d\n", res);
	}

	return 0;
}

