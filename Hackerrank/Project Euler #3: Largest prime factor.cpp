#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> factors;

void factorization(long long n) {
    factors.clear();
    
    for (long long i = 2, c; i * i <= n; i += 1 + (i & 1)) {
        c = 0;
        while (n % i == 0)
            n /= i, ++c;
        if(c)
            factors.push_back(i);
    }
    
    if (n != 1)
        factors.push_back(n);
}

int main() {
    int t;
    long long n;
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%lld", &n);
        factorization(n);
        printf("%lld\n", factors.back());
    }
    
    return 0;
}

