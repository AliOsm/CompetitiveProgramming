#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, a[N], b[N], suma, sumb;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		suma = sumb = 0;

		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
		}

		for(int i = 0; i < n; ++i) {
			scanf("%d", b + i);
			sumb += b[i];
		}

		int result = sumb;
		for(int i = 0; i < n; ++i) {
			suma += a[i];
			sumb -= b[i];
			result = max(result, suma + sumb);
		}

		printf("%d\n", result);
	}

	return 0;
}
