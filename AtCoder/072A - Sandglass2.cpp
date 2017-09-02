#include <stdio.h>
 
using namespace std;

int main() {
	int x, t;
	scanf("%d %d", &x, &t);
 
	if(t <= x)
		printf("%d\n", x - t);
	else
		puts("0");
 
    return 0;
}
