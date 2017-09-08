#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	long long res = 0;
	for(int i = 0; i < n;) {
		int j = i;
		for(; j < n - 1 && a[j] > a[j + 1]; ++j);
		if(j > i) {
			res += a[i] - a[j];
			i = j + 1;
		} else {
			++i;
		}
	}
	printf("%lld\n", res);

	return 0;
}

