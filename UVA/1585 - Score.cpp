#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int t, c, cc;
    cin >> t;
    
    while(t-- && cin >> s) {
        c = cc = 0;
        
        for(int i = 0; i < s.length(); i++, cc = 0)
            if(s[i] == 'O') {
                while(i < s.length() && s[i++] != 'X' && (cc = cc + 1))
                    c += cc;
                i--;
            }
        
        cout << c << endl;
    }
    
    return 0;
}
