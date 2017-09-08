#include <bits/stdc++.h>

using namespace std;

int n, k;
char a[8][9];
vector<int> idx;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%s", a[i]);

	for(int i = 0; i < k; ++i)
		idx.push_back(i);

	int res = 1e9;
	do {
		int mx = -1e9, mn = 1e9, cur;
		for(int i = 0; i < n; ++i) {
			cur = 0;
			for(int j = 0; j < k; ++j) {
				cur *= 10;
				cur += a[i][idx[j]] - '0';
			}
			mx = max(mx, cur);
			mn = min(mn, cur);
		}
		res = min(res, mx - mn);
	} while(next_permutation(idx.begin(), idx.end()));
	printf("%d\n", res);

	return 0;
}

