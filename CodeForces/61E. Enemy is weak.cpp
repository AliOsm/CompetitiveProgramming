#include <stdio.h>
#include <map>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;
int n, a[N], tmpa[N], seg[4 * N], mx[N], mn[N];
map<int, int> mp;

int tar;
void update(int idx, int l, int r) {
	if(tar < l || tar > r)
		return;

	if(l == r) {
		seg[idx] = 1;
		return;
	}

	int mid = (l + r) >> 1;
	update(idx << 1, l, mid);
	update((idx << 1) + 1, mid + 1, r);
	seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
}

int s, e;
int get(int idx, int l, int r) {
	if(e < l || s > r)
		return 0;

	if(l >= s && r <= e)
		return seg[idx];

	int mid = (l + r) >> 1;
	return get(idx << 1, l, mid) + get((idx << 1) + 1, mid + 1, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		tmpa[i] = a[i];
	}
	sort(tmpa + 1, tmpa + n + 1);
	for(int i = 1, cnt = 1; i <= n; ++i)
		if(!mp.count(tmpa[i]))
			mp[tmpa[i]] = cnt++;
	for(int i = 1; i <= n; ++i)
		a[i] = mp[a[i]];

	memset(seg, 0, sizeof seg);
	tar = a[1];
	update(1, 1, n);
	for(int i = 2; i < n; ++i) {
		s = a[i] + 1, e = 1e6;
		mx[i] = get(1, 1, n);
		tar = a[i];
		update(1, 1, n);
	}

	memset(seg, 0, sizeof seg);
	tar = a[n];
	update(1, 1, n);
	for(int i = n - 1; i > 1; --i) {
		s = 1, e = a[i] - 1;
		mn[i] = get(1, 1, n);
		tar = a[i];
		update(1, 1, n);
	}

	long long res = 0;
	for(int i = 1; i <= n; ++i)
		res += (1LL * mx[i] * mn[i]);

	printf("%lld\n", res);

	return 0;
}

