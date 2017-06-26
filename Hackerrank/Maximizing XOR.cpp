#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int l, r;
	scanf("%d%d", &l, &r);

	int res = 0;
	for(int i = l; i <= r; ++i)
		for(int j = l; j <= r; ++j)
			res = max(res, i ^ j);
	printf("%d\n", res);

	return 0;
}

