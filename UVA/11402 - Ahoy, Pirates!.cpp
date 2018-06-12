/*
	Idea:
		- Using Segment tree we can track how many ones in each range.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e6 + 1;
int t, n, q, s, e, v, cur, len, lst, seg[4 * N], lazy[4 * N];
bool a[N];
char type, ss[N];

void build(int at, int l, int r) {
	if(l == r) {
		seg[at] = a[l];
		return;
	}

	int m = (l + r) >> 1;
	build(at << 1, l, m);
	build(at << 1 | 1, m + 1, r);
	seg[at] = seg[at << 1] + seg[at << 1 | 1];
}

void pro(int at, int l, int r) {
	if(lazy[at] == 1)
		seg[at] = r - l + 1;
	else if(lazy[at] == 0)
		seg[at] = 0;
	else if(lazy[at] == 2)
		seg[at] = (r - l + 1) - seg[at];

	if(l != r) {
		if(lazy[at] == 1) {
			lazy[at << 1] = lazy[at];
			lazy[at << 1 | 1] = lazy[at];
		} else if(lazy[at] == 0) {
			lazy[at << 1] = lazy[at];
			lazy[at << 1 | 1] = lazy[at];
		} else if(lazy[at] == 2) {
			if(lazy[at << 1] == 2)
				lazy[at << 1] = -1;
			else if(lazy[at << 1] == 1)
				lazy[at << 1] = 0;
			else if(lazy[at << 1] == 0)
				lazy[at << 1] = 1;
			else
				lazy[at << 1] = 2;

			if(lazy[at << 1 | 1] == 2)
				lazy[at << 1 | 1] = -1;
			else if(lazy[at << 1 | 1] == 1)
				lazy[at << 1 | 1] = 0;
			else if(lazy[at << 1 | 1] == 0)
				lazy[at << 1 | 1] = 1;
			else
				lazy[at << 1 | 1] = 2;
		}
	}

	lazy[at] = -1;
}

void update(int at, int l, int r) {
	if(lazy[at] != -1)
		pro(at, l, r);

	if(l > e || r < s)
		return;

	if(l >= s && r <= e) {
		lazy[at] = v;
		pro(at, l, r);
		return;
	}

	int m = (l + r) >> 1;
	update(at << 1, l, m);
	update(at << 1 | 1, m + 1, r);
	seg[at] = seg[at << 1] + seg[at << 1 | 1];
}

int get(int at, int l, int r) {
	if(lazy[at] != -1)
		pro(at, l, r);

	if(l > e || r < s)
		return 0;

	if(l >= s && r <= e)
		return seg[at];

	int m = (l + r) >> 1;
	return get(at << 1, l, m) + get(at << 1 | 1, m + 1, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	int kase = 1;
	scanf("%d", &t);
	while(t-- != 0) {
		printf("Case %d:\n", kase++);

		scanf("%d", &n);
		lst = 0;
		while(n-- != 0) {
			scanf("%d", &cur);
			scanf("%s", ss);
			len = strlen(ss);
			for(int i = 0; i < cur; ++i)
				for(int j = 0; j < len; ++j)
					a[++lst] = (ss[j] == '1');
		}
		
		memset(seg, 0, sizeof seg);
		memset(lazy, -1, sizeof lazy);
		build(1, 1, lst);

		scanf("%d", &q);
		for(int i = 1; q-- != 0;) {
			scanf(" %c %d %d", &type, &s, &e);
			++s, ++e;

			if(type == 'F') {
				v = 1;
				update(1, 1, lst);
			} else if(type == 'E') {
				v = 0;
				update(1, 1, lst);
			} else if(type == 'I') {
				v = 2;
				update(1, 1, lst);
			} else {
				printf("Q%d: %d\n", i++, get(1, 1, lst));
			}
		}
	}

	return 0;
}
