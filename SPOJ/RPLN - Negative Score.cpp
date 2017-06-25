#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int n, q, l, r, k, a[100001], spt[100001][17];

int main() {
	int t;
	scanf("%d", &t);
	for(int cnt = 1; t-- != 0; ++cnt) {
		printf("Scenario #%d:\n", cnt);

		scanf("%d %d", &n, &q);

		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);

		for(int i = 0; i < n; ++i)
			spt[i][0] = i;

		for(int j = 1; (1 << j) <= n; ++j)
			for(int i = 0; i + (1 << j) - 1 < n; ++i)
				if(a[spt[i][j - 1]] < a[spt[i + (1 << (j - 1))][j - 1]])
					spt[i][j] = spt[i][j - 1];
				else
					spt[i][j] = spt[i + (1 << (j - 1))][j - 1];

		while(q-- != 0) {
			scanf("%d %d", &l, &r);
			l--, r--;

			k = 0;
			while((1 << k) <= r - l + 1)
				++k;
			--k;

			printf("%d\n", min(a[spt[l][k]], a[spt[r - (1 << k) + 1][k]]));
		}
	}
}

