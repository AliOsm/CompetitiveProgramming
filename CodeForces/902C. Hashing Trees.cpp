#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int a[N];

int main() {
	int n;
	scanf("%d", &n);
	++n;
	for(int i = 0; i < n; ++i)
		scanf("%d", a + i);

	bool ok = true;

	for(int i = 1; i < n; ++i)
		if(a[i] > 1 && a[i - 1] > 1) {
			ok = false;
			break;
		}

	if(ok) {
		puts("perfect");
		return 0;
	}

	puts("ambiguous");

	int cnt;

	cnt = 1;
	printf("0");
	for(int i = 1; i < n; cnt += a[i], ++i)
		for(int j = 0; j < a[i]; ++j)
			printf(" %d", cnt);
	puts("");

	cnt = 1;
	printf("0");
	for(int i = 1; i < n; ++i) {
		if(a[i - 1] > 1) {
			for(int j = 0; j < a[i] / 2; ++j)
				printf(" %d", cnt - 1);
			for(int j = a[i] / 2; j < a[i]; ++j)
				printf(" %d", cnt);
		} else {
			for(int j = 0; j < a[i]; ++j)
				printf(" %d", cnt);
		}
		cnt += a[i];
	}
	puts("");

	return 0;
}
