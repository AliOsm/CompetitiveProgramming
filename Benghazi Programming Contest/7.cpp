#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, p, x, y, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d %d %d %d", &n, &p, &x, &y);

		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}

		int result = 0;
		for(int i = 0; i < p; ++i) {
			if(a[i] == 0) {
				result += x;
			} else {
				result += y;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}
