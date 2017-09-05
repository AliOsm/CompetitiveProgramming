#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, t, a[N];

bool can(int mid) {
	for(int i = 0; i <= n - mid; ++i)
		if(a[i + mid] - a[i] <= t)
			return true;
	return false;
}

int main() {
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for(int i = 1; i <= n; ++i)
		a[i] += a[i - 1];

	int l = 1, r = n, mid, res = 0;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(can(mid)) {
			l = mid + 1;
			res = mid;
		} else
			r = mid - 1;
	}

	printf("%d\n", res);

    return 0;
}

