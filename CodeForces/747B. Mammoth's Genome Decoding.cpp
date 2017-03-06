#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n, a = 0, g = 0, c = 0, t = 0;
    cin >> n;
    string s;
    cin >> s;
    
    if(n % 4 != 0) {
        cout << "===" << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A')
            a++;
        else if(s[i] == 'G')
            g++;
        else if(s[i] == 'C')
            c++;
        else if(s[i] == 'T')
            t++;
    }
    
    n /= 4;
    
    if(a <= n && g <= n && c <= n && t <= n) {
        a = abs(a - n);
        g = abs(g - n);
        c = abs(c - n);
        t = abs(t - n);
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '?') {
                if(a) {
                    cout << 'A';
                    a--;
                } else if(g) {
                    cout << 'G';
                    g--;
                } else if(c) {
                    cout << 'C';
                    c--;
                } else if(t) {
                    cout << 'T';
                    t--;
                }
            } else
                cout << s[i];
        }
        
        cout << endl;
    } else
        cout << "===" << endl;
    
    return 0;
}
