#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n, a[1000];
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; ++i)
		scanf("%d", a + i);
	sort(a, a + 2 * n);

	bool res = true;
	for(int i = n; i < 2 * n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i] <= a[j]) {
				res = false;
				break;
			}

	if(res)
		puts("YES");
	else
		puts("NO");

	return 0;
}

