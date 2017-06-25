#include <stdio.h>

using namespace std;

int a, b, res;

int main() {
	scanf("%d %d", &a, &b);

	res = 0;
	while(a > 0 && b > 0) {
		if(a < b) {
			b -= 2;
			++a;
		} else {
			a -= 2;
			++b;
		}
		++res;

		if(a < 0 || b < 0)
			--res;
	}

	printf("%d\n", res);
}
