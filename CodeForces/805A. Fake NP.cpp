#include <stdio.h>

using namespace std;

int main() {
	int l, r;
	scanf("%d%d", &l, &r);

	if(l == r)
		printf("%d\n", r);
	else
		puts("2");

  return 0;
}

