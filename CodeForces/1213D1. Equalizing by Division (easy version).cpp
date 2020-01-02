#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 10;
int n, k, a[N], fr[N], frp[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);

	int res = 1e9;
	for(int i = 0; i < n; ++i) {
		int cur = a[i], cnt = 0;
		while(cur >= 0) {
			++fr[cur];
			frp[cur] += cnt;
			if(fr[cur] >= k)
				res = min(res, frp[cur]);
			if(cur == 0)
				break;
			cur /= 2;
			++cnt;
		}
	}

	printf("%d\n", res);

	return 0;
}