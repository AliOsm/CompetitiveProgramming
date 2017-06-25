#include <stdio.h>

using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while(t-- != 0) {
    	scanf("%d", &n);
    	unsigned long long r1 = 1ULL * n * (n + 1) * (2 * n + 1) / 6;
    	unsigned long long r2 = 1ULL * (n * (n + 1) / 2) * (n * (n + 1) / 2);
    	unsigned long long res;

    	if(r1 > r2) res = r1 - r2;
    	else res = r2 - r1;
    	printf("%llu\n", res);
    }

    return 0;
}

