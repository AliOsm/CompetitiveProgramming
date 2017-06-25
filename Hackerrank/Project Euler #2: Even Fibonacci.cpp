#include <stdio.h>

using namespace std;

unsigned long long fib[191];

int main() {
    fib[0] = 1, fib[1] = 2;
    for(int i = 2; i < 191; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    
    int t;
    unsigned long long n, res;
    scanf("%d", &t);
    while(t-- != 0) {
        res = 0;
        scanf("%llu", &n);
        for(int i = 0; fib[i] <= n; ++i)
            res += fib[i] % 2 == 0 ? fib[i] : 0;
        printf("%llu\n", res);
    }
    
    return 0;
}

