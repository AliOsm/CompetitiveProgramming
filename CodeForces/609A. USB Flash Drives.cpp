#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, a[101], res = 0;
	scanf("%d\n%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n; ++i) {
		if(m <= 0)
			break;
		int mx = -1, idx;
		for(int j = 0; j < n; ++j) {
			if(a[j] > mx) {
				mx = a[j];
				idx = j;
			}
		}
		if(mx != -1) {
			a[idx] = -1;
			m -= mx;
		}
		++res;
	}

	if(m <= 0)
		printf("%d\n", res);
	else
		puts("-1");

	return 0;
}

