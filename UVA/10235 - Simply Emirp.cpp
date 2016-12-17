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

int reverseNumber(int n) {
    int tmp = 0;
    
    while(n > 0) {
        tmp *= 10;
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

    while(cin >> n) {
        tmp = reverseNumber(n);
        if(!prime[n] && !prime[tmp] && n != tmp)
            cout << n << " is emirp." << endl;
        else if(!prime[n])
            cout << n << " is prime." << endl;
        else
            cout << n << " is not prime." << endl;
    }
    
    return 0;
}
