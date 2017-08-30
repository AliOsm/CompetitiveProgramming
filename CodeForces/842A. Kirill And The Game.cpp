#include <stdio.h>

using namespace std;

// b = a / k

int main() {
	int l, r, x, y, k;
	scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);

	for(int i = l; i <= r; ++i) {
		if(i % k == 0) {
			int tmp = i / k;
			if(tmp >= x && tmp <= y) {
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");

	return 0;
}
