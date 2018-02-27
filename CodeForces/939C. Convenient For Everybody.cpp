#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int n, a[N], cs[N], s, f;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i + n] = a[i];
	}
	scanf("%d %d", &s, &f);
	--s, --f;

	cs[0] = a[0];
	for(int i = 1; i < 2*n; ++i)
		cs[i] = a[i] + cs[i - 1];

	int mx = 0, idx, cnt = s;
	for(int i = 1; i <= n; ++i) {
		if(mx < cs[cnt + (f - s - 1)] - cs[cnt - 1]) {
			mx = cs[cnt + (f - s - 1)] - cs[cnt - 1];
			idx = i;
		}

		--cnt;
		if(cnt < 0)
			cnt += n;
	}

	printf("%d\n", idx);

	return 0;
}

