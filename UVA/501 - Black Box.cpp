/*
  Idea:
    - First we need to compress the numbers in the array `A`.
    - Then using segment tree we can track the frequency of each number.
    - For each query from the array `u` we can iterate over the new numbers
      and add 1 to the frequency of them in the segment tree.
    - To get the query answer we can take `k` with us and search in the
      segment tree for an element before it there is less than or equal
      number of frequences as `k`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 3e4 + 1;
int t, n, m, k, lst, tar, cnt, s, e, a[N], seg[N * 4];
vector<int> all;

void update(int at, int l, int r) {
	if(tar < l || tar > r)
		return;

	if(l == r) {
		++seg[at];
		return;
	}

	int m = (l + r) / 2;
	update(at * 2, l, m);
	update(at * 2 + 1, m + 1, r);
	seg[at] = seg[at * 2] + seg[at * 2 + 1];
}

int get(int at, int l, int r, int rem) {
	if(l == r)
		return l;

	int m = (l + r) / 2;
	if(seg[at * 2] >= rem)
		return get(at * 2, l, m, rem);
	return get(at * 2 + 1, m + 1, r, rem - seg[at * 2]);
}

int main() {
  bool bl = false;
  scanf("%d", &t);
  while(t-- != 0) {
  	if(bl)
  		puts("");

  	lst = cnt = 1;
  	memset(seg, 0, sizeof seg);
  	all.clear();

  	scanf("%d %d", &n, &m);
  	for(int i = 1; i <= n; ++i)
  		scanf("%d", a + i), all.push_back(a[i]);

  	sort(all.begin(), all.end());
  	all.resize(unique(all.begin(), all.end()) - all.begin());
  	for(int i = 1; i <= n; ++i)
  		a[i] = (lower_bound(all.begin(), all.end(), a[i]) - all.begin()) + 1;

  	while(m-- != 0) {
  		scanf("%d", &k);
  		for(int i = lst; i <= k; ++i) {
  			tar = a[i];
  			update(1, 1, n);
  		}
  		lst = k + 1;
  		printf("%d\n", all[get(1, 1, n, cnt) - 1]);
  		++cnt;
  	}

  	bl = true;
  }

  return 0;
}
