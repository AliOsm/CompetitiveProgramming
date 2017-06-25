#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int a[3001];
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);

	int res = -1;
	for(int i = 1; i < n; ++i)
		if(a[i] != a[i - 1] + 1) {
			res = a[i - 1] + 1;
			break;
		}

	if(a[0] > 1)
		res = 1;

	if(res == -1)
		res = a[n - 1] + 1;

	printf("%d\n", res);

	return 0;
}

