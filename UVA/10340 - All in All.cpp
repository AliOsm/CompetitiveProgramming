#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    int c;
    
    while(cin >> s >> t) {
        c = 0;
        
        for(int i = 0; i < t.length(); i++) {
            if(s[c] == t[i]) c++;
            if(c == s.length()) break;
        }
        
        if(c == s.length()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
