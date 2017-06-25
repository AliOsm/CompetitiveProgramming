#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int n, q, l, r, len, k, a[100001], spt[100001][17];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n; ++i)
		spt[i][0] = i;

	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 0; i + (1 << j) - 1 < n; ++i)
			if(a[spt[i][j - 1]] <= a[spt[i + (1 << (j - 1))][j - 1]])
				spt[i][j] = spt[i][j - 1];
			else
				spt[i][j] = spt[i + (1 << (j - 1))][j - 1];

	scanf("%d", &q);
	while(q-- != 0) {
		scanf("%d %d", &l, &r);
		len = r - l + 1;
		k = log2(len);
		printf("%d\n", min(a[spt[l][k]], a[spt[l + len - (1 << k)][k]]));
	}
}

