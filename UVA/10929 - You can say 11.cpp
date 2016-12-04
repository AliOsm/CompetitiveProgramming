#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int t;
    
    while(cin >> s && s != "0") {
        t = 0;
        for(int i = s.length() - 1; i >= 0; i--)
            if(i % 2 == 0) t += (s[i] - '0');
            else t -= (s[i] - '0');
        
        if(t % 11 == 0) cout << s << " is a multiple of 11." << endl;
        else cout << s << " is not a multiple of 11." << endl;
    }
    
    return 0;
}
