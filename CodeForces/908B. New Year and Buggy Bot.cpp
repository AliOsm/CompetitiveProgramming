#include <bits/stdc++.h>

using namespace std;

int const N = 1e2 + 1;
int n, m;
char g[N][N];
string s, nw;
vector<int> idx;
int sx, sy, dx, dy;

bool check() {
	nw = s;

	for(int i = 0; i < nw.size(); ++i)
		if(nw[i] - '0' == idx[0])
			nw[i] = 'D';
		else if(nw[i] - '0' == idx[1])
			nw[i] = 'L';
		else if(nw[i] - '0' == idx[2])
			nw[i] = 'U';
		else
			nw[i] = 'R';

	int cx = sx, cy = sy;
	for(int i = 0; i < nw.size(); ++i) {
		if(cx < 0 || cx >= n || cy < 0 || cy >= m || g[cx][cy] == '#')
			return false;

		if(cx == dx && cy == dy)
			return true;

		if(nw[i] == 'D')
			++cx;
		if(nw[i] == 'L')
			--cy;
		if(nw[i] == 'U')
			--cx;
		if(nw[i] == 'R')
			++cy;
	}

	return cx == dx && cy == dy;
}

int main() {
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 'S')
				sx = i, sy = j;
			if(g[i][j] == 'E')
				dx = i, dy = j;
		}

	cin >> s;

	for(int i = 0; i < 4; ++i)
		idx.push_back(i);

	int res = 0;
	do {
		res += check();
	} while(next_permutation(idx.begin(), idx.end()));

	printf("%d\n", res);

	return 0;
}

