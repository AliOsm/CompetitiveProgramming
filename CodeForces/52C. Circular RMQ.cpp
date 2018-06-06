/*
	Idea:
		- Using Segment tree with Lazy propagation to handle the update queries
			and print queries in log time.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, m, s, e, t1, t2;
long long a[N], seg[N * 4], lazy[N * 4], v, res;
string q;

void build(int at, int l, int r) {
	if(l == r) {
		seg[at] = a[l];
		return;
	}

	int mid = (l + r) >> 1;
	build(at << 1, l, mid);
	build(at << 1 | 1, mid + 1, r);
	seg[at] = min(seg[at << 1], seg[at << 1 | 1]);
}

void pro(int at, int l, int r) {
	seg[at] += lazy[at];
	if(l != r) {
		lazy[at << 1] += lazy[at];
		lazy[at << 1 | 1] += lazy[at];
	}
	lazy[at] = 0;
}

void update(int at, int l, int r) {
	if(lazy[at] != 0)
		pro(at, l, r);

	if(l > e || r < s)
		return;

	if(l >= s && r <= e) {
		lazy[at] += v;
		pro(at, l, r);
		return;
	}

	int mid = (l + r) >> 1;
	update(at << 1, l, mid);
	update(at << 1 | 1, mid + 1, r);
	seg[at] = min(seg[at << 1], seg[at << 1 | 1]);
}

long long get(int at, int l, int r) {
	if(lazy[at] != 0)
		pro(at, l, r);

	if(l > e || r < s)
		return 1e18;

	if(l >= s && r <= e)
		return seg[at];

	int mid = (l + r) >> 1;
	return min(get(at << 1, l, mid), get(at << 1 | 1, mid + 1, r));
}

int count_spaces() {
	int ret = 0;
	for(int i = 0; i < q.length(); ++i)
		if(q[i] == ' ')
			++ret;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in", "r", stdin);
#endif

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i)
  	scanf("%lld", a + i);

  build(1, 1, n);

  scanf("%d", &m);
  cin.ignore();
  while(m-- != 0) {
  	getline(cin, q);
  	stringstream ss(q);
  	if(count_spaces() == 1) {
  		ss >> t1 >> t2;

  		if(t1 > t2) {
  			s = t1 + 1, e = n;
  			res = get(1, 1, n);
  			s = 1, e = t2 + 1;
  			res = min(res, get(1, 1, n));
  			printf("%lld\n", res);
  		} else {
  			s = t1 + 1, e = t2 + 1;
  			printf("%lld\n", get(1, 1, n));
  		}
  	} else {
  		ss >> t1 >> t2 >> v;

  		if(t1 > t2) {
  			s = t1 + 1, e = n;
  			update(1, 1, n);
  			s = 1, e = t2 + 1;
  			update(1, 1, n);
  		} else {
  			s = t1 + 1, e = t2 + 1;
  			update(1, 1, n);
  		}
  	}
  }

  return 0;
}
