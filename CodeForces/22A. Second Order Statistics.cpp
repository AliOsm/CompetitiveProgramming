#include <stdio.h>
#include <algorithm>

using namespace std;

int const N = 101;
int n, a[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	sort(a, a + n);

	int mn = a[0], i = 0;
	while(a[i] == mn && i < n)
		++i;

	if(i == n && a[i - 1] == mn)
		puts("NO");
	else
		printf("%d\n", a[i]);

    return 0;
}
