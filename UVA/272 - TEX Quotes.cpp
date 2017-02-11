#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    bool f = true;
    
    while(getline(cin, s)) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '"' && f) {
                cout << "``";
                f = false;
            } else if(s[i] == '"' && !f) {
                cout << "\'\'";
                f = true;
            } else
                cout << s[i];
        }
        
        cout << endl;
    }
    
    return 0;
}
