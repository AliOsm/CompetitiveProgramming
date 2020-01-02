#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int t, n, a[N], mn, res;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &t);
	while(t-- != 0) {
		mn = 1e9;
		res = 0;

		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);

		for(int i = n - 1; i >= 0; --i) {
			if(a[i] > mn)
				++res;
			mn = min(mn, a[i]);
		}

		printf("%d\n", res);
	}

	return 0;
}