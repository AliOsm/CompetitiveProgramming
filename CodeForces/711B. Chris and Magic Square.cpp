#include <bits/stdc++.h>

using namespace std;

int n;
long long g[501][501], rows[501], cols[501], md, sd, x, y;

int main() {
	cin >> n;

	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> g[i][j];

			if(g[i][j] == 0)
				x = i, y = j;

			rows[i] += g[i][j];
			cols[j] += g[i][j];
			if(i == j)
				md += g[i][j];
			if(i + j + 1 == n)
				sd += g[i][j];
		}
	}

	long long sum = 0;
	for(int i = 0; i < n; ++i)
		if(x != i) {
			sum = rows[i];
			break;
		}

	if(x != y && md != sum) {
		cout << -1 << endl;
		return 0;
	}

	if(x + y + 1 != n && sd != sum) {
		cout << -1 << endl;
		return 0;
	}

	for(int i = 0; i < n; ++i) {
		if(i != x && rows[i] != sum) {
			cout << -1 << endl;
			return 0;
		}

		if(i != y && cols[i] != sum) {
			cout << -1 << endl;
			return 0;
		}
	}

	g[x][y] = sum - rows[x];

	if(g[x][y] <= 0 || cols[y] + g[x][y] != sum) {
		cout << -1 << endl;
		return 0;
	}

	if(x == y && md + g[x][y] != sum) {
		cout << -1 << endl;
		return 0;	
	} 

	if(x + y + 1 == n && sd + g[x][y] != sum) {
		cout << -1 << endl;
		return 0;
	} 

	cout << g[x][y] << endl;

	return 0;
}
