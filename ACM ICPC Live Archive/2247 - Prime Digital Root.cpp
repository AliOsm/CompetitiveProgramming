#include <iostream>
#include <iomanip>

using namespace std;

int const N = 1e6 + 1;
bool prime[N];

void sieve() {
    for (int p = 2; p*p <= N; p++)
        if (prime[p] == false)
            for (int i = p * 2; i <= N; i += p)
                prime[i] = true;
}

int addDigits(int n) {
    int tmp = 0;
    
    while(n > 0) {
        tmp += n % 10;
        n /= 10;
    }
    
    return tmp;
}

int main() {
    prime[0] = true;
    prime[1] = true;
    sieve();
    
    int n, tmp;
    
    while(cin >> n && n) {
        cout << setw(7) << n << ' ' << setw(7);

        if(!prime[n]) {
            cout << n << endl;
            continue;
        }
        
        tmp = n;
        while(tmp > 10 && prime[tmp]) tmp = addDigits(tmp);
            
        if(!prime[tmp]) cout << tmp << endl;
        else cout << "none" << endl;
    }
    
    return 0;
}