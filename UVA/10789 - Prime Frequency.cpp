#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int const N = 2001;
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
    
    int t, ascii[128], indx = 0;
    cin >> t;
    
    string s, res;
    
    while(t--) {
        cin >> s;
        res = "";
        memset(ascii, 0, sizeof ascii);
        
        for(int i = 0; i < s.size(); i++)
            ascii[int(s[i])]++;
        
        for(int i = 0; i < 128; i++)
            if(!prime[ascii[i]])
                res += char(i);
        
        cout << "Case " << ++indx << ": " ;
        if(res == "") cout << "empty" << endl;
        else cout << res << endl;
    }
    
    return 0;
}
