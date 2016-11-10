#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        int c = 0, cc = 0;
        
        for(int i = 0, len = s.length(); i < len; i++)
            if(s[i] == '<') c++;
            else if(s[i] == '>' && c) {
                c--;
                cc++;
            }
        
        cout << cc << endl;
    }
 
    return 0;
}
