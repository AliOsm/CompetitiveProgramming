#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, a[100001], mx = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		mx = max(mx, a[i]);
	}

	int res = 0;
	for(int i = 0; i < n; ++i)
		if(mx == a[i])
			++res;
	printf("%d\n", res);

	return 0;
}

