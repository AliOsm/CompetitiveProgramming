#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a, b, c;
	scanf("%d %d %d %d", &n, &a, &b, &c);

	int res = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j) {
			int need = n - (i * a + j * b);
			if(need >= 0 && need % c == 0)
				res = max(res, i + j + need / c);
		}

	printf("%d\n", res);

	return 0;
}

