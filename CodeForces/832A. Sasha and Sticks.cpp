#include <stdio.h>

using namespace std;

int main() {
	long long n, k;
	scanf("%lld %lld", &n, &k);

	long long rem = n % k;
	n -= rem;
	long long d = n / k;

	if(d % 2 == 0)
		puts("NO");
	else
		puts("YES");

	return 0;
}
