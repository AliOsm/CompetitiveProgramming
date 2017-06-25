#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 2e5 + 1;
int a[N];
bool f[N];

int main() {
	int n, tmp = 0, res = 0;
	scanf("%d", &n);

	for(int i = 0; i < n * 2; ++i)
		scanf("%d", a + i);

	for(int i = 0; i < n * 2; ++i) {
		if(!f[a[i]]) {
			f[a[i]] = true;
			++tmp;
		} else
			--tmp;

		res = max(res, tmp);
	}

	printf("%d\n", res);

	return 0;
}

