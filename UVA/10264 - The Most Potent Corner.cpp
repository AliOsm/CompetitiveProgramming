/*
	Idea:
		- For each corner, get the sum of its neighbors.
		- Then for each corner consider it as a part of the solution
			and add the maximum neighbor point to its sum.
		- Finally maximize the result.
		- To get the neighbors you need to search for the points with
			same dimensions except 1 dimension differ by 1, for example points
			(1, 0, 1) and (1, 0, 0) are neighbors.
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[(1 << 16)], sum[(1 << 16)];

int main() {
	while(scanf("%d", &n) != EOF) {
		int p = (1 << n);
		for(int i = 0; i < p; ++i)
			scanf("%d", a + i);

		for(int i = 0, cur; i < p; ++i) {
			sum[i] = 0, cur = i;
			for(int j = 0; j < n; ++j) {
				cur ^= (1 << j);
				sum[i] += a[cur];
				cur ^= (1 << j);
			}
		}

		int res = 0;
		for(int i = 0, cur, tmp; i < p; ++i) {
			cur = i, tmp = 0;
			for(int j = 0; j < n; ++j) {
				cur ^= (1 << j);
				tmp = max(tmp, sum[cur]);
				cur ^= (1 << j);
			}
			tmp += sum[i];
			res = max(res, tmp);
		}

		printf("%d\n", res);
	}

	return 0;
}
