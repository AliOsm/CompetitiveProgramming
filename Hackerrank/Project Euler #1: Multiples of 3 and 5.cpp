#include <stdio.h>

using namespace std;

int main() {
    int t, n;
    long long threes, fives, fifteens;
    
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%d", &n);
        --n;
        
        threes = n / 3;
        threes = (threes * (threes + 1) / 2) * 3;
        
        fives = n / 5;
        fives = (fives * (fives + 1) / 2) * 5;
        
        fifteens = n / 15;
        fifteens = (fifteens * (fifteens + 1) / 2) * 15;
        
        printf("%lld\n", threes + fives - fifteens);
    }
    
    return 0;
}

