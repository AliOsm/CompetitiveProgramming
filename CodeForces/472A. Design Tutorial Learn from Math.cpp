#include <iostream>
#include <memory.h>

using namespace std;

int const N = 1e6 + 1;
bool prime[N];

void sieve() {
    for (int p = 2; p*p <= N; p++)
        if (prime[p] == false)
            for (int i = p * 2; i <= N; i += p)
                prime[i] = true;
}

int main() {
    prime[0] = true;
    prime[1] = true;
    sieve();
    
    int n;
    cin >> n;
    
    for(int i = n - 3; i > 2; i--)
        if(prime[n - i] && prime[i]) {
            cout << i << ' ' << n - i << endl;
            break;
        }
    
    return 0;
}
