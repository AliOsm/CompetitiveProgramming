#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 6;
int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		++a[tmp];
	}
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		++b[tmp];
	}

	int res = 0;
	for(int i = 1; i <= 5; ++i) {
		if((a[i] + b[i]) % 2 != 0) {
			puts("-1");
			return 0;
		}

		int tmp = (a[i] + b[i]) >> 1;
		tmp = max(a[i], b[i]) - tmp;
		res += tmp;
	}

	printf("%d\n", res / 2);

    return 0;
}
