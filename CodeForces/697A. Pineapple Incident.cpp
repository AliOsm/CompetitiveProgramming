#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, s, x;
	scanf("%d %d %d", &t, &s, &x);

	if(x >= t && (t - x) % s == 0) {
		puts("YES");
		return 0;
	}

	--x;

	if(x > t && (t - x) % s == 0) {
		puts("YES");
		return 0;
	}

	puts("NO");

	return 0;
}

