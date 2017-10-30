#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
	int n, a[100001];
	ll res = 1e18 + 1;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	for(int i = 1; i < n; ++i)
		res = min(res, abs(1LL * a[i - 1] - a[i]));
	printf("%lld\n", res);

	return 0;
}

