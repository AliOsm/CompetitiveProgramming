#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, a[101];
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	int res = 1000000;
	for(int i = 0; i < n; ++i) {
		if(k % a[i] == 0) {
			res = min(res, k / a[i]);
		}
	}

	printf("%d\n", res);

	return 0;
}
