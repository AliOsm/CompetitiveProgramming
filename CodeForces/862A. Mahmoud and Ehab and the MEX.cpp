#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1, oo = 2e9;
int n, m, q, k, x, y, a[N];
pair<int, int> aa[N];

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		++a[tmp];
	}

	int res = 0;
	for(int i = 0; i < x; ++i)
		if(a[i] == 0)
			++res;
	if(a[x] > 0)
		res += a[x];

	printf("%d\n", res);

	return 0;
}
