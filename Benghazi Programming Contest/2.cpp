#include <bits/stdc++.h>

using namespace std;

int t, n, m, best;
int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
long long masks[64];

void rec(int i, int j, bool isWhite, int knights, long long orResult);

int cellToIndex(int i, int j) {
	return m * i + j;
}

bool isValid(double n, long long orResult) {
	return bitset<64>(orResult).count() >= n;
}

inline void recNext(int i, int j, bool isWhite, int knights, long long orResult) {
	if(j + 2 < m) {
		rec(i, j + 2, isWhite, knights, orResult);
	} else {
		if (isWhite) {
			if(i % 2 == 0) {
				rec(i + 1, 1, isWhite, knights, orResult);
			} else {
				rec(i + 1, 0, isWhite, knights, orResult);
			}
		} else {
			if(i % 2 == 0) {
				rec(i + 1, 0, isWhite, knights, orResult);
			} else {
				rec(i + 1, 1, isWhite, knights, orResult);
			}
		}
	}
}

void rec(int i, int j, bool isWhite, int knights, long long orResult) {
	if(isWhite) {
		if(isValid(n * m / 2.0, orResult)) {
			rec(0, 1, false, knights, orResult);
			return;
		}
	} else {
		if(isValid(n * m, orResult)) {
			best = min(best, knights);
			return;
		}
	}

	if(i >= n || j >= m) {
		return;
	}

	recNext(i, j, isWhite, knights + 1, orResult | masks[cellToIndex(i, j)]);
	recNext(i, j, isWhite, knights, orResult);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int currentCellIndex = cellToIndex(i, j);
				masks[currentCellIndex] |= (1LL << currentCellIndex);

				for(int k = 0; k < 8; ++k) {
					int ni = i + dx[k];
					int nj = j + dy[k];

					if(ni < 0 || ni >= n || nj < 0 || nj >= m) {
						continue;
					}

					masks[currentCellIndex] |= (1LL << (cellToIndex(ni, nj)));
				}
			}
		}

		best = 1e9;
		rec(0, 0, true, 0, 0LL);
		
		printf("%d\n", best);
	}

	return 0;
}
