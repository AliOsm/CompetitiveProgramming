#include <stdio.h>

using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);

	int r1 = s * v1 + 2 * t1;
	int r2 = s * v2 + 2 * t2;

	if(r1 == r2)
		puts("Friendship");
	if(r1 > r2)
		puts("Second");
	if(r1 < r2)
		puts("First");

	return 0;
}
