/*
	Idea:
		- Keep track what is the elements in the left and right for each
			other element using array.
*/

#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int n, m, link[N][2];

enum { L, R };

int main() {
	int kase = 1;
	while(scanf("%d %d", &n, &m) != EOF) {
		printf("Case %d: ", kase++);

		memset(link, -1, sizeof link);
		for(int i = 1; i <= n; ++i) {
			if(i == 1)
				link[i][R] = 2;
			else if(i == n)
				link[i][L] = n - 1;
			else
				link[i][L] = i - 1, link[i][R] = i + 1;
		}

		bool inv = false;
		int type, x, y;
		while(m-- != 0) {
			scanf("%d", &type);

			if(type == 4) {
				inv = !inv;
				continue;
			}

			scanf("%d %d", &x, &y);

			if(n == 1)
				continue;

			if(type == 3) {
				if(link[x][L] != -1 && link[x][L] != y)
					link[link[x][L]][R] = y;
				if(link[x][R] != -1 && link[x][R] != y)
					link[link[x][R]][L] = y;
				
				if(link[y][L] != -1 && link[y][L] != x)
					link[link[y][L]][R] = x;
				if(link[y][R] != -1 && link[y][R] != x)
					link[link[y][R]][L] = x;

				if(link[x][R] == y) {
					link[x][R] = link[y][R];
					link[y][L] = link[x][L];
					link[x][L] = y;
					link[y][R] = x;

					continue;
				}

				if(link[x][L] == y) {
					link[x][L] = link[y][L];
					link[y][R] = link[x][R];
					link[x][R] = y;
					link[y][L] = x;

					continue;
				}

				swap(link[x], link[y]);
				continue;
			}

			if(inv)
				type = 3 - type;

			if(type == 2) {
				if(link[y][R] == x)
					continue;

				if(link[y][L] == x) {
					if(link[x][L] != -1 && link[x][L] != y)
						link[link[x][L]][R] = y;
					if(link[x][R] != -1 && link[x][R] != y)
						link[link[x][R]][L] = y;
					
					if(link[y][L] != -1 && link[y][L] != x)
						link[link[y][L]][R] = x;
					if(link[y][R] != -1 && link[y][R] != x)
						link[link[y][R]][L] = x;

					link[x][R] = link[y][R];
					link[y][L] = link[x][L];
					link[x][L] = y;
					link[y][R] = x;

					continue;
				}
				
				if(link[y][R] != -1)
					link[link[y][R]][L] = x;

				if(link[x][R] != -1 && link[x][L] != -1)
					link[link[x][R]][L] = link[x][L],
					link[link[x][L]][R] = link[x][R];
				else if(link[x][R] != -1)
					link[link[x][R]][L] = -1;
				else if(link[x][L] != -1)
					link[link[x][L]][R] = -1;

				link[x][R] = link[y][R];
				link[x][L] = y;
				link[y][R] = x;
			}

			if(type == 1) {
				if(link[y][L] == x)
					continue;

				if(link[y][R] == x) {
					if(link[x][L] != -1 && link[x][L] != y)
						link[link[x][L]][R] = y;
					if(link[x][R] != -1 && link[x][R] != y)
						link[link[x][R]][L] = y;
					
					if(link[y][L] != -1 && link[y][L] != x)
						link[link[y][L]][R] = x;
					if(link[y][R] != -1 && link[y][R] != x)
						link[link[y][R]][L] = x;

					link[x][L] = link[y][L];
					link[y][R] = link[x][R];
					link[x][R] = y;
					link[y][L] = x;

					continue;
				}

				if(link[y][L] != -1)
					link[link[y][L]][R] = x;

				if(link[x][L] != -1 && link[x][R] != -1)
					link[link[x][L]][R] = link[x][R],
					link[link[x][R]][L] = link[x][L];
				else if(link[x][L] != -1)
					link[link[x][L]][R] = -1;
				else if(link[x][R] != -1)
					link[link[x][R]][L] = -1;

				link[x][L] = link[y][L];
				link[x][R] = y;
				link[y][L] = x;

				continue;
			}
		}

		if(n == 1) {
			puts("1");
			continue;
		}

		int idx1 = -1, idx2 = -1;
		for(int i = 1; i <= n; ++i)
			if(link[i][L] == -1) {
				idx1 = i;
				break;
			}

		long long res = 0;
		if(n & 1)
			for(int i = idx1; i > 0; i = link[link[i][R]][R])
				res += i;
		else {
			if(!inv)
				for(int i = idx1; i > 0; i = link[link[i][R]][R])
					res += i;
			else
				for(int i = link[idx1][R]; i > 0; i = link[link[i][R]][R])
					res += i;
		}

		printf("%lld\n", res);
	}

	return 0;
}
