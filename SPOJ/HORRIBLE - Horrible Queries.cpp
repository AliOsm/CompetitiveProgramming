#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1e5 + 1;
int n, q;
long long seg[4 * N], lazy[4 * N];

int s, e, v;

void pro(int idx, int l, int r) {
	seg[idx] += lazy[idx] * (r - l + 1);
	if(l != r)
		lazy[idx << 1] += lazy[idx],
		lazy[(idx << 1) + 1] += lazy[idx];
	lazy[idx] = 0;
}

void update(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(s > r || e < l)
		return;

	if(l >= s && r <= e) {
		lazy[idx] += v;
		pro(idx, l, r);
		return;
	}

	int m = (l + r) >> 1;
	update(idx << 1, l, m);
	update((idx << 1) + 1, m + 1, r);
	seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

long long get(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(s > r || e < l)
		return 0;

	if(l >= s && r <= e)
		return seg[idx];

	int m = (l + r) >> 1;
	return get(idx << 1, l, m) + get((idx << 1) + 1, m + 1, r);
}

int main() {
	int t, type;
	scanf("%d", &t);
	while(t-- != 0) {
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		scanf("%d %d", &n, &q);
		while(q-- != 0) {
			scanf("%d %d %d", &type, &s, &e);
			if(type == 0) {
				scanf("%d", &v);
				update(1, 1, n);
			} else {
				printf("%lld\n", get(1, 1, n));
			}
		}
	}

    return 0;
}

