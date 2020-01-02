#include <bits/stdc++.h>

using namespace std;

int q, n, sum;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		sum = 0;

		scanf("%d", &n);
		for(int j = 0, tmp; j < n; ++j)
			scanf("%d", &tmp), sum += tmp;

		printf("%d\n", (sum + (n - 1)) / n);
	}

	return 0;
}