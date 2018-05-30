/*
  Idea:
    - The idea is that the anding operation occurs in some way, so you
      do not need to make the all operations independently, for example:
      if we have the following array: 2 2 3 4 2, and k = 2
      after the first step:  2 2 0 0 0
      (2 & 2 & 2) (2 & 2 & 3) (2 & 3 & 4) (3 & 4 & 2) (4 & 2 & 2)
      after the second step: 0 0 0 0 0
      (0 & 2 & 2) (2 & 2 & 0) (2 & 0 & 0) (0 & 0 & 0) (0 & 0 & 2)
      You can see that the value of index 2 (which is contains 2 also)
      at the end of operations is 0, and it is equivalint to:
      (2 & 2 & 2 & 3 & 4)
      So for each index i the value of it will be:
      a[i] = a[i-k] & a[i-k+1] & ... & a[i] & ... & a[i+k-1] & a[i+k]
    - This can be obtained using Segment Tree.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e4 + 1;
int t, n, k, a[N * 3], ori[N], seg[N * 3 * 4];

void build(int at, int l, int r) {
	if(l == r) {
		seg[at] = a[l];
		return;
	}

	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
	seg[at] = seg[at * 2] & seg[at * 2 + 1];
}

int s, e;
int get(int at, int l, int r) {
	if(l > e || r < s)
		return (1ll << 31) - 1;

	if(l >= s && r <= e)
		return seg[at];

	int m = (l + r) / 2;
	return get(at * 2, l, m) & get(at * 2 + 1, m + 1, r);
}

int main() {
  scanf("%d", &t);
  while(t-- != 0) {
  	scanf("%d %d", &n, &k);
  	for(int i = 1; i <= n; ++i)
  		scanf("%d", a + i), a[i + n + n] = a[i + n] = a[i];

  	build(1, 1, n * 3);

  	for(int i = n + 1; i <= n + n; ++i) {
  		s = max(1, i - k), e = min(n * 3, i + k);
  		ori[i - n] = get(1, 1, n * 3);
  	}

  	for(int i = 1; i <= n; ++i)
  		printf("%s%d", i == 1 ? "" : " ", ori[i]);
  	puts("");
  }

  return 0;
}
