/*
	Idea:
		- Backtracking.
*/

#include <bits/stdc++.h>

using namespace std;

char q, g[5][5];

bool go(int i, int j, int di, int dj, char eq) {
	if(i >= 4 || i < 0 || j >= 4 || j < 0)
		return true;
	if(g[i][j] != eq)
		return false;
	return go(i + di, j + dj, di, dj, eq);
}

int check() {
	bool o = false, x = false;
	
	for(int i = 0; i < 4; ++i)
		if(go(i, 0, 0, 1, 'o') || go(0, i, 1, 0, 'o')) {
			o = true;
			break;
		}
	o |= go(0, 0, 1, 1, 'o');
	o |= go(0, 3, 1, -1, 'o');

	for(int i = 0; i < 4; ++i)
		if(go(i, 0, 0, 1, 'x') || go(0, i, 1, 0, 'x')) {
			x = true;
			break;
		}
	x |= go(0, 0, 1, 1, 'x');
	x |= go(0, 3, 1, -1, 'x');

	if(o)
		return 0;
	if(x)
		return 1;
	return 2;
}

bool rec(int cur, int cnt) {
	if(cnt == 0)
		return check() == 1;

	bool ret = true;

	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) 
			if(g[i][j] == '.') {
				if(cur == 0)
					g[i][j] = 'o';
				else
					g[i][j] = 'x';

				int win = check();

				if(win == 2)
					win = rec(!cur, cnt - 1);

				if(!cur && win != 1)
					ret = false;
				
				g[i][j] = '.';
				
				if(!cur && win == 0)
					return false;
				
				if(cur && win == 1)
					return true;
			}

	if(!cur)
		return ret;
	return false;
}

int main() {
	while(scanf(" %c", &q) && q != '$') {
		bool ok = true;
		int cnt = 0;

		for(int i = 0; i < 4; ++i) {
			scanf("%s", g[i]);
			for(int j = 0; j < 4; ++j)
				cnt += g[i][j] == '.';
		}
		--cnt;

		for(int i = 0; ok && i < 4; ++i)
			for(int j = 0; ok && j < 4; ++j)
				if(g[i][j] == '.') {
					g[i][j] = 'x';

					if(check() == 1 || rec(0, cnt)) {
						ok = false;
						printf("(%d,%d)\n", i, j);
					}

					g[i][j] = '.';
				}
		
		if(ok)
			puts("#####");
	}

	return 0;
}
