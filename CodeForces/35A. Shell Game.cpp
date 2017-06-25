#include <stdio.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	int a1, b1;
	scanf("%d%d", &a1, &b1);

	int a2, b2;
	scanf("%d%d", &a2, &b2);

	int a3, b3;
	scanf("%d%d", &a3, &b3);

	if(a1 == n)
		n = b1;
	else if(b1 == n)
		n = a1;

	if(a2 == n)
		n = b2;
	else if(b2 == n)
		n = a2;

	if(a3 == n)
		n = b3;
	else if(b3 == n)
		n = a3;

	printf("%d\n", n);

	return 0;
}
