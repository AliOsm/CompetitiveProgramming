#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int t, n, sum;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		sum = 0;

		scanf("%d", &n);

		for(int i = 0, tmp; i < n; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
		}

		if(sum & 1) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}
