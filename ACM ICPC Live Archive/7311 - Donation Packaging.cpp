#include <stdio.h>
#include <algorithm>

typedef long long ll;

using namespace std;

int a, b, c;

int main() {
	int t;
	scanf("%d", &t);

	a = b = c = 0;
	for(int i = 0, ta, tb, tc; i < t; ++i) {
		scanf("%d%d%d", &ta, &tb, &tc);

		a += ta;
		b += tb;
		c += tc;

		if(a >= 30 && b >= 30 && c >= 30) {
			int res = min(a, min(b, c));

			a -= res;
			b -= res;
			c -= res;

			printf("%d\n", res);
		} else {
			puts("NO");
		}
	}

	return 0;
}

