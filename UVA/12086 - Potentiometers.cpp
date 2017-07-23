#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 2e5 + 1;
int n, a[N], seg[4 * N];

void build(int idx, int L, int R) {
	if(L == R) {
		seg[idx] = a[L];
		return;
	}

	int mid = (L + R) >> 1;
	build(idx << 1, L, mid);
	build((idx << 1) + 1, mid + 1, R);
	seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

int tar, val;
void update(int idx, int L, int R) {
	if(tar < L || tar > R)
		return;

	if(L == R) {
		seg[idx] = a[L] = val;
		return;
	}

	int mid = (L + R) >> 1;
	update(idx << 1, L, mid);
	update((idx << 1) + 1, mid + 1, R);
	seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

int S, E;
int get(int idx, int L, int R) {
	if(E < L || S > R)
		return 0;

	if(L >= S && R <= E)
		return seg[idx];

	int mid = (L + R) >> 1;
	return get(idx << 1, L, mid) + get((idx << 1) + 1, mid + 1, R);
}

int main() {
	bool blankline = false;
	for(int kase = 1; scanf("%d", &n) && n != 0; ++kase) {
		if(blankline)
			puts("");

		printf("Case %d:\n", kase);

		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		build(1, 1, n);

		char type[4];
		while(scanf("%s", type) && type[0] != 'E') {
			if(type[0] == 'S') {
				scanf("%d %d", &tar, &val);
				update(1, 1, n);
			} else {
				scanf("%d %d", &S, &E);
				printf("%d\n", get(1, 1, n));
			}
		}

		blankline = true;
	}

	return 0;
}

