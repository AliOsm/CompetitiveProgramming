#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	bool f = true;
	while(n != 0)
		if(f && n >= 2) {
			printf("aa");
			n -= 2;
			f = false;
		} else if(!f && n >= 2) {
			printf("bb");
			n -= 2;
			f = true;
		} else break;

	if(n == 1)
		if(f)
			printf("a");
		else
			printf("b");

	putchar('\n');

  return 0;
}

