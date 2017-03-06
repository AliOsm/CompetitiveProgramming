#include <iostream>
#include <memory.h>

using namespace std;

int const N = 3001;
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
    
    int n, c = 0, cc = 0;
    cin >> n;
    
    for(int i = 1; i <= n; i++, cc = 0) {
        for(int j = 1; j <= i; j++)
            if(!prime[j] && i % j == 0) cc++;
        
        if(cc == 2) c++;
    }
    
    cout << c << endl;
    
    return 0;
}
