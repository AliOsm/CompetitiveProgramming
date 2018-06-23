/*
	Idea:
		- Using Segment tree to calculate the maximum in range.
		- Then using Two pointers to calculate the maximum segment.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 10;
int n, m, k, a[N][6], sum[N], seg[4 * N][6];

void build(int at, int l, int r) {
	if(l == r) {
		for(int i = 1; i <= m; ++i)
			seg[at][i] = a[l][i];
		return;
	}

	int mid = (l + r) >> 1;
	build(at << 1, l, mid);
	build(at << 1 | 1, mid + 1, r);

	for(int i = 1; i <= m; ++i)
		seg[at][i] = max(seg[at << 1][i], seg[at << 1 | 1][i]);
}

int s, e, tar;
int get(int at, int l, int r) {
	if(l > e || r < s)
		return 0;

	if(l >= s && r <= e)
		return seg[at][tar];

	int mid = (l + r) >> 1;
	return max(get(at << 1, l, mid), get(at << 1 | 1, mid + 1, r));
}

int calc(int l, int r) {
	int sum = 0;
	s = l, e = r;
	for(int i = 1; i <= m; ++i) {
		tar = i;
		sum += get(1, 1, n);
	}
	return sum;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
			sum[i] += a[i][j];
		}

	build(1, 1, n);

	int l = 1, r = 1, r1, r2, len = 0;
	while(r <= n) {
		while(l < r && calc(l, r) > k)
			++l;

		if(calc(r, l) <= k && r - l + 1 > len)
			len = r - l + 1, r1 = l, r2 = r;;

		++r;
	}

	s = r1, e = r2;
	for(int i = 1; i <= m; ++i) {
		tar = i;
		printf("%s%d", i == 1 ? "" : " ", get(1, 1, n));
	}
	puts("");

  return 0;
}
