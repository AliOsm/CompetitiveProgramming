#include <bits/stdc++.h>

using namespace std;

int t, abc[3], d, e;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif

	scanf("%d", &t);

	while(t-- != 0) {
		for(int i = 0; i < 3; ++i) {
			scanf("%d", abc + i);
		}

		scanf("%d %d", &d, &e);

		sort(abc, abc + 3);

		bool can = false;

		do {
			if(abc[0] + abc[1] <= d && abc[2] <= e) {
				can = true;
				break;
			}
		} while(next_permutation(abc, abc + 3));

		if(can) {
			puts("YES");
		} else {
			puts("NO");
		}
	}

	return 0;
}
