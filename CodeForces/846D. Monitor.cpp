#include <bits/stdc++.h>

using namespace std;

struct broke {
	int x, y, t;

	bool operator<(const broke &b) const {
		return t < b.t;
	}
};

int const N = 500 * 500 + 1;
int n, m, k, q, cs[501][501];
bool g[501][501];
broke b[N];

bool can(int mid) {
	memset(g, false, sizeof g);

	for(int i = 0; i < q && b[i].t <= mid; ++i)
		g[b[i].x][b[i].y] = true;

	bool res = false;
	for(int i = 1; i <= n && !res; ++i)
		for(int j = 1; j <= m && !res; ++j) {
			cs[i][j] = cs[i - 1][j] + cs[i][j - 1] - cs[i - 1][j - 1] + g[i][j];

			if(i >= k && j >= k && cs[i][j] - cs[i - k][j] - cs[i][j - k] + cs[i - k][j - k] == k * k)
				res = true;
		}

	for(int i = 0; i < q && b[i].t <= mid; ++i)
		g[b[i].x][b[i].y] = false;

	return res;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 0; i < q; ++i)
		scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].t);
	sort(b, b + q);

	int l = 0, r = 1e9 + 1, mid, res = -1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(can(mid)) {
			r = mid - 1;
			res = mid;
		} else
			l = mid + 1;
	}

	printf("%d\n", res);

	return 0;
}
