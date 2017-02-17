#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    string s;
    int ans, opens;
    while(t--) {
        cin >> s;
        
        ans = opens = 0;
        
        for(int i = 0; i < s.length(); i++)
            if(s[i] == '<')
                opens++;
            else {
                opens--;
                
                if(opens == 0) ans = i + 1;
                if(opens < 0) break;
            }
        
        cout << ans << endl;
    }
    
    return 0;
}
