#include <bits/stdc++.h>

using namespace std;

int g[9][9];
bool R[10][10], C[10][10], U[3][3][10];

void update(int i, int j, int val, int f) {
	R[i][val] = f;
	C[j][val] = f;
	U[i / 3][j / 3][val] = f;
}

bool rec(int i, int j) {
	if(j == 9)
		return rec(i + 1, 0);

	if(i == 9) {
		for(int k = 0; k < 9; ++k, puts(""))
			for(int l = 0; l < 9; ++l)
				printf("%s%d", l != 0 ? " " : "", g[k][l]);
		return true;
	}

	if(g[i][j] != 0)
		return rec(i, j + 1);

	for(int k = 1; k < 10; ++k) {
		if(!R[i][k] && !C[j][k] && !U[i / 3][j / 3][k]) {
			update(i, j, k, true);
			g[i][j] = k;
			if(rec(i, j + 1))
				return true;
			update(i, j, k, false);
		}
	}
	g[i][j] = 0;

	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		memset(R, false, sizeof R);
		memset(C, false, sizeof C);
		memset(U, false, sizeof U);

		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j) {
				scanf("%d", &g[i][j]);
				if(g[i][j] != 0)
					update(i, j, g[i][j], true);
			}

		if(!rec(0, 0))
			puts("No solution");
	}

	return 0;
}

