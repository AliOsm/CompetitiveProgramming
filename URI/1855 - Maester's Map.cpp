#include <stdio.h>

using namespace std;

int n, m;
char g[101][101];

void DFS(int i, int j, int xdir, int ydir) {
	if(i < 0 || i >= n || j < 0 || j >= m)
		return;

	if(g[i][j] == '*') {
		puts("*");
		exit(0);
	}

	if(g[i][j] == '.') {
		DFS(i + xdir, j + ydir, xdir, ydir);
		return;
	}

	switch(g[i][j]) {
	case '>': xdir = 0, ydir = 1; break;
	case '<': xdir = 0, ydir = -1; break;
	case '^': xdir = -1, ydir = 0; break;
	case 'v': xdir = 1, ydir = 0; break;
	}

	g[i][j] = '.';
	DFS(i + xdir, j + ydir, xdir, ydir);
}

int main() {
	scanf("%d\n%d", &m, &n);
	for(int i = 0; i < n; ++i)
		scanf("%s", g[i]);

	int xdir, ydir;
	switch(g[0][0]) {
	case '>': xdir = 0, ydir = 1; break;
	case '<': xdir = 0, ydir = -1; break;
	case '^': xdir = -1, ydir = 0; break;
	case 'v': xdir = 1, ydir = 0; break;
	}
	DFS(0, 0, xdir, ydir);

	puts("!");

	return 0;
}

