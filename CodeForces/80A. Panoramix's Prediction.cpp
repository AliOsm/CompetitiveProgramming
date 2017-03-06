#include <iostream>

using namespace std;

bool prime[51];

void sieve() {
    for(int i = 0; i < 51; i++) prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 0; i < 51; i++)
        if(prime[i])
            for(int j = i + i; j < 51; j += i)
                prime[j] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    sieve();
    
    for(int i = n + 1; i < m; i++)
        if(prime[i]) {
            cout << "NO" << endl;
            return 0;
        }
    
    if(prime[m]) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
