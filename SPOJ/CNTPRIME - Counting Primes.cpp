/*
	Idea:
		- Segment tree with lazy propagation.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1, MAX = 1e6 + 1;
int t, n, q, a[N], seg[4 * N], lazy[4 * N];
bitset<MAX> prime;

void sieve() {
	prime.set();
	prime[0] = prime[1] = 0;
	for(int i = 2; i * i < MAX; ++i)
		if(prime[i])
			for(int j = i * i; j < MAX; j += i)
				prime[j] = 0;
}

void build(int idx, int l, int r) {
	if(l == r) {
		seg[idx] = prime[a[l]];
		return;
	}

	int mid = (l + r) / 2;
	build(idx * 2, l, mid);
	build(idx * 2 + 1, mid + 1, r);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int s, e, val;

void pro(int idx, int l, int r) {
	seg[idx] = prime[lazy[idx]] * (r - l + 1);
	if(l != r)
		lazy[idx * 2] = lazy[idx * 2 + 1] = lazy[idx];
	lazy[idx] = 0;
}

void update(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(s > r || e < l)
		return;

	if(r <= e && l >= s) {
		lazy[idx] = val;
		pro(idx, l, r);
		return;
	}

	int mid = (l + r) / 2;
	update(idx * 2, l, mid);
	update(idx * 2 + 1, mid + 1, r);
	seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}

int get(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(s > r || e < l)
		return 0;

	if(r <= e && l >= s)
		return seg[idx];

	int mid = (l + r) / 2;
	return get(idx * 2, l, mid) + get(idx * 2 + 1, mid + 1, r);
}

int main() {
  sieve();

  int kase = 1;
  scanf("%d", &t);
  while(t-- != 0) {
  	printf("Case %d:\n", kase++);
  	scanf("%d %d", &n, &q);
  	memset(a, 0, sizeof a);
  	for(int i = 1; i <= n; ++i)
  		scanf("%d", a + i);

  	memset(seg, 0, sizeof seg);
  	memset(lazy, 0, sizeof lazy);
  	build(1, 1, n);

  	while(q-- != 0) {
  		int type;
  		scanf("%d %d %d", &type, &s, &e);

  		if(type == 0) {
  			scanf("%d", &val);
  			update(1, 1, n);
  		} else {
  			printf("%d\n", get(1, 1, n));
  		}
  	}
  }

  return 0;
}
