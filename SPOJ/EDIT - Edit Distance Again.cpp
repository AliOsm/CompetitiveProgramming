#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void calc(int &cc, string s) {
    char a, b, c;
    
    for(int i = 1; i < s.size() - 1; i++) {
        a = s[i];
        b = s[i+1];
        c = s[i-1];
        
        if(!((a >= 'a' && a <= 'z') && (b == ' ' || (b >= 'A' && b <= 'Z')) && (c == ' ' || (c >= 'A' && c <= 'Z'))) || !((a >= 'A' && a <= 'Z') && (b == ' ' || (b >= 'a' && b <= 'z')) && (c == ' ' || (c >= 'a' && c <= 'z')))) {
            if((c >= 'a' && c <= 'z' && a >= 'a' && a <= 'z') || (c >= 'A' && c <= 'Z' && a >= 'A' && a <= 'Z')) {
                if(islower(s[i])) s[i] = toupper(s[i]);
                else s[i] = tolower(s[i]);
                a = s[i];
                cc++;
            }
            
            if((b >= 'a' && b <= 'z' && a >= 'a' && a <= 'z') || (b >= 'A' && b <= 'Z' && a >= 'A' && a <= 'Z')) {
                if(islower(s[i+1])) s[i+1] = toupper(s[i+1]);
                else s[i+1] = tolower(s[i+1]);
                b = s[i];
                cc++;
            }
        }
    }
}

int main() {
    string s;
    int cc1, cc2;
    
    while(cin >> s) {
        if(s.size() == 1)
            cout << 0 << endl;
        else if(s.size() == 2) {
            char a, b;
            
            a = s[0];
            b = s[1];
            
            if((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') || (a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z'))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else {
            cc1 = 0;
            cc2 = 1;
            
            calc(cc1, s);
            
            if(islower(s[0])) s[0] = toupper(s[0]);
            else s[0] = tolower(s[0]);
            
            calc(cc2, s);
            
            cout << min(cc1, cc2) << endl;
        }
    }
    
    return 0;
}
