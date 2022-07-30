/*
  Idea:
    - Using meet in the middle technique we can generate all paths
      start at point `(0, 0)` and end in the middle of the grid with
      its result.
    - Then we can construct all paths start from point `(n-1, m-1)`
      and end in the middle of the grid and check how many numbers
      the XOR of them with the current result equal to `k`.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 21;
int n, m, half;
long long k, g[N][N], sol;
map<long long, int> solutions[N][N];

void firstHalf(int i, int j, long long val, int cnt) {
	val ^= g[i][j];

	if (cnt == half) {
		++solutions[i][j][val];
		return;
	}

	if(i + 1 < n) {
		firstHalf(i + 1, j, val, cnt + 1);
	}

	if(j + 1 < m) {
		firstHalf(i, j + 1, val, cnt + 1);
	}
}

void secondHalf(int i, int j, long long val, int cnt) {
	if(cnt == (m + n - 2) - half) {
		if(solutions[i][j].count(val ^ k)) {
			sol += solutions[i][j][val ^ k];
		}

		return;
	}

	val ^= g[i][j];

	if(i > 0) {
		secondHalf(i - 1, j, val, cnt + 1);
	}

	if(j > 0) {
		secondHalf(i, j - 1, val, cnt + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d %d %lld", &n, &m, &k);

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%lld", &g[i][j]);
		}
	}

	half = (n + m - 2) / 2;

	firstHalf(0, 0, 0, 0);
	secondHalf(n - 1, m - 1, 0, 0);

	printf("%lld\n", sol);

	return 0;
}
