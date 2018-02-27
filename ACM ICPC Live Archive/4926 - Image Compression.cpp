#include <bits/stdc++.h>

using namespace std;

int const N = 65;
int w, t;
char g[N][N];

void rec(int x, int y, int w) {
	int ones, zeros;
	ones = zeros = 0;

	for(int i = x; i < x + w; ++i)
		for(int j = y; j < y + w; ++j)
			ones += (g[i][j] == '1'), zeros += (g[i][j] == '0');

	int onesp = ones * 100;
	int zerosp = zeros * 100;

	if(onesp >= t * (w * w)) {
		for(int i = x; i < x + w; ++i)
			for(int j = y; j < y + w; ++j)
				g[i][j] = '1';
	} else if(zerosp >= t * (w * w)) {
		for(int i = x; i < x + w; ++i)
			for(int j = y; j < y + w; ++j)
				g[i][j] = '0';
	} else {
		rec(x + w / 2, y + w / 2, w / 2);
		rec(x + w / 2, y, w / 2);
		rec(x, y + w / 2, w / 2);
		rec(x, y, w / 2);
	}
}

int main() {
	int kase = 1;
	while(scanf("%d", &w) && w != 0) {
		printf("Image %d:\n", kase++);
		scanf("%d", &t);

		for(int i = 0; i < w; ++i)
			scanf("%s", g[i]);

		rec(0, 0, w);

		for(int i = 0; i < w; ++i)
			printf("%s\n", g[i]);
	}
	
	return 0;
}
