/*
	Idea:
		- Using Segment tree, for each segment we need to maintain the following
			four values:
			SUM - the sum of the value in the range.
			RES - the best result of the range.
			PRE - the best result of the prefix range.
			SUF - the best result of the suffix range.
*/

#include <bits/stdc++.h>

using namespace std;

struct node {
	int sum, res, pre, suf;
	node() {}
	node(int val) {
		sum = res = pre = suf = val;
	}
};

int const N = 5e4 + 1;
int n, m, a[N], s, e;
node seg[N * 4];

node merge(node left, node right) {
	node ret;
	ret.sum = left.sum + right.sum;
	ret.pre = max(left.pre, left.sum + right.pre);
	ret.suf = max(right.suf, right.sum + left.suf);
	ret.res = max(left.res, max(right.res, left.suf + right.pre));
	return ret;
}

void build(int at, int l, int r) {
	if(l == r) {
		seg[at] = node(a[l]);
		return;
	}

	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
	seg[at] = merge(seg[at * 2], seg[at * 2 + 1]);
}

node get(int at, int l, int r) {
	if(l > e || r < s)
		return node(-1000000);
 
	if(l >= s && r <= e)
		return seg[at];
 
	int m = (l + r) / 2;
	return merge(get(at * 2, l, m), get(at * 2 + 1, m + 1, r));
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
  	scanf("%d", a + i);

  build(1, 1, n);

  scanf("%d", &m);
  while(m-- != 0) {
  	scanf("%d %d", &s, &e);
  	printf("%lld\n", get(1, 1, n).res);
  }

  return 0;
}
