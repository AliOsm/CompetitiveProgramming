#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1, oo = 2e9;
int n, m, q, k, x, y, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	int res = 0;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j)
			if((a[i] + a[j]) & 1)
				++res;
	printf("%d\n", res);

	return 0;
}

