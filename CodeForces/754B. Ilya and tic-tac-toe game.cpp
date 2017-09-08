#include <bits/stdc++.h>

using namespace std;

char g[6][7];

bool can() {
	for(int i = 1; i < 5; ++i)
		for(int j = 1; j < 5; ++j) {
			if(g[i][j] == 'x') {
				if(g[i - 1][j] == 'x' && g[i + 1][j] == 'x')
					return true;
				if(g[i][j - 1] == 'x' && g[i][j + 1] == 'x')
					return true;
				if(g[i - 1][j - 1] == 'x' && g[i + 1][j + 1] == 'x')
					return true;
				if(g[i - 1][j + 1] == 'x' && g[i + 1][j - 1] == 'x')
					return true;
			}
		}
	return false;
}

int main() {
	for(int i = 1; i < 5; ++i)
		scanf("%s", g[i] + 1);

	for(int i = 1; i < 5; ++i)
		for(int j = 1; j < 5; ++j) {
			if(g[i][j] == '.') {
				g[i][j] = 'x';
				if(can()) {
					puts("YES");
					return 0;
				}
				g[i][j] = '.';
			}
		}

	puts("NO");

	return 0;
}

