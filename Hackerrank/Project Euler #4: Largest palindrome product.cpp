#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

vector<int> palindromes;

int reverse(int n) {
    int m = 0;
    while(n != 0) {
        m *= 10;
        m += n % 10;
        n /= 10;
    }
    return m;
}

bool divisors(int n) {
    int sqrtn = sqrt(n);
    for(int i = 1; i <= sqrtn; ++i)
        if(n % i == 0 && i > 100 && i < 1000 && n / i > 100 && n / i < 1000)
            return true;
    return false;
}

void check(int n) {
    if(n == reverse(n) && divisors(n))
        palindromes.push_back(n);
}

int main() {
    for(int i = 101101; i < 1000000; ++i)
        check(i);

    int t, n;
    scanf("%d", &t);
    while(t-- != 0) {
        scanf("%d", &n);
        printf("%d\n", palindromes[lower_bound(palindromes.begin(), palindromes.end(), n) - palindromes.begin() - 1]);
    }

    return 0;
}

