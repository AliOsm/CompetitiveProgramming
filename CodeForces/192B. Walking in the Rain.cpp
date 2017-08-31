#include <stdio.h>

using namespace std;

int const N = 1e3 + 1;
int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	int res = 0;
	while(true) {
		if(a[0] == 0 || a[n - 1] == 0) {
			printf("%d\n", res);
			return 0;
		}

		for(int j = 0; j < n;) {
			if(j == n - 1)
				break;

			if(j + 2 < n && a[j + 2] > 0)
				j += 2;
			else if(j + 1 < n && a[j + 1] > 0)
				++j;
			else {
				printf("%d\n", res);
				return 0;
			}
		}

		for(int j = 0; j < n; ++j)
			--a[j];

		++res;
	}

	printf("%d\n", res);

    return 0;
}
