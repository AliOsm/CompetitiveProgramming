#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 10;
int n;
pair<int, int> a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		a[i].first = tmp;
		a[i].second = i;
	}
	sort(a, a + n);
	reverse(a, a + n);

	int res = 0;
	for(int i = 0; i < n; ++i)
		res += (a[i].first * i + 1);

	printf("%d\n", res);
	for(int i = 0; i < n; ++i) {
		if(i != 0) printf(" ");
		printf("%d", a[i].second + 1);
	}
	puts("");

	return 0;
}