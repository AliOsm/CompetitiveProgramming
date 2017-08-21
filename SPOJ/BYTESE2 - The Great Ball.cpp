#include <stdio.h>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

int const N = 1000;
int n, seg[4 * N], lazy[4 * N];
pair<int, int> a[N];
set<int> st;

int s, e;

void pro(int idx, int l, int r) {
	seg[idx] += lazy[idx];
	if(l != r)
		lazy[idx << 1] += lazy[idx],
		lazy[(idx << 1) + 1] += lazy[idx];
	lazy[idx] = 0;
}

int update(int idx, int l, int r) {
	if(lazy[idx] != 0)
		pro(idx, l, r);

	if(s > r || e < l)
		return 0;

	if(l >= s && r <= e) {
		++lazy[idx];
		pro(idx, l, r);
		return seg[idx];
	}

	int m = (l + r) >> 1;
	update(idx << 1, l, m);
	update((idx << 1) + 1, m + 1, r);
	return seg[idx] = max(seg[idx << 1], seg[(idx << 1) + 1]);
}

int main() {
	int t, res;
	scanf("%d", &t);
	while(t-- != 0) {
		st.clear();
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		scanf("%d", &n);

		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i].first, &a[i].second);
			st.insert(a[i].first);
			st.insert(a[i].second);
		}

		int cnt = 1;
		for(set<int>::iterator it = st.begin(); it != st.end(); ++it, ++cnt)
			for(int i = 0; i < n; ++i) {
				if(a[i].first == (*it))
					a[i].first = cnt;
				if(a[i].second == (*it))
					a[i].second = cnt;
			}

		res = 0;
		for(int i = 0; i < n; ++i) {
			s = a[i].first, e = a[i].second;
			res = max(res, update(1, 1, N));
		}

		printf("%d\n", res);
	}

    return 0;
}

