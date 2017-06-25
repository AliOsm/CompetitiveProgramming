#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, a, res, rem[101];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a);
		++rem[a % k];
	}

	res += rem[0] != 0;
	for(int i = 1, j = k - 1; i < j; ++i, --j)
		res += max(rem[i], rem[j]);
	res += k % 2 == 0 && rem[k / 2] != 0;

	printf("%d\n", res);
}

