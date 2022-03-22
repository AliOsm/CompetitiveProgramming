#include <bits/stdc++.h>

using namespace std;

int t, a, b, x, y;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d %d %d %d", &a, &b, &x, &y);

		if(a * b <= x * y) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}
