#include <bits/stdc++.h>

using namespace std;

int t, xa, xb, xc;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d %d %d", &xa, &xb, &xc);

		if(xa > 50) {
			puts("A");
		} else if(xb > 50) {
			puts("B");
		} else if(xc > 50) {
			puts("C");
		} else {
			puts("NOTA");
		}
	}

	return 0;
}
