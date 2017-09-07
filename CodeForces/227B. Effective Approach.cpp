#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, q, a[N];
vector<int> idx[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		idx[a[i]].push_back(i + 1);
	}

	scanf("%d", &q);
	int tmp;
	long long l = 0, r = 0;
	while(q-- != 0) {
		scanf("%d", &tmp);
		l += idx[tmp].front();
		r += n - idx[tmp].back() + 1;
	}

	printf("%lld %lld\n", l, r);

	return 0;
}
