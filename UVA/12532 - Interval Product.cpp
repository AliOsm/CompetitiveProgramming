#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

struct node {
	int pos, zer, neg;
	node() {
		pos = zer = neg = 0;
	}
	node(int pos, int zer, int neg) :
		pos(pos), zer(zer), neg(neg) {}
};

int const N = 1e5 + 1;
int n, m, a[N];
node seg[4 * N];

void build(int idx, int L, int R) {
	if(L == R) {
		seg[idx].pos = (a[L] > 0);
		seg[idx].zer = (a[L] == 0);
		seg[idx].neg = (a[L] < 0);
		return;
	}

	int mid = (L + R) / 2;
	build(idx * 2, L, mid);
	build((idx * 2) + 1, mid + 1, R);

	seg[idx].pos = seg[idx * 2].pos + seg[(idx * 2) + 1].pos;
	seg[idx].zer = seg[idx * 2].zer + seg[(idx * 2) + 1].zer;
	seg[idx].neg = seg[idx * 2].neg + seg[(idx * 2) + 1].neg;
}

int tar, val;
void update(int idx, int L, int R) {
	if(tar < L || tar > R)
		return;

	if(L == R) {
		a[tar] = val;
		seg[idx].pos = (a[L] > 0);
		seg[idx].zer = (a[L] == 0);
		seg[idx].neg = (a[L] < 0);
		return;
	}

	int mid = (L + R) / 2;
	update(idx * 2, L, mid);
	update((idx * 2) + 1, mid + 1, R);

	seg[idx].pos = seg[idx * 2].pos + seg[(idx * 2) + 1].pos;
	seg[idx].zer = seg[idx * 2].zer + seg[(idx * 2) + 1].zer;
	seg[idx].neg = seg[idx * 2].neg + seg[(idx * 2) + 1].neg;
}

int S, E;
node get(int idx, int L, int R) {
	if(E < L || S > R)
		return node(0, 0, 0);

	if(L >= S && R <= E)
		return seg[idx];

	int mid = (L + R) / 2;
	node ln = get(idx * 2, L, mid);
	node rn = get((idx * 2) + 1, mid + 1, R);

	return node(ln.pos + rn.pos, ln.zer + rn.zer, ln.neg + rn.neg);
}

int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		build(1, 1, n);

		char type;
		for(int i = 0; i < m; ++i) {
			scanf(" %c", &type);
			if(type == 'C') {
				scanf("%d %d", &tar, &val);
				update(1, 1, n);
			} else {
				scanf("%d %d", &S, &E);
				node nn = get(1, 1, n);
				if(nn.zer > 0) putchar('0');
				else if((nn.neg % 2) == 1) putchar('-');
				else putchar('+');
			}
		}
		puts("");
	}

	return 0;
}

