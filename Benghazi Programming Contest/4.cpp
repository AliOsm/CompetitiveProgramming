#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}

		sort(a, a + n);

		int result = 2e9;
		for(int i = 1; i < n; ++i) {
			result = min(result, a[i] - a[i - 1]);
		}

		printf("%d\n", result);
	}

	return 0;
}
