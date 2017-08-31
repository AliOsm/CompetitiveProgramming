#include <stdio.h>

using namespace std;

int main() {
	int p1, p2, p3, p4, a, b, res = 0;
	scanf("%d %d %d %d %d %d", &p1, &p2, &p3, &p4, &a, &b);
	for(int i = a; i <= b; ++i)
		if(i == (((i % p1) % p2) % p3) % p4)
			++res;
	printf("%d\n", res);

    return 0;
}
