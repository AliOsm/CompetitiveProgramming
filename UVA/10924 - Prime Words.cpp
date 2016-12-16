#include <iostream>
#include <memory.h>
#include <string>
#include <cstdlib>

using namespace std;

int const N = 1e4;
bool prime[N];

void sieve() {
    for (int p = 2; p * p <= N; p++)
        if (prime[p] == false)
            for (int i = p * 2; i <= N; i += p)
                prime[i] = true;
}

int main() {
    prime[0] = true;
    prime[1] = false;
    sieve();
    
    string s;
    int c = 0;
    
    while(cin >> s) {
        c = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(isupper(s[i])) c += (s[i] - 'A') + 26 + 1;
            else c += (s[i] - 'a') + 1;
        }
        
        if(!prime[c]) cout << "It is a prime word." << endl;
        else cout << "It is not a prime word." << endl;
    }
    
    return 0;
}
