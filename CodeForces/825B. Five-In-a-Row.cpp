#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

char g[11][11];

bool check() {
	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j) {
			int cnt = 0;
			while(j < 10 && g[i][j] == 'X')
				++cnt, ++j;
			if(cnt >= 5)
				return true;
		}

	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j) {
			int cnt = 0;
			while(j < 10 && g[j][i] == 'X')
				++cnt, ++j;
			if(cnt >= 5)
				return true;
		}

	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j) {
			if(g[i][j] == 'X') {
				int cnt = 0;
				for(int k = i, l = j; k < 10 && l < 10 && g[k][l] == 'X'; ++k, ++l, ++cnt);
				if(cnt >= 5)
					return true;
				cnt = 0;
				for(int k = i, l = j; k >= 0 && l >= 0 && g[k][l] == 'X'; ++k, --l, ++cnt);
				if(cnt >= 5)
					return true;
			}
		}

	return false;
}

int main() {
	for(int i = 0; i < 10; ++i)
		scanf("%s", g[i]);

	for(int i = 0; i < 10; ++i)
		for(int j = 0; j < 10; ++j)
			if(g[i][j] == '.') {
				g[i][j] = 'X';
				if(check()) {
					puts("YES");
					return 0;
				}
				g[i][j] = '.';
			}

	puts("NO");

	return 0;
}
