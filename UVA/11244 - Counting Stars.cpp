#include <stdio.h>

using namespace std;

int r, c, ni, nj, res;
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
char g[101][101];
bool ok;

int main() {
	while(scanf("%d %d", &r, &c) && r != 0 && c != 0) {
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j)
				scanf(" %c", &g[i][j]);

		res = 0;
		for(int i = 0; i < r; ++i)
			for(int j = 0; j < c; ++j) {
				if(g[i][j] == '*') {
					ok = true;
					for(int k = 0; k < 8; ++k) {
						ni = i + dx[k];
						nj = j + dy[k];
						if(ni >= 0 && ni < r && nj >= 0 && nj < c && g[ni][nj] == '*') {
							ok = false;
							break;
						}
					}
					if(ok)
						++res;
				}
			}

		printf("%d\n", res);
	}

    return 0;
}

