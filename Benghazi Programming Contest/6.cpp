#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, k, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d %d", &n, &k);

		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}

		int i = 0, current = 0;
		for(; i < n; ++i) {
			current += a[i];
			current -= k;

			if(current < 0) {
				break;
			}
		}

		if(i != n) {
			printf("NO %d\n", i + 1);
		} else {
			puts("YES");
		}
	}

	return 0;
}
