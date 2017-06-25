#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	/*
	 h > 1 > 2 > h
	 h > 1 > h > 2 > h
	 h > 1 > 2 > 1 > h
	 h > 2 > 1 > 2 > h
	 */

	printf("%d\n", min(min(min(a + c + b, a + a + b + b), a + c + c + a), b + c + c + b));

	return 0;
}

