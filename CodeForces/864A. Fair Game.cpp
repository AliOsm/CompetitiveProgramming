#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e5 + 1;
int n, m, q, p, k, x, y, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		++a[tmp];
	}

	int cnt = 0;
	for(int i = 0; i < 101; ++i) {
		if(a[i] != 0)
			++cnt;
	}

	if(cnt == 2) {
		for(int i = 0; i < 101; ++i) {
			if(a[i] != 0) {
				if(x == 0)
					x = a[i], q = i;
				else
					y = a[i], p = i;
			}
		}

		if(x == y) {
			puts("YES");
			printf("%d %d\n", q, p);
		} else {
			puts("NO");
		}
	} else {
		puts("NO");
	}

	return 0;
}
