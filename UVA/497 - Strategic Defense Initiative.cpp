#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int cases, n, a[N], t[N], d[N], p[N], sol[N];
string s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d\n\n", &cases);

	while(cases-- != 0) {
		memset(p, -1, sizeof p);
		memset(d, 0, sizeof d);

		for(int i = 0; getline(cin, s) && s != ""; ++i) {
			a[i] = stoi(s);
			n = i;
		}
		++n;

		int l = 1;
		t[0] = a[0];

		for(int i = 1; i < n; ++i) {
			int idx = upper_bound(t, t + l, a[i]) - t;

			if((idx > 0 && a[i] > t[idx - 1]) || idx == 0) {
				t[idx] = a[i];
				d[idx] = i;
				p[i] = d[idx - 1];

				if(idx == l) {
					++l;
				}
			}
		}

		printf("Max hits: %d\n", l);

		int cur = d[l - 1];
		int idx = l - 1;
		do {
			sol[idx--] = a[cur];
			cur = p[cur];
		} while(cur != -1);

		for(int i = 0; i < l; ++i) {
			printf("%d\n", sol[i]);
		}

		if(cases) {
			puts("");
		}
	}

	return 0;
}
