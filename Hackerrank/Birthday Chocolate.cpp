#include <stdio.h>

using namespace std;

int n, a[101], m, d, cm[101], res;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);
	scanf("%d %d", &d, &m);

	cm[0] = 0;
	for(int i = 1; i <= n; ++i)
		cm[i] = cm[i - 1] + a[i - 1];

	res = 0;
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= n; ++j)
			if(j - i + 1 == m && cm[j] - cm[i - 1] == d)
				++res;

	printf("%d\n", res);

    return 0;
}

