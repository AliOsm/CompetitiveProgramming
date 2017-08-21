#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 1e5 + 1;
int n, q, seg[4 * N][3], lazy[4 * N], s, e;

void build(int idx, int l, int r) {
	if(l == r) {
		++seg[idx][0];
		return;
	}

	int m = (l + r) >> 1;
	build(idx << 1, l, m);
	build((idx << 1) + 1, m + 1, r);
	seg[idx][0] = seg[idx << 1][0] + seg[(idx << 1) + 1][0];
}

inline void pro(int idx, int l, int r) {
	int m = lazy[idx] % 3;
	for(int i = 0; i < m; ++i)
		swap(seg[idx][1], seg[idx][2]),
		swap(seg[idx][0], seg[idx][1]);

	if(l != r)
		lazy[idx << 1] += lazy[idx],
		lazy[(idx << 1) + 1] += lazy[idx];

	lazy[idx] = 0;
}

void update(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(e < l || s > r)
		return;

	if(l >= s && r <= e) {
		++lazy[idx];
		pro(idx, l, r);
		return;
	}

	int m = (l + r) >> 1;
	update(idx << 1, l, m);
	update((idx << 1) + 1, m + 1, r);
	for(int i = 0; i < 3; ++i)
		seg[idx][i] = seg[idx << 1][i] + seg[(idx << 1) + 1][i];
}

int get(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(e < l || s > r)
		return 0;

	if(l >= s && r <= e)
		return seg[idx][0];

	int m = (l + r) >> 1;
	return get(idx << 1, l, m) + get((idx << 1) + 1, m + 1, r);
}

int main() {
	scanf("%d %d", &n, &q);
	build(1, 1, n);
	int t, a, b;
	while(q-- != 0) {
		scanf("%d %d %d", &t, &a, &b);
		++a, ++b;
		if(t == 0) {
			s = a, e = b;
			update(1, 1, n);
		} else {
			s = a, e = b;
			printf("%d\n", get(1, 1, n));
		}
	}

    return 0;
}

