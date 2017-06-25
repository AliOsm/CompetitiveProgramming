#include <stdio.h>

using namespace std;

int times[100005];

int main() {
	int n, t = 0;
	scanf("%d", &n);
	for(int i = 0, tmp; i < n; ++i) {
		scanf("%d", &tmp);
		t += tmp;
	}

	int m;
	scanf("%d", &m);
	for(int i = 0, l, r; i < m; ++i) {
		scanf("%d%d", &l, &r);
		times[l] = 1;
		times[r] = 2;
	}

	for(int i = t; i < 100005; ++i)
		if(times[i] == 1) {
			printf("%d\n", i);
			return 0;
		} else if(times[i] == 2) {
			printf("%d\n", t);
			return 0;
		}

	puts("-1");

	return 0;
}

