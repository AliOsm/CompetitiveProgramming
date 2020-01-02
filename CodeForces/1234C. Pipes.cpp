#include <bits/stdc++.h>

using namespace std;

int const N = 4e5 + 10;
char tmp;
int q, n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		scanf("%d", &n);
		for(int j = 0; j < n; ++j) {
			scanf(" %c", &tmp);
			a[j] = tmp - '0';
		}
		for(int j = 0; j < n; ++j) {
			scanf(" %c", &tmp);
			a[n + j] = tmp - '0';
		}

		if(a[0] <= 2)
			a[0] = 2;
		else
			a[0] = 4;

		int row = 0, col = 1, frow = 0, fcol = 0, trow, tcol;
		if(a[0] == 4)
			row = 1, col = 0;
		if(col == n) {
			puts("NO");
			continue;
		}
		bool ok = true;
		while(true) {
			if(col != fcol) {
				if(a[col + row * n] <= 2)
					a[col + row * n] = 2;
				else
					if(frow == 0)
						a[col + row * n] = 4;
					else
						a[col + row * n] = 5;
			}
			if(row != frow) {
				if(a[col + row * n] <= 2)
					a[col + row * n] = 1;
				else
					if(frow == 0)
						a[col + row * n] = 6;
					else
						a[col + row * n] = 3;
			}

			trow = row, tcol = col;

			if(frow == 0 && a[tcol + trow * n] == 1)
				++row;
			else if(frow == 1 && a[tcol + trow * n] == 1)
				--row;
			if(a[tcol + trow * n] == 4)
				++row;
			if(a[tcol + trow * n] == 2 || a[tcol + trow * n] == 3 || a[tcol + trow * n] == 6)
				++col;
			if(a[tcol + trow * n] == 5)
				--row;

			frow = trow, fcol = tcol;

			if(row < 0 || row > 1) {
				ok = false;
				break;
			}

			if(col >= n)
				break;
		}

		if(ok && col == n && row == 1)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}