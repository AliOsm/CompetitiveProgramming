#include <stdio.h>

using namespace std;

int n;
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
char pops[11][11], played[11][11];

int main() {
	int t;
	scanf("%d", &t);

	bool blankline = false;
	while(t-- != 0) {
		if(blankline) puts("");

		scanf("%d", &n);

		for(int i = 0; i < n; ++i)
			scanf("%s", pops[i]);

		for(int i = 0; i < n; ++i)
			scanf("%s", played[i]);

		int px = -1, py = -1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(played[i][j] == 'x') {
					if(pops[i][j] == '*')
						px = i, py = j;
					int cnt = 0;
					for(int k = 0; k < 8; ++k) {
						int ni = i + dx[k], nj = j + dy[k];
						if(ni >= 0 && ni < n && nj >= 0 && nj < n && pops[ni][nj] == '*')
							++cnt;
					}
					played[i][j] = char(cnt + '0');
				}

		if(px == -1 && py == -1)
			for(int i = 0; i < n; ++i)
				printf("%s\n", played[i]);
		else {
			for(int i = 0; i < n; ++i, puts(""))
				for(int j = 0; j < n; ++j)
					if((i == px && j == py) || pops[i][j] == '*')
						putchar('*');
					else
						printf("%c", played[i][j]);
		}

		blankline = true;
	}
}

