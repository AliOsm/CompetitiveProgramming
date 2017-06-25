#include <stdio.h>
#include <algorithm>

using namespace std;

int g[20][20];

int go(int ci, int cj, int pi, int pj) {
	int res = 1;
	for(int i = 0; i < 4; ++i)
		res *= g[ci][cj], ci += pi, cj += pj;
	return res;
}

int main() {
	for(int i = 0; i < 20; ++i)
		for(int j = 0; j < 20; ++j)
			scanf("%d", &g[i][j]);

	int res = 0;
	for(int i = 0; i < 20; ++i)
		for(int j = 0; j < 20; ++j) {
			if(i > 2) res = max(res, go(i, j, -1, 0));
			if(i < 17) res = max(res, go(i, j, 1, 0));
			if(j > 2) res = max(res, go(i, j, 0, -1));
			if(j < 17) res = max(res, go(i, j, 0, 1));
			if(i > 2 && j > 2) res = max(res, go(i, j, -1, -1));
			if(i > 2 && j < 17) res = max(res, go(i, j, -1, 1));
			if(i < 17 && j > 2) res = max(res, go(i, j, 1, -1));
			if(i < 17 && j < 17) res = max(res, go(i, j, 1, 1));
		}
	printf("%d\n", res);

    return 0;
}

