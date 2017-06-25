#include <stdio.h>

using namespace std;

long long lcm[41];

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    lcm[1] = 1;
    for(int i = 2; i < 41; ++i)
    	lcm[i] = i * lcm[i - 1] / gcd(i, lcm[i - 1]);

    int t, n;
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%d", &n);
        printf("%lld\n", lcm[n]);
    }

    return 0;
}

