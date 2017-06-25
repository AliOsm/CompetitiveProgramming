#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 3e5 + 1;
int n, a[N], r_minus_l;
pair<int, int> sparse[N][19];
vector<int> starts, starts_tmp;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int calc_log(int len) {
	int log = 0;
	while((1 << log) <= len)
		++log;
	return --log;
}

int min_query(int l, int r) {
	int log = calc_log(r - l + 1);
	return min(a[sparse[l][log].first], a[sparse[r + 1 - (1 << log)][log].first]);
}

int gcd_query(int l, int r) {
	int log = calc_log(r - l + 1);
	return gcd(sparse[l][log].second, sparse[r + 1 - (1 << log)][log].second);
}

void can(int mid) {
	starts_tmp.clear();
	for(int i = 0; i <= n - mid; ++i)
		if(min_query(i, i + mid - 1) == gcd_query(i, i + mid - 1))
			starts_tmp.push_back(i + 1);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n; ++i) {
		sparse[i][0].first = i;
		sparse[i][0].second = a[i];
	}

	for(int j = 1; (1 << j) <= n; ++j)
		for(int i = 0; i + (1 << j) - 1 < n; ++i) {
			if(a[sparse[i][j - 1].first] < a[sparse[i + (1 << (j - 1))][j - 1].first])
				sparse[i][j].first = sparse[i][j - 1].first;
			else
				sparse[i][j].first = sparse[i + (1 << (j - 1))][j - 1].first;

			sparse[i][j].second = gcd(sparse[i][j - 1].second, sparse[i + (1 << (j - 1))][j - 1].second);
		}

	int l = 1, r = n, mid;
	while(l <= r) {
		mid = (l + r) / 2;
		can(mid);
		if(!starts_tmp.empty()) {
			l = mid + 1;
			r_minus_l = mid;
			starts.swap(starts_tmp);
		} else
			r = mid - 1;
	}

	printf("%d %d\n", (int)starts.size(), r_minus_l - 1);
	for(int i = 0; i < (int)starts.size(); ++i)
		printf("%d ", starts[i]);
	puts("");

    return 0;
}

