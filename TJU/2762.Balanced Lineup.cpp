#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int const N = 1e5 + 1;
int a[N];
pair<int, int> seg[4 * N];

void build(int idx, int L, int R) {
	if(L == R) {
		seg[idx].first = seg[idx].second = a[L];
		return;
	}

	int mid = (L + R) / 2;
	build(idx * 2, L, mid);
	build(idx * 2 + 1, mid + 1, R);

	seg[idx].first = min(seg[idx * 2].first, seg[idx * 2 + 1].first);
	seg[idx].second = max(seg[idx * 2].second, seg[idx * 2 + 1].second);
}

int start, end;
pair<int, int> get(int idx, int L, int R) {
	if(end < L || start > R)
		return make_pair(1e9 + 1, -1e9 - 1);

	if(L >= start && R <= end)
		return seg[idx];

	int mid = (L + R) / 2;
	pair<int, int> left = get(idx * 2, L, mid);
	pair<int, int> right = get(idx * 2 + 1, mid + 1, R);
	return make_pair(min(left.first, right.first), max(left.second, right.second));
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	build(1, 1, n);

	while(q-- != 0) {
		scanf("%d %d", &start, &end);
		pair<int, int> mnmx = get(1, 1, n);
		printf("%d\n", mnmx.second - mnmx.first);
	}

	return 0;
}

