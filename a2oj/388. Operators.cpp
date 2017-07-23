#include <stdio.h>

using namespace std;

int n, s;

bool rec(int i, int sum) {
	if(sum == s && i == n + 1)
		return true;

	if(i > n)
		return false;

	return rec(i + 1, sum + i) || rec(i + 1, sum - i);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t-- != 0) {
		scanf("%d %d", &n, &s);
		if(rec(1, 0))
			puts("Possible");
		else
			puts("Impossible");
	}

	return 0;
}

