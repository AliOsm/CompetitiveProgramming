#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	
	while(scanf("%d %d %d", &a, &b, &c) && (a != 0 || b != 0 || c != 0)) {
		if(c - b == b - a)
			printf("AP %d\n", c + (c - b));
		else
			printf("GP %d\n", c * (c / b));
	}

	return 0;
}

