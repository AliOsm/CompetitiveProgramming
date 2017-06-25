#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF) {
		if(a < b)
			swap(a, b);

		if(a == b) printf("%d\n", a);
		else printf("%d\n", max(a, b));
	}
}

