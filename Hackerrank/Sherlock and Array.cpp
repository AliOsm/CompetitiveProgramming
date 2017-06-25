#include <stdio.h>

using namespace std;

long long a[100001], cm[100001];

int main() {
	int t, n;
	bool ok;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
			scanf("%d", a + i);

		cm[0] = a[0];
		for(int i = 1; i <= n; ++i)
			cm[i] = cm[i - 1] + a[i];

		ok = false;
		for(int i = 0; i < n; ++i) {
			if(i == 0 && 0 == cm[n - 1] - a[0]) {
				puts("YES");
				ok = true;
			} else if(i == n - 1 && cm[n - 1] - a[n - 1] == 0) {
				puts("YES");
				ok = true;
			} else if(cm[i - 1] == cm[n - 1] - cm[i]) {
				puts("YES");
				ok = true;
			}

			if(ok)
				break;
		}

		if(ok)
			continue;

		puts("NO");
	}

    return 0;
}

