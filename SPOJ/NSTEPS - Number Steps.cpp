#include <stdio.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	int x, y;
	while(t-- != 0) {
		scanf("%d %d", &x, &y);

		if(x == y || x == y + 2)
			if(x % 2 == 0) printf("%d\n", x + y);
			else printf("%d\n", x + y - 1);
		else
			puts("No Number");
	}

    return 0;
}

