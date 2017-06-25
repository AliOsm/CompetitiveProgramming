#include <stdio.h>

using namespace std;

int main() {
	int v, a;
	while(scanf("%d %d", &v, &a) != EOF)
		printf("%d\n", v * a * 2);

    return 0;
}

